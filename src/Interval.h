#ifndef _INTERVAL_H_
#define _INTERVAL_H_

#include "FromEndPoint.h"
#include "UntilEndPoint.h"

class Interval {
public:
    Interval(double min, double max);
    virtual ~Interval() = default;
    virtual bool isIntersected(const Interval* another) const;

    double getMin() const;
    double getMax() const;

protected:
    FromEndPoint from;
    UntilEndPoint until;

    virtual bool isIncluded(double value) const = 0;
};

#endif