#include "aadc_types.hpp"
#include "Curve.hpp"
#include <cmath>

namespace QL {

FlatDiscountCurve::FlatDiscountCurve(Real r) : r(r) {}

FlatDiscountCurve::~FlatDiscountCurve() {}

Real FlatDiscountCurve::discount(Real x) const {
    return std::exp(-r * x);
}

}; // namespace QL
