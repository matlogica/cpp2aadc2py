#include <aadc_types.hpp>
#pragma once

namespace QL {

class Curve {
public:
    Curve() {}
    virtual ~Curve() {}
    virtual Real discount(Real x) const = 0;
};

class FlatDiscountCurve : public Curve {
public:
    FlatDiscountCurve(Real r);
    virtual ~FlatDiscountCurve();
    virtual Real discount(Real x) const;
private:
    Real r;
};

}; // namespace QL