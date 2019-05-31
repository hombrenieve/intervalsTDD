#include "EndPoint.h"

 EndPoint::EndPoint(double point, bool isIncluded) :
    point(point),
    isIncluded(isIncluded)
{ }

bool EndPoint::isLeftOf(const EndPoint& another) const {
    return this->point <= another.point;
}

bool EndPoint::isRightOf(const EndPoint& another) const {
    return false;
}