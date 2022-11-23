//============================================================================
// Name        : installer.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Install C/C++ packages via CBS CLI
//============================================================================

#ifndef CBS_INCLUDE_INSTALLER_H
#define CBS_INCLUDE_INSTALLER_H

#include "cli_config.h"
#include "base64_encode.h"

/**
 * The {PKG_TYPES} ENUM represents
 * different types of data that can be
 * installed via CBS CLI
 *
 * {PKG_INCLUDE_FILES} 	represents any header files 	(.h, .hpp, etc)
 * {PKG_LIBRARY_FILES} 	represents any implementations 	(.c, .cpp)
 * {PKG_EXECUTABLES} 	represents any binary files 	(.dll, .lib, .dylib)
 */
enum class PKG_TYPES {
	PKG_DEFAULT,
	PKG_INCLUDE_FILES,
	PKG_LIBRARY_FILES,
	PKG_EXECUTABLES
};
/**
 * The {installer} class allows
 * for installation of packages from the
 * CBS CLI Site. Specifying the package content
 * and package type allows CBS CLI to determine its
 * installation path.
 */
class installer final {
private:
	/**
	 * {__pkg_type} represents an object
	 * of {PKG_TYPES} ENUM class. Used to select
	 * the type of content that is being installed.
	 */
	PKG_TYPES __pkg_type;
	/**
	 * {__pkg_name} is very self-explanatory. Holds
	 * the name of the package being installed.
	 */
	const char* __pkg_name;
	/**
	 * Using {__pkg_type} this will specify the final
	 * installation path for the downloading process.
	 */
	const char* __path;
	/**
	 * The URL of the package location that will
	 * be used for installing contents.
	 */
	const char* __url;
private:
	/**
	 * Any caches or temporary files, even memory
	 * allocated will be freed/removed once the
	 * installation is completed.
	 */
	void __clean() LIB_LAVALAMP_CLI_DONT_THROW(true);
public:
	/**
	 * Select the {PKG_TYPE} to be installed.
	 * Defaulted to PKG_DEFAULT which will be
	 * the root include path on your system.
	 */
	installer(const PKG_TYPES& = PKG_TYPES::PKG_DEFAULT);
	~installer();
public:
	/**
	 * Explicitly set the package type. First param
	 * takes the package url and the second param takes
	 * the type of package it is.
	 */
	void set_pkg(const char*, const PKG_TYPES&) const LIB_LAVALAMP_CLI_DONT_THROW(true);
	/**
	 * Installs the contents set by {installer#set_pkg}
	 */
	void install_contents() LIB_LAVALAMP_CLI_DONT_THROW(false);
};

#endif /* CBS_INCLUDE_INSTALLER_H */
