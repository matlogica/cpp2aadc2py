#include "CashFlowPricer.hpp"
#include <iostream>

namespace QL {

class MyMarket : public Market {
public:
    MyMarket(std::shared_ptr<Curve> c) : c(c) {}
    virtual ~MyMarket() {}

    virtual std::shared_ptr<Curve> getDiscountCurve() const {
        return c;
    }

private:
    std::shared_ptr<Curve> c;
};


}; // namespace QL

int main() {

    using namespace QL;

    std::shared_ptr<Curve> c(new FlatDiscountCurve(0.05));
    MyMarket m(c);

    CashFlow cf = {100, 1};

    SimpleCashFlowPricer p;

    double price = p.price(m, cf);

    std::cout << "Price: " << price << std::endl;

    return 0;
}
