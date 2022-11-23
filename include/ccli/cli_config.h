//============================================================================
// Name        : cli_config.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Setup classes deriving command.h
//============================================================================

#ifndef _CBS_INCLUDE_CCLI_CLI_CONFIG_H
#define _CBS_INCLUDE_CCLI_CLI_CONFIG_H

#include "../cclibstypes.h"
#include "../config.h"
#include "../pathpresets.h"

#define LIB_LAVALAMP_CLI_DONT_THROW(__t_type) LIB_LAVALAMP_DONT_THROW(__t_type)

#ifndef _CBS_INCLUDE_CCLI_COMMAND_H
	#include "command.h"
#endif

#endif /* _CBS_INCLUDE_CCLI_CLI_CONFIG_H */
