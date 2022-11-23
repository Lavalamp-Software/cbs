//============================================================================
// Name        : http.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Make HTTP requests to CBS CLI API
//============================================================================

#ifndef CBS_INCLUDE_NETWORK_HTTP_H
#define CBS_INCLUDE_NETWORK_HTTP_H

#include "net_config.h"
#include "../threading/thread_pool.h"

enum class HTTP_CODES {
	RESPONSE_OK,
	RESPONSE_SEVER_DOWN,
	RESPONSE_CLIENT_DOWN,
	HTTP_UNKNOWN,
	HTTP_404
};

enum class HTTP_REQUEST {
	GET,
	POST,
	DELETE,
	PUT,
	PATCH
};

class http {
private:
	HTTP_CODES __response;
	HTTP_REQUEST __current_req;
	thread_pool __tp;
	int __max_tries;
public:
	explicit http();
	~http();
private:
	const HTTP_CODES get_response() const LIB_LAVALAMP_NET_DONT_THROW(true);
	const HTTP_CODES send_request(const HTTP_REQUEST&) const LIB_LAVALAMP_NET_DONT_THROW(false);
	const HTTP_CODES send_request(const HTTP_REQUEST&, const int&) const LIB_LAVALAMP_NET_DONT_THROW(false);
	const HTTP_CODES send_request_async(const HTTP_REQUEST&) const LIB_LAVALAMP_NET_DONT_THROW(false);
	const HTTP_CODES send_request_async(const HTTP_REQUEST&, const int&) const LIB_LAVALAMP_NET_DONT_THROW(false);

	HTTP_REQUEST get_current_request() const LIB_LAVALAMP_NET_DONT_THROW(true);
	int get_max_retries() const LIB_LAVALAMP_NET_DONT_THROW(true);
};

#endif /* CBS_INCLUDE_NETWORK_HTTP_H */
