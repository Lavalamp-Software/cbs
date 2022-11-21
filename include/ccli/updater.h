//============================================================================
// Name        : updater.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Service to update the CBS system
//============================================================================

#ifndef _CBS_INCLUDE_CCLI_UPDATER_H
#define _CBS_INCLUDE_CCLI_UPDATER_H

#include <curlpp/Options.hpp>

#include "cli_config.h"

namespace lavalamp {

namespace cli {

/**
 * The {updater} class is responsible
 * for fetching new updates for the CBS CLI.
 * It sends a HTTP GET Request to the CBS API
 * to fetch the new patch files and apply them
 * to the user machine. In case of abortion, failure
 * or unexpected termination, previous version files
 * will be cached if restoration is needed.
 */
class updater final {
private:
	/**
	 * {__update_complete} is a {LIB_LAVALAMP_STATIC} member
	 * which will be set to true if the CBS CLI update completed
	 * successfully.
	 */
	LIB_LAVALAMP_STATIC bool __update_complete;
	/**
	 * {__in_progress} is a {LIB_LAVALAMP_STATIC} member
	 * which will be set to true if the update is in progress.
	 */
	LIB_LAVALAMP_STATIC bool __in_progress;
	/**
	 * {__prog_left} is a {LIB_LAVALAMP_STATIC} member
	 * which will hold a value from 0-100 how much of the update
	 * is complete. This value cannot hold negative values, hence it is
	 * an unsigned integer.
	 */
	LIB_LAVALAMP_STATIC _uint __prog_left = 0;
	/**
	 * {__fp} is a {LIB_LAVALAMP_STATIC} member
	 * which represents the installation path for the
	 * new update patch files.
	 */
	LIB_LAVALAMP_STATIC const char* __fp;
private:
	/**
	 * Creates a backup context in-case the installation
	 * progress unexpectedly fails. The {updater#restore} will
	 * look for the previous patch files backed up by this method.
	 */
	LIB_LAVALAMP_STATIC void backup() LIB_LAVALAMP_CONST_RETURN LIB_LAVALAMP_CLI_DONT_THROW(false);
private:
	// This is a singleton class, objects are not needed.
	updater() = delete;
	~updater() = delete;
protected:
	/**
	 * Applies the new patch files to the {__fp} location.
	 * Since patch files will not directly go to the {__fp} location,
	 * it needs to be applied to validate the update. Returns true if the
	 * validation is successful;
	 */
	LIB_LAVALAMP_STATIC bool apply() LIB_LAVALAMP_CLI_DONT_THROW(false);
	/**
	 * Cleans any left over cache, releases any thread-pools or removes old backup
	 * files.
	 */
	LIB_LAVALAMP_STATIC LIB_LAVALAMP_CONST_FUNC bool clean() 	LIB_LAVALAMP_CONST_RETURN LIB_LAVALAMP_CLI_DONT_THROW(true);
	LIB_LAVALAMP_STATIC LIB_LAVALAMP_CONST_FUNC bool complete() LIB_LAVALAMP_CONST_RETURN LIB_LAVALAMP_CLI_DONT_THROW(true);
	LIB_LAVALAMP_STATIC 						void abort() 	LIB_LAVALAMP_CLI_DONT_THROW(false);
	LIB_LAVALAMP_STATIC 						void cache() 	LIB_LAVALAMP_CONST_RETURN LIB_LAVALAMP_CLI_DONT_THROW(false);
	LIB_LAVALAMP_STATIC 						void restore() 	LIB_LAVALAMP_CLI_DONT_THROW(false);
};

}
}

#endif /* _CBS_INCLUDE_CCLI_UPDATER_H */
