#ifndef _CLOSED_OPEN_INTERVAL_H_
#define _CLOSED_OPEN_INTERVAL_H_
#include "Interval.h"

class ClosedOpenInterval : public Interval{
public:
    ClosedOpenInterval(double min, double max);

private:
    bool isIncluded(double value) const override;

};

#endif