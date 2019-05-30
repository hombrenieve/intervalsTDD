#include "ClosedInterval.h"

ClosedInterval::ClosedInterval(double min, double max) :
    min(min),
    max(max)
{ }

bool ClosedInterval::isIntersected(const ClosedInterval& another) {
    return this->isIncluded(another.min) ||
        this->isIncluded(another.max)||
        another.isIncluded(this->min);
}

bool ClosedInterval::isIncluded(double value) const {
    return this->min <= value && value <= this->max;
}