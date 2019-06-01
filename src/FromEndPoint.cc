#include "FromEndPoint.h"

FromEndPoint::FromEndPoint(double value, bool isIncluded) :
    EndPoint(value, isIncluded)
{ }

bool FromEndPoint::isLeftOf(const UntilEndPoint& another) const {
    if(this->isIncluded() and another.isIncluded()) {
        return this->getValue() <= another.getValue();
    }
    return this->getValue() < another.getValue();
}