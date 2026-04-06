#include <iostream>
#include <thread>
#include "Timer.hpp"

using namespace std;

int main() {
    Timer timer;

    // Test 1: elapsed before start
    cout << "Elapsed before start: " << timer.elapsed() << " seconds" << endl;

    // Test 2: stop before start
    timer.stop();
    cout << "Called stop() before start (no crash)" << endl;

    // Test 3: normal timing
    cout << "\nStarting timer..." << endl;
    timer.start();

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Elapsed while running: " << timer.elapsed() << " seconds" << endl;

    timer.stop();
    cout << "Timer stopped." << endl;

    cout << "Final elapsed time: " << timer.elapsed() << " seconds" << endl;

    // Test 4: restart timer
    cout << "\nRestarting timer..." << endl;
    timer.start();

    this_thread::sleep_for(chrono::seconds(1));

    timer.stop();
    cout << "Elapsed after restart: " << timer.elapsed() << " seconds" << endl;

    return 0;
}