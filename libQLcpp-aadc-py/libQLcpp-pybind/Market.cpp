#include <CashFlowPricer.hpp>
#include <Curve.hpp>
#include <Market.hpp>
#include <aadc/idouble.h>
#include <iterator>
#include <memory>
#include <sstream> // __str__
#include <string>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <pybind_idouble_fix.hpp>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// QL::Market file:Market.hpp line:10
struct PyCallBack_QL_Market : public QL::Market {
	using QL::Market::Market;

	class std::shared_ptr<class QL::Curve> getDiscountCurve() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const QL::Market *>(this), "getDiscountCurve");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class std::shared_ptr<class QL::Curve>>::value) {
				static pybind11::detail::override_caster_t<class std::shared_ptr<class QL::Curve>> caster;
				return pybind11::detail::cast_ref<class std::shared_ptr<class QL::Curve>>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::shared_ptr<class QL::Curve>>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Market::getDiscountCurve\"");
	}
};

// QL::CashFlowPricer file:CashFlowPricer.hpp line:15
struct PyCallBack_QL_CashFlowPricer : public QL::CashFlowPricer {
	using QL::CashFlowPricer::CashFlowPricer;

	class idouble price(const class QL::Market & a0, const class QL::CashFlow & a1) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const QL::CashFlowPricer *>(this), "price");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class idouble>::value) {
				static pybind11::detail::override_caster_t<class idouble> caster;
				return pybind11::detail::cast_ref<class idouble>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class idouble>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CashFlowPricer::price\"");
	}
};

// QL::SimpleCashFlowPricer file:CashFlowPricer.hpp line:23
struct PyCallBack_QL_SimpleCashFlowPricer : public QL::SimpleCashFlowPricer {
	using QL::SimpleCashFlowPricer::SimpleCashFlowPricer;

	class idouble price(const class QL::Market & a0, const class QL::CashFlow & a1) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const QL::SimpleCashFlowPricer *>(this), "price");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class idouble>::value) {
				static pybind11::detail::override_caster_t<class idouble> caster;
				return pybind11::detail::cast_ref<class idouble>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class idouble>(std::move(o));
		}
		return SimpleCashFlowPricer::price(a0, a1);
	}
};

void bind_Market(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // QL::Market file:Market.hpp line:10
		 using namespace QuantLib;
		pybind11::class_<QL::Market, std::shared_ptr<QL::Market>, PyCallBack_QL_Market> cl(M("QL"), "Market", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_QL_Market(); } ) );
		cl.def("getDiscountCurve", (class std::shared_ptr<class QL::Curve> (QL::Market::*)() const) &QL::Market::getDiscountCurve, "C++: QL::Market::getDiscountCurve() const --> class std::shared_ptr<class QL::Curve>");
		cl.def("assign", (class QL::Market & (QL::Market::*)(const class QL::Market &)) &QL::Market::operator=, "C++: QL::Market::operator=(const class QL::Market &) --> class QL::Market &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // QL::CashFlow file:CashFlowPricer.hpp line:7
		 using namespace QuantLib;
		pybind11::class_<QL::CashFlow, std::shared_ptr<QL::CashFlow>> cl(M("QL"), "CashFlow", "");
		cl.def( pybind11::init( [](){ return new QL::CashFlow(); } ) );
		cl.def( pybind11::init<class idouble, class idouble>(), pybind11::arg("amount"), pybind11::arg("time") );

		cl.def( pybind11::init( [](QL::CashFlow const &o){ return new QL::CashFlow(o); } ) );
		cl.def_readwrite("amount", &QL::CashFlow::amount);
		cl.def_readwrite("time", &QL::CashFlow::time);
		cl.def("assign", (class QL::CashFlow & (QL::CashFlow::*)(const class QL::CashFlow &)) &QL::CashFlow::operator=, "C++: QL::CashFlow::operator=(const class QL::CashFlow &) --> class QL::CashFlow &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // QL::CashFlowPricer file:CashFlowPricer.hpp line:15
		 using namespace QuantLib;
		pybind11::class_<QL::CashFlowPricer, std::shared_ptr<QL::CashFlowPricer>, PyCallBack_QL_CashFlowPricer> cl(M("QL"), "CashFlowPricer", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_QL_CashFlowPricer(); } ) );
		cl.def(pybind11::init<PyCallBack_QL_CashFlowPricer const &>());
		cl.def("price", (class idouble (QL::CashFlowPricer::*)(const class QL::Market &, const class QL::CashFlow &) const) &QL::CashFlowPricer::price, "C++: QL::CashFlowPricer::price(const class QL::Market &, const class QL::CashFlow &) const --> class idouble", pybind11::arg("m"), pybind11::arg("c"));
		cl.def("assign", (class QL::CashFlowPricer & (QL::CashFlowPricer::*)(const class QL::CashFlowPricer &)) &QL::CashFlowPricer::operator=, "C++: QL::CashFlowPricer::operator=(const class QL::CashFlowPricer &) --> class QL::CashFlowPricer &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // QL::SimpleCashFlowPricer file:CashFlowPricer.hpp line:23
		 using namespace QuantLib;
		pybind11::class_<QL::SimpleCashFlowPricer, std::shared_ptr<QL::SimpleCashFlowPricer>, PyCallBack_QL_SimpleCashFlowPricer, QL::CashFlowPricer> cl(M("QL"), "SimpleCashFlowPricer", "");
		cl.def( pybind11::init( [](){ return new QL::SimpleCashFlowPricer(); }, [](){ return new PyCallBack_QL_SimpleCashFlowPricer(); } ) );
		cl.def( pybind11::init( [](PyCallBack_QL_SimpleCashFlowPricer const &o){ return new PyCallBack_QL_SimpleCashFlowPricer(o); } ) );
		cl.def( pybind11::init( [](QL::SimpleCashFlowPricer const &o){ return new QL::SimpleCashFlowPricer(o); } ) );
		cl.def("price", (class idouble (QL::SimpleCashFlowPricer::*)(const class QL::Market &, const class QL::CashFlow &) const) &QL::SimpleCashFlowPricer::price, "C++: QL::SimpleCashFlowPricer::price(const class QL::Market &, const class QL::CashFlow &) const --> class idouble", pybind11::arg("m"), pybind11::arg("c"));
		cl.def("assign", (class QL::SimpleCashFlowPricer & (QL::SimpleCashFlowPricer::*)(const class QL::SimpleCashFlowPricer &)) &QL::SimpleCashFlowPricer::operator=, "C++: QL::SimpleCashFlowPricer::operator=(const class QL::SimpleCashFlowPricer &) --> class QL::SimpleCashFlowPricer &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
