#include "stc_entry.h"

STC_entry::STC_entry()
{
    std::time_t t = std::time(0);
    myPointInTime = *std::localtime(&t);
}

tm STC_entry::getMyPointInTime()
{
    return myPointInTime;
}