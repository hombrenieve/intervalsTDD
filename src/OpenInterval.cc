#include "OpenInterval.h"

OpenInterval::OpenInterval(double min, double max) :
    min(min),
    max(max)
{ }

bool OpenInterval::isIntersected(const OpenInterval& another) const {
    return true;
}