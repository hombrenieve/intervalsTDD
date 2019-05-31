#include "UntilEndPoint.h"

UntilEndPoint::UntilEndPoint(double value, bool isIncluded) :
    EndPoint(value, isIncluded)
{ }

bool UntilEndPoint::isLeftWhenNotIncluded() const {
    return true;
}

bool UntilEndPoint::isRightWhenNotIncluded() const {
    return false;
}