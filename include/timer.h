#include <iostream>
#include <chrono>
#include <thread>

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

    void elapsedTime() {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
};