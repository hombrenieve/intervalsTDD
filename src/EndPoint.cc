#include "EndPoint.h"

 EndPoint::EndPoint(double value, bool isIncluded) :
    value(value),
    isIncludedValue(isIncluded)
{ }

 double EndPoint::getValue() const {
     return this->value;
 }
 bool EndPoint::isIncluded() const {
     return this->isIncludedValue;
 }