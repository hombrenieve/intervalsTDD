#include "Interval.h"
#include <cassert>

Interval::Interval(double min, double max) :
    from(min, true),
    until(max, true)
{ 
    assert(min < max);
}

double Interval::getMin() const {
    return this->from.getValue();
}

double Interval::getMax() const {
    return this->until.getValue();
}

bool Interval::isIntersected(const Interval* another) const {
    return this->isIncluded(another->getMin()) ||
        this->isIncluded(another->getMax())||
        another->isIncluded(this->getMin());
}