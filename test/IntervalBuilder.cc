#include "IntervalBuilder.h"

IntervalBuilder::IntervalBuilder() :
    minValue(0),
    maxValue(1),
    type(IntervalType::CLOSED)
{ }

IntervalBuilder& IntervalBuilder::min(double min) {
    this->minValue = min;
    return *this;
}

IntervalBuilder& IntervalBuilder::max(double max) {
    this->maxValue = max;
    return *this;
}

IntervalBuilder& IntervalBuilder::open() {
    this->type = IntervalType::OPEN;
    return *this;
}

IntervalBuilder& IntervalBuilder::closed() {
    this->type = IntervalType::CLOSED;
    return *this;
}

IntervalBuilder& IntervalBuilder::closedOpen() {
    this->type = IntervalType::CLOSED_OPEN;
    return *this;
}

Interval* IntervalBuilder::build() {
    switch(this->type) {
        case IntervalType::CLOSED:
            return new ClosedInterval(this->minValue, this->maxValue);
        case IntervalType::OPEN:
            return new OpenInterval(this->minValue, this->maxValue);
        case IntervalType::CLOSED_OPEN:
            return new ClosedOpenInterval(this->minValue, this->maxValue);
        default:
            break;
    }
    return nullptr;
}

