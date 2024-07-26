#pragma once
#include <Market.hpp>

namespace QL {

class CashFlow {
public:
    CashFlow() {}
    CashFlow(double amount, double time) : amount(amount), time(time) {}
    double amount;
    double time;
};

class CashFlowPricer {
public:
    CashFlowPricer() {}
    virtual ~CashFlowPricer() {}

    virtual double price(const Market& m, const CashFlow& c) const = 0;
};

class SimpleCashFlowPricer : public CashFlowPricer {
public:
    SimpleCashFlowPricer() {}
    virtual ~SimpleCashFlowPricer() {}

    virtual double price(const Market& m, const CashFlow& c) const;
};

};