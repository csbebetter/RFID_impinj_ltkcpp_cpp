#include "utils.h"

using namespace  std::chrono;

typedef std::chrono::microseconds time_type;

unsigned long long getTimeStamp() {

	time_point<system_clock, time_type> now = time_point_cast<time_type>(system_clock::now());
	return now.time_since_epoch().count();
}

unsigned long long	getSteadyClock() {
	time_point<system_clock, time_type> now = time_point_cast<time_type>(system_clock::now());
	return now.time_since_epoch().count();
}

unsigned long long getPreciseTimeStamp(){
	
	struct timeval timenow;
	gettimeofday(&timenow,NULL);
	return timenow.tv_usec;//us
}
