#ifndef _CLOSED_INTERVAL_H_
#define _CLOSED_INTERVAL_H_
#include "Interval.h"

class ClosedInterval : public Interval{
public:
    ClosedInterval(double min, double max);

private:
    bool isIncluded(double value) const override;

};

#endif