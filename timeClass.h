#ifndef TIME_H
#define TIME_H

#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <locale>
#include <sstream>

class Time
{
private:
    int day;
    int week;
public:
    Time();
    int getCurrDay();
    int getCurrWeek();
    int getDay();
    int getWeek();
};

#endif // TIME_H
