#pragma once
#include "common.h"

bool operator>(tm &lhs, tm &rhs);
bool operator<(tm &lhs, tm &rhs);
bool operator==(tm &lhs, tm &rhs);
tm operator+(const tm &lhs, tm &rhs);