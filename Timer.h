//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_TIMER_H
#define SORT_TIMER_H

#include <chrono>

using namespace std::chrono;

class Timer{
public:
    Timer();
    ~Timer();

private:
    time_point<steady_clock, nanoseconds> m_timer;
};

#endif //SORT_TIMER_H
