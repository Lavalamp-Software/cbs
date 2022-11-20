//============================================================================
// Name        : deprecated.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Warns of usage with deprecated features
//============================================================================

#ifndef _CBS_INCLUDE_CCLI_DEPRECATED_H
#define _CBS_INCLUDE_CCLI_DEPRECATED_H

#if __cplusplus == 201103L
	#define _LIB_LAVALAMP_DEPRECATED(discard) __attribute__((deprecated))
#elif __cplusplus >= 201402L
	#define _LIB_LAVALAMP_DEPRECATED(msg) [[deprecated(msg)]]
#endif

#endif /* _CBS_INCLUDE_CCLI_DEPRECATED_H */
