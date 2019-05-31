#include "EndPoint.h"

 EndPoint::EndPoint(double value, bool isIncluded) :
    value(value),
    isIncludedValue(isIncluded)
{ }

bool EndPoint::equals(const EndPoint* another) const {
    return this->value == another->value;
}

bool EndPoint::bothIncluded(const EndPoint* another) const {
    return this->isIncluded() and another->isIncluded();
}

bool EndPoint::isLeftOf(const EndPoint* another) const {
    if(this->equals(another)) {
        return !this->bothIncluded(another) and 
            this->isLeftWhenEquals(another);
    }
    return this->value < another->value;
}

bool EndPoint::isRightOf(const EndPoint* another) const {
    if(this->equals(another)) {
        return !this->bothIncluded(another) and 
            this->isRightWhenEquals(another);
    }
    return another->value < this->value;
}

 double EndPoint::getValue() const {
     return this->value;
 }
 bool EndPoint::isIncluded() const {
     return this->isIncludedValue;
 }