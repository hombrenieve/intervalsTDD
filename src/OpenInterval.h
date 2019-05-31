#ifndef _OPEN_INTERVAL_H_
#define _OPEN_INTERVAL_H_
#include "Interval.h"

class OpenInterval : public Interval {
public:
    OpenInterval(double min, double max);

    bool isIntersected(const Interval* another) const override;

private:
    bool isIncluded(double value) const override;
};

#endif