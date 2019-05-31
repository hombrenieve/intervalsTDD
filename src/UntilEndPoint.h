#ifndef _UNTILENDPOINT_H_
#define _UNTILENDPOINT_H_

#include "EndPoint.h"

class UntilEndPoint: public EndPoint {
public:
    UntilEndPoint(double value, bool isIncluded);

protected:
    bool isLeftWhenNotIncluded() const override;
    bool isRightWhenNotIncluded() const override;

};

#endif