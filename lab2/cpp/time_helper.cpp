#pragma once
#include "common.h"

bool operator>(tm lhs, tm rhs)
{
    time_t firstDate = mktime(&lhs);
    time_t secondDate = mktime(&rhs);
    return firstDate > secondDate;
}

bool operator<(tm lhs, tm rhs)
{
    time_t firstDate = mktime(&lhs);
    time_t secondDate = mktime(&rhs);
    return firstDate < secondDate;
}

bool operator==(tm lhs, tm rhs)
{
    time_t firstDate = mktime(&lhs);
    time_t secondDate = mktime(&rhs);
    return firstDate == secondDate;
}

tm operator+(const tm &lhs, tm &rhs)
{
    tm result = lhs;
    result.tm_sec += rhs.tm_sec;
    result.tm_min += rhs.tm_min;
    result.tm_hour += rhs.tm_hour;
    result.tm_mday += rhs.tm_mday;
    result.tm_mon += rhs.tm_mon;
    result.tm_year += rhs.tm_year;
    result.tm_wday += rhs.tm_wday;
    result.tm_yday += rhs.tm_yday;
}