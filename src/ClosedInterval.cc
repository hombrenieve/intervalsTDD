#include "ClosedInterval.h"

ClosedInterval::ClosedInterval(double min, double max) :
    Interval(min, max)
{ }

bool ClosedInterval::isIncluded(double value) const {
    return this->getMin() <= value && value <= this->getMax();
}