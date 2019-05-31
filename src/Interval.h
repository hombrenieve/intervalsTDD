#ifndef _INTERVAL_H_
#define _INTERVAL_H_

class Interval {
public:
    Interval(double min, double max);
    virtual ~Interval() = default;
    virtual bool isIntersected(const Interval& another) const;

    double getMin() const;
    double getMax() const;

protected:
    double min;
    double max;

    virtual bool isIncluded(double value) const = 0;
};

#endif