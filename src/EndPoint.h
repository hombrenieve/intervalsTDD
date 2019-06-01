#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

class EndPoint {
public:
    EndPoint(double value, bool isIncluded);
    virtual ~EndPoint() = default;

    double getValue() const;
    bool isIncluded() const;

private:
    double value;
    bool isIncludedValue;

};

#endif