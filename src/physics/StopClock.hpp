#pragma once

typedef unsigned long long uint64_t;

namespace obiectum {
namespace physics {
using namespace std;

struct ClockAlreadyRunningException : public exception {
    const char *what() const throw();
};
struct ClockNeverStartedException : public exception {
    const char *what() const throw();
};

class StopClock {
  private:
    bool isRunning;

    uint64_t startTime;
    uint64_t endTime;

    static uint64_t micros(void);

  public:
    StopClock();
    StopClock(const bool startClockOnInstantiation);

    void Start(void);
    void Stop(void);
    void Reset(void);

    int DeltaTime(void) const;
    
};

} // namespace physics
} // namespace obiectum