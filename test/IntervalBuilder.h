#ifndef __INTERVAL_BUILDER_H_
#define __INTERVAL_BUILDER_H_

#include "Interval.h"


class IntervalBuilder {
public:
    IntervalBuilder();

    IntervalBuilder& from(const FromEndPoint& fromValue);
    IntervalBuilder& until(const UntilEndPoint& untilValue);

    Interval build();

private:
    FromEndPoint fromValue;
    UntilEndPoint untilValue;
};

#endif 