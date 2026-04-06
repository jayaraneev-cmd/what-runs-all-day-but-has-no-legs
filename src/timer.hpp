#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;
    bool running;
    bool started;

public:
    Timer();

    void start();
    void stop();
    long long elapsed(); // returns seconds
};

#endif