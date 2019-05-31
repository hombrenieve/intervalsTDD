#include "ClosedOpenInterval.h"

ClosedOpenInterval::ClosedOpenInterval(double min, double max) :
    Interval(min, max)
{ }

bool ClosedOpenInterval::isIncluded(double value) const {
    return this->getMin() <= value && value < this->getMax();
}