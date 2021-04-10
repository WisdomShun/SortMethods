//
// Created by Administrator on 2021/4/3.
//

#include "Timer.h"
#include <cstdio>


Timer::Timer() {
    m_timer = std::chrono::steady_clock::now();
}

Timer::~Timer() {
    auto end_timer = std::chrono::steady_clock::now();
    auto duration = duration_cast<milliseconds>(end_timer - m_timer);

    //auto milli_cost = duration.count() * milliseconds::period::num / milliseconds::period::den;

    printf("cost %d milliseconds\n", duration.count());
}
