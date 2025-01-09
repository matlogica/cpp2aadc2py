#pragma once

#include "Curve.hpp"
#include <memory>


namespace QL {

class Market {
public:
    Market() {}
    virtual ~Market() {}
    virtual std::shared_ptr<Curve> getDiscountCurve() const = 0;
};

}; // namespace QL
