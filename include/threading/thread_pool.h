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

#include "../cclibstypes.h"
#include "../config.h"

class thread_pool final {
private:
	_uint __poolc;
#if defined(__APPLE__) || defined(__linux__)
	const _uint __core_count = std::thread::hardware_concurrency();
#elif _WIN32
	#include <windows.h>
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	const _uint __core_count = sysinfo.dwNumberOfProcessors;
#endif
	typedef void* (*__tfp)(void);
public:
	thread_pool();
	thread_pool(const _uint&, __tfp);
	~thread_pool();
public:
	void set_execution(__tfp) LIB_LAVALAMP_DONT_THROW(true);
	void spawn_multiple_threads() LIB_LAVALAMP_DONT_THROW(true);
	void exec() const LIB_LAVALAMP_DONT_THROW(true);
};

#endif /* CBS_INCLUDE_THREADING_THREAD_POOL_H */
