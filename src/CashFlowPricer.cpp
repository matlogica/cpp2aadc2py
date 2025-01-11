#include "aadc_types.hpp"
#include "CashFlowPricer.hpp"
#include "Market.hpp"

namespace QL {

Real SimpleCashFlowPricer::price(const Market& m, const CashFlow& c) const {
    return c.amount * (*m.getDiscountCurve()).discount(c.time);
}

};
