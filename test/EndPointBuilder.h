#ifndef _ENDPOINTBUILDER_H_
#define _ENDPOINTBUILDER_H_

#include "EndPoint.h"

class EndPointBuilder {
public:
    EndPointBuilder();

    EndPointBuilder& point(double value);
    EndPointBuilder& included();
    EndPointBuilder& notIncluded();
    EndPointBuilder& from();
    EndPointBuilder& until();

    EndPoint* build();

private:
    double value;
    bool isIncluded;
    enum class EndPointType {
        FROM,
        UNTIL
    } type;
};

#endif