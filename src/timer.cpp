#include "Timer.hpp"

Timer::Timer() {
    running = false;
    started = false;
}

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
    running = true;
    started = true;
}

void Timer::stop() {
    if (!started || !running) return;

    endTime = std::chrono::steady_clock::now();
    running = false;
}

long long Timer::elapsed() {
    if (!started) {
        return 0;
    }

    if (running) {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    } else {
        return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    }
}