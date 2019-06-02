#ifndef _ENDPOINTBUILDER_H_
#define _ENDPOINTBUILDER_H_

#include "EndPoint.h"
#include "UntilEndPoint.h"
#include "FromEndPoint.h"

class EndPointBuilder {
public:
    EndPointBuilder();

    EndPointBuilder& point(double value);
    EndPointBuilder& included();
    EndPointBuilder& notIncluded();
    EndPointBuilder& included(bool isIncluded);
    FromEndPoint buildFrom();
    UntilEndPoint buildUntil();

private:
    double value;
    bool isIncluded;
};

#endif