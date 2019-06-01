#include "IntervalBuilder.h"

IntervalBuilder::IntervalBuilder() :
    fromValue(0, true),
    untilValue(0, false)
{ }

IntervalBuilder& IntervalBuilder::from(const FromEndPoint& fromValue) {
    this->fromValue = fromValue;
    return *this;
}

IntervalBuilder& IntervalBuilder::until(const UntilEndPoint& untilValue) {
    this->untilValue = untilValue;
    return *this;
}

Interval IntervalBuilder::build() {
    return Interval(this->fromValue, this->untilValue);
}

