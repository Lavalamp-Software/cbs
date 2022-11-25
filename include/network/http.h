//============================================================================
// Name        : http.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Make HTTP requests to CBS CLI API
//============================================================================

#ifndef CBS_INCLUDE_NETWORK_HTTP_H
#define CBS_INCLUDE_NETWORK_HTTP_H

#ifdef _WNN32
	#pragma warning (disable: 4703)
#endif

#include <curl/curl.h>

#include <istream>

#include "net_config.h"
#include "../threading/thread_pool.h"

using namespace lavalamp::concurrent;

namespace lavalamp {
namespace network {

enum class HTTP_CODES {
	RESPONSE_OK,
	RESPONSE_NOT_OK
};

class http {
private:
	CURL* __curl;
	CURLcode __reply = static_cast<CURLcode>(0); // make the compiler stop crying
	const char* __url;
private:
	void __cleanup() LIB_LAVALAMP_NET_DONT_THROW(true);
public:
	http(const char*);
	~http();
public:
	HTTP_CODES get_response() LIB_LAVALAMP_NET_DONT_THROW(true);
	CURLcode get_raw_response() LIB_LAVALAMP_NET_DONT_THROW(true);
	const char* get_url() LIB_LAVALAMP_NET_DONT_THROW(true);
	void send_request() LIB_LAVALAMP_NET_DONT_THROW(false);
};

}}

#endif /* CBS_INCLUDE_NETWORK_HTTP_H */
