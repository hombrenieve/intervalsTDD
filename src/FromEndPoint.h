#ifndef _FROMENDPOINT_H_
#define _FROMENDPOINT_H_

#include "EndPoint.h"

class FromEndPoint: public EndPoint {
public:
    FromEndPoint(double value, bool isIncluded);

protected:
    bool isLeftWhenEquals(const EndPoint* another) const override;
    bool isRightWhenEquals(const EndPoint* another) const override;

};

#endif