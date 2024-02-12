#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

std::string GetTime()
{
    auto now = std::chrono::system_clock::now();
    auto timeNow = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    struct std::tm timeInfo;
    localtime_s(&timeInfo, &timeNow);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S.", &timeInfo);

    sprintf_s(buffer + 9, sizeof(buffer) - 9, "%03d", static_cast<int>(ms.count()));

    return buffer;
}

class Timer {
public:
    void start(){
        start_time = std::chrono::system_clock::now();
    }

    void end(){
        end_time = std::chrono::system_clock::now();
    }

    void pause_for(int ms){
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    std::chrono::milliseconds elapsed(){
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    }

    std::string elapsed_to_str(){
        if (end_time == std::chrono::time_point<std::chrono::system_clock>()) {
            return "Timer not ended";
        }

        auto milliseconds = elapsed().count();

        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << milliseconds / 3600000 << ":";
        ss << std::setfill('0') << std::setw(2) << (milliseconds % 3600000) / 60000 << ":";
        ss << std::setfill('0') << std::setw(2) << (milliseconds % 60000) / 1000 << ".";
        ss << std::setfill('0') << std::setw(3) << (milliseconds % 1000);

        return ss.str();
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::time_point<std::chrono::system_clock> end_time;
};