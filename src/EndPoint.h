#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

class EndPoint {
public:
    EndPoint(double point, bool isIncluded);

    bool isLeftOf(const EndPoint& another) const;
    bool isRightOf(const EndPoint& another) const;

private:
    double point;
    bool isIncluded;
};

#endif