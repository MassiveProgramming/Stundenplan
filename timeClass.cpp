#include "timeClass.h"

Time::Time()
{
    day = getCurrDay();
    week = getCurrWeek();
}

int Time::getDay()
{
    return day;
}

int Time::getWeek()
{
    return week;
}

int Time::getCurrDay()
{
    struct tm *timeval;
    time_t tt;
    tt = time( NULL );
    timeval = localtime( &tt );

    return timeval->tm_wday;
}

int Time::getCurrWeek()
{
    struct tm tm;
    time_t tt;
    char timebuf[ 3 ] = {};
    int woy = 0;

    tt = time( NULL );

    tm = *localtime( &tt );

    mktime( &tm );

    strftime( timebuf, sizeof( timebuf ), "%W", &tm );

    sscanf( timebuf, "%d", &woy );

    return woy;
}
