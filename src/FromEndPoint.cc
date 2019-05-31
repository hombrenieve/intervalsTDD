#include "FromEndPoint.h"

FromEndPoint::FromEndPoint(double value, bool isIncluded) :
    EndPoint(value, isIncluded)
{ }

bool FromEndPoint::isLeftWhenEquals(const EndPoint* another) const {
    if(this->isIncluded()) {
        return another->isRightOf(this);
    }
    return false;
}

bool FromEndPoint::isRightWhenEquals(const EndPoint* another) const {
    if(this->isIncluded()) {
        return another->isLeftOf(this);
    }
    return true;
}