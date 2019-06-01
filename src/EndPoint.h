#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

class EndPoint {
public:
    EndPoint(double value, bool isIncluded);

    bool isLeftOf(const EndPoint* another) const;
    bool isRightOf(const EndPoint* another) const;

    double getValue() const;
    bool isIncluded() const;

private:
    double value;
    bool isIncludedValue;

    bool equals(const EndPoint* another) const;

protected:
    virtual bool isLeftWhenNotIncluded() const = 0;
    virtual bool isRightWhenNotIncluded() const = 0;
};

#endif