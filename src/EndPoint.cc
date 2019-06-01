#include "EndPoint.h"

 EndPoint::EndPoint(double value, bool isIncluded) :
    value(value),
    isIncludedValue(isIncluded)
{ }

bool EndPoint::equals(const EndPoint* another) const {
    return this->value == another->value;
}

bool EndPoint::isLeftOf(const EndPoint* another) const {
    if(this->equals(another)) {
        return !this->isIncluded() and 
            this->isLeftWhenNotIncluded();
    }
    return this->value < another->value;
}

bool EndPoint::isRightOf(const EndPoint* another) const {
    if(this->equals(another)) {
        return !this->isIncluded() and 
            this->isRightWhenNotIncluded();
    }
    return another->value < this->value;
}

 double EndPoint::getValue() const {
     return this->value;
 }
 bool EndPoint::isIncluded() const {
     return this->isIncludedValue;
 }