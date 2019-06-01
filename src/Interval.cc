#include "Interval.h"
#include <cassert>

Interval::Interval(double min, double max) :
    from(min, true),
    until(max, true)
{ 
    assert(min < max);
}

Interval::Interval(const FromEndPoint& from, const UntilEndPoint& until) :
    from(from),
    until(until)
{ }

double Interval::getMin() const {
    return this->from.getValue();
}

double Interval::getMax() const {
    return this->until.getValue();
}

const FromEndPoint& Interval::getFrom() const {
    return this->from;
}

const UntilEndPoint& Interval::getUntil() const {
    return this->until;
}

bool Interval::isIntersected(const Interval& another) const {
    return this->getFrom().isLeftOf(another.getUntil()) and
        another.getFrom().isLeftOf(this->getUntil());
}