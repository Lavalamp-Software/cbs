/*
 * thread_pool.cpp
 *
 *  Created on: 23 Nov 2022
 *      Author: mustafamalik
 */

#include "../../include/threading/thread_pool.h"

using namespace lavalamp::concurrent;

thread_pool::thread_pool( __tfp fp) : __func(fp) {
	__core = std::thread(__func);
}

thread_pool::~thread_pool() {
	if (__core.joinable()) {
		__core.detach();
	}
}

// public

void thread_pool::set_execution(__tfp nfp) LIB_LAVALAMP_DONT_THROW(false) {
	__func = nfp;
	if (__core.joinable()) {
		throw std::runtime_error("Overriding running thread process");
	}
	__core = std::thread(__func);
}

void thread_pool::exec() LIB_LAVALAMP_DONT_THROW(true) {
	if (__func != nullptr && __core.joinable()) {
		__core.join();
	}
}

thread_pool::__tfp thread_pool::get_thread_func() LIB_LAVALAMP_DONT_THROW(true) {
	return __func;
}
