#ifndef __INTERVAL_BUILDER_H_
#define __INTERVAL_BUILDER_H_

#include "ClosedInterval.h"
#include "OpenInterval.h"


class IntervalBuilder {
public:
    IntervalBuilder();

    IntervalBuilder& min(double min);
    IntervalBuilder& max(double max);

    IntervalBuilder& open();
    IntervalBuilder& closed();

    Interval* build();

private:
    double minValue;
    double maxValue;

    enum class IntervalType {
        OPEN,
        CLOSED
    } type;

};

#endif 