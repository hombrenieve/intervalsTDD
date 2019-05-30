#include "ClosedIntervalBuilder.h"

ClosedIntervalBuilder& ClosedIntervalBuilder::min(double min) {
    this->minValue = min;
    return *this;
}

ClosedIntervalBuilder& ClosedIntervalBuilder::max(double max) {
    this->maxValue = max;
    return *this;
}

ClosedInterval ClosedIntervalBuilder::build() {
    return ClosedInterval(this->minValue, this->maxValue);
}