#ifndef COMMON_OPS_H
#define COMMON_OPS_H

#include "assert.h"

inline bool IsEqual(float a, float b, int maxUlps = 6)
{
    assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
    int aInt = *(int*)&a;

    if (aInt < 0)
        aInt = 0x80000000 - aInt;

    int bInt = *(int*)&b;
    if (bInt < 0)
        bInt = 0x80000000 - bInt;

    int intDiff = abs(aInt - bInt);
    if (intDiff <= maxUlps)
        return true;

    return false;
}

#endif
