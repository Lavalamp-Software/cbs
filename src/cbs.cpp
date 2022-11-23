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

#include <iostream>
#include <thread>


int main() {
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
    std::cout << std::thread::hardware_concurrency() << std::endl;

}

