#ifndef _FROMENDPOINT_H_
#define _FROMENDPOINT_H_

#include "EndPoint.h"
#include "UntilEndPoint.h"

class FromEndPoint: public EndPoint {
public:
    FromEndPoint(double value, bool isIncluded);

    bool isLeftOf(const UntilEndPoint& another) const;

};

#endif