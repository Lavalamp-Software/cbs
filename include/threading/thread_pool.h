//============================================================================
// Name        : thread_pool.h
// Author      : Mustafa Malik
// Version     :
// Copyright   : Copyright (C) 2022 Lavalamp Software
// Description : Create a new worker thread
//============================================================================

#ifndef CBS_INCLUDE_THREADING_THREAD_POOL_H
#define CBS_INCLUDE_THREADING_THREAD_POOL_H

#include <thread>
#include <atomic>
#include <chrono>

#include "../cclibstypes.h"
#include "../config.h"

namespace lavalamp {
namespace concurrent {

class thread_pool final {
private:
	typedef void (*__tfp)();
	__tfp __func;
	std::thread __core;
public:
	thread_pool(__tfp = nullptr);
	~thread_pool();
public:
	void set_execution(__tfp) LIB_LAVALAMP_DONT_THROW(false);
	void exec() LIB_LAVALAMP_DONT_THROW(true);
	__tfp get_thread_func() LIB_LAVALAMP_DONT_THROW(true);
};

}}
#endif /* CBS_INCLUDE_THREADING_THREAD_POOL_H */
