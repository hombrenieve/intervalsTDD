#ifndef _OPEN_INTERVAL_H_
#define _OPEN_INTERVAL_H_

class OpenInterval {
public:
    OpenInterval(double min, double max);

    bool isIntersected(const OpenInterval& another) const;
private:
    double min;
    double max;
};

#endif