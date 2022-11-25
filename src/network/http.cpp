/*
 * http.cpp
 *
 *  Created on: 23 Nov 2022
 *      Author: mustafamalik
 */

#include "../../include/network/http.h"

using namespace lavalamp::network;

http::http(const char* url) {
	curl_global_init(CURL_GLOBAL_ALL);
	__curl = curl_easy_init();
	__url = url;
}

http::~http() {
	__cleanup();
}

// private

void http::__cleanup() LIB_LAVALAMP_NET_DONT_THROW(true) {
	curl_easy_cleanup(__curl);
	curl_global_cleanup();
}

// public

HTTP_CODES http::get_response() LIB_LAVALAMP_NET_DONT_THROW(true) {
	return __reply != CURLE_OK ? HTTP_CODES::RESPONSE_NOT_OK : HTTP_CODES::RESPONSE_OK;
}

CURLcode http::get_raw_response() LIB_LAVALAMP_NET_DONT_THROW(true) {
	return __reply;
}

void http::send_request() LIB_LAVALAMP_NET_DONT_THROW(false) {
	if (__curl) {
		curl_easy_setopt(__curl, CURLOPT_URL, __url);
		__reply = curl_easy_perform(__curl);
	} else {
		throw std::runtime_error("CURL failed to initialise");
	}
}
