#include "aadc_types.hpp"
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

    std::shared_ptr<Curve> c(new FlatDiscountCurve(Real_Disambiguate(0.05)));
    MyMarket m(c);

    CashFlow cf = {Real_Disambiguate(100.0), Real_Disambiguate(1.0)};

    SimpleCashFlowPricer p;

    Real price = p.price(m, cf);

    std::cout << "Price: " << price << std::endl;

    return 0;
}
