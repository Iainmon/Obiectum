#include <chrono>
#include <iostream>

#include "./StopClock.hpp"

using namespace obiectum;
using namespace physics;

const char *ClockAlreadyRunningException::what() const throw() { return "This StopClock instance has already been started. Consider the 'Reset()' method."; }
const char *ClockNeverStartedException::what() const throw() { return "This StopClock instance has not been started. Consider the 'Start()' or 'Reset()' methods."; }

uint64_t StopClock::micros(void) { return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(); }

StopClock::StopClock() {
    startTime = 0;
    endTime = 0;
    isRunning = false;
}

StopClock::StopClock(const bool startClockOnInstantiation) {

    startTime = 0;
    endTime = 0;
    isRunning = false;

    if (startClockOnInstantiation) {
        isRunning = true;
        startTime = StopClock::micros();
    }
}

void StopClock::Start(void) {
    if (isRunning) {
        throw ClockAlreadyRunningException();
        return;
    }

    Reset();
}
void StopClock::Stop(void) {
    if (!isRunning) {
        throw ClockNeverStartedException();
        return;
    }

    isRunning = false;
    endTime = StopClock::micros();
}

void StopClock::Reset(void) {
    isRunning = true;
    endTime = 0;
    startTime = StopClock::micros();
}

int StopClock::DeltaTime(void) const {

    const uint64_t currentTime = StopClock::micros();

    if (startTime == 0) {
        throw ClockNeverStartedException();
    }

    if (endTime != 0) {
        return endTime - startTime;
    }

    return currentTime - startTime;
}
