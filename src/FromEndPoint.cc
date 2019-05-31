#include "FromEndPoint.h"

FromEndPoint::FromEndPoint(double value, bool isIncluded) :
    EndPoint(value, isIncluded)
{ }

bool FromEndPoint::isLeftWhenNotIncluded() const {
    return false;
}

bool FromEndPoint::isRightWhenNotIncluded() const {
    return true;
}