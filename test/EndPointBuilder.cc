#include "EndPointBuilder.h"
#include "FromEndPoint.h"
#include "UntilEndPoint.h"

EndPointBuilder::EndPointBuilder() : 
    value(0),
    isIncluded(true),
    type(EndPointType::FROM)
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

EndPointBuilder& EndPointBuilder::from() {
    this->type = EndPointType::FROM;
    return *this;
}


EndPointBuilder& EndPointBuilder::until() {
    this->type = EndPointType::UNTIL;
    return *this;
}

EndPoint* EndPointBuilder::build() {
    if(this->type == EndPointType::FROM) {
        return new FromEndPoint(this->value, this->isIncluded);
    }
    return new UntilEndPoint(this->value, this->isIncluded);
}