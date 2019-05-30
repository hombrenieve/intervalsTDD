#ifndef _OPEN_INTERVAL_BUILDER_H_
#define _OPEN_INTERVAL_BUILDER_H_

#include "OpenInterval.h"

class OpenIntervalBuilder {
public:
    OpenIntervalBuilder() = default;

    OpenIntervalBuilder& min(double min);
    OpenIntervalBuilder& max(double max);

    OpenInterval build();

private:
    double minValue;
    double maxValue;

};

#endif 