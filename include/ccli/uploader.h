//============================================================================
// Name        : command.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Base class for CLI actions
//============================================================================

#ifndef _CBS_INCLUDE_CCLI_UPLOADER_H
#define _CBS_INCLUDE_CCLI_UPLOADER_H

#include "cli_config.h"

namespace lavalamp {

namespace cli {

/**
 * The {uploader} class is a child derived
 * from {command} which is a CLI action interface.
 * This class allows users to upload packages to the
 * CBS site for other users to access and download their
 * packages. This class is marked as final and should not be
 * derived from.
*/
class uploader final : public command {
private:
	/**
	 * {__uploader_service_succeed} will be
	 * set to true if the user package was
	 * successfully uploaded to the CBS site.
	 */
	bool __uploader_service_succeed;
	/**
	 * {__is_api_awake} will be
	 * set to true if the CBS service API
	 * is currently active. If not, then please
	 * wait for the CBS API to be restored.
	 */
	bool __is_api_awake;
	/**
	 * {__validated_package} will be
	 * set to true if the the parsing process
	 * found the project to be setup correctly.
	 * The project must contain a `config.cbf`
	 * file in the root directory of the project.
	 */
	bool __validated_package;
	/**
	 * {__cmd} is the actual command given
	 * and will be the target value to be executed.
	 * If {__cmd} is validated by (command#validate},
	 * then the process of execution will take place
	 * and the final result of execution will be placed
	 * upon {command#execute}
	 */
	const char* __cmd;
	/**
	 * {__input} is the data collected from the terminal
	 * by the user. This input will be translated to
	 * {__cmd} and then proceed for validation
	 * via {command#validate}.
	 */
	const char* __input;
	/**
	 * {__prompt_data} is the information
	 * collected from the {uploader#prompt} function.
	 * Any specific information for uploading will be
	 * collected and stored here.
	 */
	char* __prompt_data;
	/**
	 * {__flags} is the flags for the CBS CLI
	 * system to execute if the user requests
	 * the CLI to handle functionality in a specific
	 * way.
	 */
	char* __flags;
private:
	/**
	 * Asynchronously upload package
	 * data to the CBS site. Parameter #1
	 * requires a valid path location to the
	 * package/project that will be uploaded.
	 * Returns false if an exception occurs
	 * or if the API is down.
	 */
	LIB_LAVALAMP_CONST_FUNC bool __upload_async(const char*) LIB_LAVALAMP_CLI_DONT_THROW(false);
	/**
	 * Parsers the project to ensure there is a
	 * `config.cbf` file and its contents have
	 * valid syntax. If not, then this will return
	 * false
	 */
	LIB_LAVALAMP_CONST_FUNC bool __validate_package(const char*) LIB_LAVALAMP_CLI_DONT_THROW(false);
	/**
	 * Checks if the CBS API is alive by sending
	 * a HTTP Request with dummy data. If HTTP response 200
	 * is given, the API is alive and this will return true.
	 */
	LIB_LAVALAMP_CONST_FUNC bool __api_awake() LIB_LAVALAMP_CLI_DONT_THROW(false);
	/**
	 * Encodes the project files into base64
	 * to simplify the storage of package content
	 * and ease load on the CBS API.
	 */
	void __encode() LIB_LAVALAMP_CLI_DONT_THROW(false);
public:
	uploader();
	~uploader() override;
	/*
	 * Copy constructors/Assignment operators are redundant
	 * for this child class
	 */
	uploader(const uploader&) = delete;
	uploader(uploader&) = delete;

	uploader& operator = (const uploader&) = delete;
	uploader operator = (uploader&) = delete;
public:
	/**
	 * Before finalising the upload action,
	 * ensure any flags or data for the package
	 * needs to be collected before uploading it
	 * will be collected here.
	 */
	void prompt();
	/**
	 * Execute the command set by {__cmd}
	 * If the execution succeeded without errors,
	 * the value of {command#execute} will be true.
	 */
	LIB_LAVALAMP_CONST_FUNC bool execute() LIB_LAVALAMP_CLI_DONT_THROW(false) override;
	/**
	 * Validate the command set by {__cmd}
	 * If there is no syntax errors, then
	 * {command#validate} will be true.
	 */
	LIB_LAVALAMP_CONST_FUNC bool validate() LIB_LAVALAMP_CLI_DONT_THROW(false) override;
	/**
	 * Sets the value of {__cmd} and will proceed
	 * for validation.
	 */
	void set_command(const char*) LIB_LAVALAMP_CLI_DONT_THROW(true) override;
	/**
	 * Fetch input from whatever terminal system
	 * the user is using. This will invoke
	 * {command#set_command} to set the final value
	 * of {__cmd} from {__input}.
	 */
	void get_input() LIB_LAVALAMP_CLI_DONT_THROW(true) override;
};

}
}

#endif /* _CBS_INCLUDE_CCLI_UPLOADER_H */
