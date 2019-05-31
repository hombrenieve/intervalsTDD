#include "Interval.h"
#include <cassert>

Interval::Interval(double min, double max) :
    min(min),
    max(max)
{ 
    assert(min < max);
}

double Interval::getMin() const {
    return this->min;
}

double Interval::getMax() const {
    return this->max;
}

bool Interval::isIntersected(const Interval& another) const {
    return this->isIncluded(another.min) ||
        this->isIncluded(another.max)||
        another.isIncluded(this->min);
}