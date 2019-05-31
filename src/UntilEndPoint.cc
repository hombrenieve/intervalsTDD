#include "UntilEndPoint.h"

UntilEndPoint::UntilEndPoint(double value, bool isIncluded) :
    EndPoint(value, isIncluded)
{ }

bool UntilEndPoint::isLeftWhenEquals(const EndPoint* another) const {
    if(this->isIncluded()) {
        return another->isRightOf(this);
    }
    return true;
}

bool UntilEndPoint::isRightWhenEquals(const EndPoint* another) const {
    return true;
}