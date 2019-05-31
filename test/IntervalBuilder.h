#ifndef __INTERVAL_BUILDER_H_
#define __INTERVAL_BUILDER_H_

#include "ClosedInterval.h"
#include "OpenInterval.h"
#include "ClosedOpenInterval.h"


class IntervalBuilder {
public:
    IntervalBuilder();

    IntervalBuilder& min(double min);
    IntervalBuilder& max(double max);

    IntervalBuilder& open();
    IntervalBuilder& closed();
    IntervalBuilder& closedOpen();

    Interval* build();

private:
    double minValue;
    double maxValue;

    enum class IntervalType {
        OPEN,
        CLOSED,
        CLOSED_OPEN
    } type;

};

#endif 