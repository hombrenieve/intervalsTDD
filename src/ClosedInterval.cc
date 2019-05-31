#include "ClosedInterval.h"

ClosedInterval::ClosedInterval(double min, double max) :
    Interval(min, max)
{ }

bool ClosedInterval::isIncluded(double value) const {
    return this->min <= value && value <= this->max;
}