//============================================================================
// Name        : cbs.cpp
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Entry point for application
//============================================================================

#include "../include/ccli/command.h"
#include "../include/ccli/uploader.h"
#include "../include/network/http.h"
#include "../include/threading/thread_pool.h"
#include "../include/encode/base64.h"

#include <iostream>
#include <cstdio>

#include <curl/curl.h>

namespace thread = lavalamp::concurrent;
namespace network = lavalamp::network;

int main() {
	thread::thread_pool netty([]() -> void {
		network::http htp("http://calapi.inadiutorium.cz/api/v0/en/calendars/general-en/2021/03");
		htp.send_request();
		std::cout << htp.get_raw_response() << std::endl;
	});
	netty.exec();
}
