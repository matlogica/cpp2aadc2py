#include "Curve.hpp"
#include <cmath>

namespace QL {

FlatDiscountCurve::FlatDiscountCurve(double r) : r(r) {}

FlatDiscountCurve::~FlatDiscountCurve() {}

double FlatDiscountCurve::discount(double x) const {
    return std::exp(-r * x);
}

}; // namespace QL
