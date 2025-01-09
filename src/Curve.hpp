#pragma once

namespace QL {

class Curve {
public:
    Curve() {}
    virtual ~Curve() {}
    virtual double discount(double x) const = 0;
};

class FlatDiscountCurve : public Curve {
public:
    FlatDiscountCurve(double r);
    virtual ~FlatDiscountCurve();
    virtual double discount(double x) const;
private:
    double r;
};

}; // namespace QL