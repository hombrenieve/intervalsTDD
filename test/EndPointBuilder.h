#ifndef _ENDPOINTBUILDER_H_
#define _ENDPOINTBUILDER_H_

#include "EndPoint.h"

class EndPointBuilder {
public:
    EndPointBuilder();

    EndPointBuilder& point(double value);
    EndPointBuilder& included();
    EndPointBuilder& notIncluded();

    EndPoint build();

private:
    double value;
    bool isIncluded;
};

#endif