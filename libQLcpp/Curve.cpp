#include <Curve.hpp>
#include <math.h>

namespace QL {

FlatDiscountCurve::FlatDiscountCurve(double r) : r(r) {}

FlatDiscountCurve::~FlatDiscountCurve() {}

double FlatDiscountCurve::discount(double x) const {
    return std::exp(-r * x);
}

}; // namespace QL