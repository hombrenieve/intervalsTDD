#ifndef _CLOSED_INTERVAL_BUILDER_H_
#define _CLOSED_INTERVAL_BUILDER_H_

#include "ClosedInterval.h"

class ClosedIntervalBuilder {
public:
    ClosedIntervalBuilder() = default;

    ClosedIntervalBuilder& min(double min);
    ClosedIntervalBuilder& max(double max);

    ClosedInterval build();

private:
    double minValue;
    double maxValue;

};

#endif 