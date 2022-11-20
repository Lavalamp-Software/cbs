//============================================================================
// Name        : command.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Base class for CLI actions
//============================================================================

#ifndef _CBS_INCLUDE_CC_COMMAND_H
#define _CBS_INCLUDE_CC_COMMAND_H

/**
 * The {command} class is the base class for
 * all CLI related actions. Any CLI command will
 * inherit this base class to get basic functionality
 * of interacting with the terminal and ensure the commands
 * entered by the user is validated correctly.
 *
 * NOTE: Please do not heap allocate this class.
 */
class command {
private:
	/**
	 * {__execute_success} will be set to true
	 * if the execution of the selected command
	 * runs successfully with no exceptions
	 */
	bool __execute_success;
	/**
	 * {__validated_src} will be set to true
	 * if the validation of parsing the command
	 * executed successfully with no syntax errors
	 */
	bool __validated_src;
	/**
	 * {__cmd} is the actual command given
	 * and will be the target value to be executed.
	 * If {__cmd} is validated by (__validated_src},
	 * then the process of execution will take place
	 * and the final result of execution will be placed
	 * upon {__execute_success}
	 */
	const char* __cmd;
	/**
	 * {__input} is the data collected from the terminal
	 * by the user. This input will be translated to
	 * {__cmd} and then proceed for validation.
	 */
	const char* __input;
public:
	command();
	virtual ~command();

	/*
	 * Copy constructors/Assignment operators are redundant
	 * for this base class
	 */
	command(const command&) = delete;
	command(command&) = delete;

	command& operator = (const command&) = delete;
	command operator = (command&) = delete;
public:
	/**
	 * Execute the command set by {__cmd}
	 * If the execution succeeded without errors,
	 * the value of {__execute_success} will be true.
	 */
	virtual const bool execute() const;
	/**
	 * Validate the command set by {__cmd}
	 * If there is no syntax errors, then
	 * {__validated_src} will be true.
	 */
	virtual const bool validate() const;
	/**
	 * Sets the value of {__cmd} and will proceed
	 * for validation.
	 */
	virtual void set_command(const char*) noexcept;
	/**
	 * Fetch input from whatever terminal system
	 * the user is using. This will invoke
	 * {command#set_command} to set the final value
	 * of {__cmd} from {__input}.
	 */
	virtual void get_input() noexcept;
};

#endif /* _CBS_INCLUDE_CC_COMMAND_H */
