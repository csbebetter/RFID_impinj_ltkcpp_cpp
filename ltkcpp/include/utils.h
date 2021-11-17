#include <ratio>
#include <chrono>
#include <sys/time.h>


/*c++11 获取 utc 时间戳*/
unsigned long long getTimeStamp();

unsigned long long getSteadyClock();

unsigned long long getPreciseTimeStamp();
