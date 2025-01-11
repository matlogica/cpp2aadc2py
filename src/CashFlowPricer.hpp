#pragma once
#include "Market.hpp"

namespace QL {

class CashFlow {
public:
    CashFlow() {}
    CashFlow(Real amount, Real time) : amount(amount), time(time) {}
    Real amount;
    Real time;
};

class CashFlowPricer {
public:
    CashFlowPricer() {}
    virtual ~CashFlowPricer() {}

    virtual Real price(const Market& m, const CashFlow& c) const = 0;
};

class SimpleCashFlowPricer : public CashFlowPricer {
public:
    SimpleCashFlowPricer() {}
    virtual ~SimpleCashFlowPricer() {}

    virtual Real price(const Market& m, const CashFlow& c) const;
};

};
