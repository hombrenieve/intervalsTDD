#include "OpenInterval.h"

OpenInterval::OpenInterval(double min, double max) :
    Interval(min, max)
{ }

bool OpenInterval::isIntersected(const Interval* another) const {
    return Interval::isIntersected(another) ||
        (this->getMin() == another->getMin() && this->max == another->getMax());
}

bool OpenInterval::isIncluded(double value) const {
    return this->getMin() < value && value < this->getMax();
}