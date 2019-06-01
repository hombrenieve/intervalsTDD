#ifndef _INTERVAL_H_
#define _INTERVAL_H_

#include "FromEndPoint.h"
#include "UntilEndPoint.h"

class Interval {
public:
    Interval(double min, double max);
    Interval(const FromEndPoint& from, const UntilEndPoint& until);
    virtual ~Interval() = default;
    virtual bool isIntersected(const Interval& another) const;

    double getMin() const;
    double getMax() const;

    const FromEndPoint& getFrom() const;
    const UntilEndPoint& getUntil() const;

protected:
    FromEndPoint from;
    UntilEndPoint until;
};

#endif