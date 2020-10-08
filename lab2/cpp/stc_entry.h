#pragma once
#include "common.h"

//Space Time Continum Entry
class STC_entry
{
public:
    virtual void acceptImminentPassingOfTime(tm targetPointOfTime);
    tm getMyPointInTime();
    STC_entry();

private:
    tm myPointInTime;
};