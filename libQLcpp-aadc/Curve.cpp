#include <Curve.hpp>
#include <math.h>

namespace QL {

FlatDiscountCurve::FlatDiscountCurve(Real r) : r(r) {}

FlatDiscountCurve::~FlatDiscountCurve() {}

Real FlatDiscountCurve::discount(Real x) const {
    return std::exp(-r * x);
}

}; // namespace QL