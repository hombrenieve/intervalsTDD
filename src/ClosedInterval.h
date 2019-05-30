#ifndef _CLOSED_INTERVAL_H_
#define _CLOSED_INTERVAL_H_

class ClosedInterval {
public:
    ClosedInterval(double min, double max);

    bool isIntersected(const ClosedInterval& another);

private:
    double min;
    double max;

    bool isIncluded(double value) const;

};

#endif