#include "EndPointBuilder.h"

EndPointBuilder::EndPointBuilder() : 
    value(0),
    isIncluded(true)
{ }

EndPointBuilder& EndPointBuilder::point(double value) {
    this->value = value;
    return *this;
}

EndPointBuilder& EndPointBuilder::included() {
    this->isIncluded = true;
    return *this;
}

EndPointBuilder& EndPointBuilder::notIncluded() {
    this->isIncluded = false;
    return *this;
}

FromEndPoint EndPointBuilder::buildFrom() {
    return FromEndPoint(this->value, this->isIncluded);
}


UntilEndPoint EndPointBuilder::buildUntil() {
    return UntilEndPoint(this->value, this->isIncluded);
}
