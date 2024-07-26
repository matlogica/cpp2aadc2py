#include <CashFlowPricer.hpp>
#include <Market.hpp>

namespace QL {

double SimpleCashFlowPricer::price(const Market& m, const CashFlow& c) const {
    return c.amount * (*m.getDiscountCurve()).discount(c.time);
}

};