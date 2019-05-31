#include "EndPoint.h"

 EndPoint::EndPoint(double value, bool isIncluded) :
    value(value),
    isIncludedValue(isIncluded)
{ }

bool EndPoint::isLeftOf(const EndPoint* another) const {
    if(this->value == another->value) {
        return this->isLeftWhenEquals(another);
    }
    return this->value < another->value;
}

bool EndPoint::isRightOf(const EndPoint* another) const {
    if(this->value == another->value) {
        return this->isRightWhenEquals(another);
    }
    return another->value < this->value;
}

 double EndPoint::getValue() const {
     return this->value;
 }
 bool EndPoint::isIncluded() const {
     return this->isIncludedValue;
 }