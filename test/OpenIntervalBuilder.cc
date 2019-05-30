#include "OpenIntervalBuilder.h"

OpenIntervalBuilder& OpenIntervalBuilder::min(double min) {
    this->minValue = min;
    return *this;
}

OpenIntervalBuilder& OpenIntervalBuilder::max(double max) {
    this->maxValue = max;
    return *this;
}

OpenInterval OpenIntervalBuilder::build() {
    return OpenInterval(this->minValue, this->maxValue);
}