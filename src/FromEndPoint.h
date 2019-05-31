#ifndef _FROMENDPOINT_H_
#define _FROMENDPOINT_H_

#include "EndPoint.h"

class FromEndPoint: public EndPoint {
public:
    FromEndPoint(double value, bool isIncluded);

protected:
    bool isLeftWhenNotIncluded() const override;
    bool isRightWhenNotIncluded() const override;

};

#endif