import aadc
import numpy as np

ql = aadc.QL  # User library

flat = ql.FlatDiscountCurve(0.05)

print(flat.discount(1.0))

class UserMarket(ql.Market):
    def __init__(self):
        ql.Market.__init__(self)
        self.r = 0.05
    def getDiscountCurve(self):
        return ql.FlatDiscountCurve(self.r)
    
market = UserMarket()
cf = ql.CashFlow(100.0, 0.5)

pricer = ql.SimpleCashFlowPricer()

print(pricer.price(market, cf))


    
funcs = aadc.Functions()

market.r = aadc.idouble(market.r)

funcs.start_recording()

r_arg = market.r.mark_as_input()

price = pricer.price(market, cf)

price_res = price.mark_as_output()

funcs.stop_recording()

inputs = {
    r_arg:(0.04 * np.random.normal(1, 0.2, 20))
}

request = {price_res:[r_arg]}

Res = aadc.evaluate(funcs, request, inputs, aadc.ThreadPool(4))

print ("Scenario prices:")
print(Res[0][price_res])

print ("Scenario derivatives dP/dr:")
print(Res[1][price_res][r_arg])




