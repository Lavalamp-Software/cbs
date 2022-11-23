//============================================================================
// Name        : base64_encode.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Encoding content into base64
//============================================================================

#ifndef CBS_INCLUDE_ENCODE_BASE64_ENCODE_H
#define CBS_INCLUDE_ENCODE_BASE64_ENCODE_H

#include "../config.h"
#include "base64.h"


class base64 {
private:
	base64();
	~base64();

	base64& operator = (base64&) = delete;
public:
	LIB_LAVALAMP_STATIC const char* encode(const char*, const bool& = false) LIB_LAVALAMP_DONT_THROW(true);
	LIB_LAVALAMP_STATIC const char* decode(const char*, const bool& = false) LIB_LAVALAMP_DONT_THROW(true);
};

#endif /* CBS_INCLUDE_ENCODE_BASE64_ENCODE_H */
