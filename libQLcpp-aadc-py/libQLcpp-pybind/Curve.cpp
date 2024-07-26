#include <Curve.hpp>
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

// QL::Curve file:Curve.hpp line:6
struct PyCallBack_QL_Curve : public QL::Curve {
	using QL::Curve::Curve;

	class idouble discount(class idouble a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const QL::Curve *>(this), "discount");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<class idouble>::value) {
				static pybind11::detail::override_caster_t<class idouble> caster;
				return pybind11::detail::cast_ref<class idouble>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class idouble>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Curve::discount\"");
	}
};

// QL::FlatDiscountCurve file:Curve.hpp line:13
struct PyCallBack_QL_FlatDiscountCurve : public QL::FlatDiscountCurve {
	using QL::FlatDiscountCurve::FlatDiscountCurve;

	class idouble discount(class idouble a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const QL::FlatDiscountCurve *>(this), "discount");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<class idouble>::value) {
				static pybind11::detail::override_caster_t<class idouble> caster;
				return pybind11::detail::cast_ref<class idouble>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class idouble>(std::move(o));
		}
		return FlatDiscountCurve::discount(a0);
	}
};

void bind_Curve(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // QL::Curve file:Curve.hpp line:6
		 using namespace QuantLib;
		pybind11::class_<QL::Curve, std::shared_ptr<QL::Curve>, PyCallBack_QL_Curve> cl(M("QL"), "Curve", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_QL_Curve(); } ) );
		cl.def(pybind11::init<PyCallBack_QL_Curve const &>());
		cl.def("discount", (class idouble (QL::Curve::*)(class idouble) const) &QL::Curve::discount, "C++: QL::Curve::discount(class idouble) const --> class idouble", pybind11::arg("x"));
		cl.def("assign", (class QL::Curve & (QL::Curve::*)(const class QL::Curve &)) &QL::Curve::operator=, "C++: QL::Curve::operator=(const class QL::Curve &) --> class QL::Curve &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // QL::FlatDiscountCurve file:Curve.hpp line:13
		 using namespace QuantLib;
		pybind11::class_<QL::FlatDiscountCurve, std::shared_ptr<QL::FlatDiscountCurve>, PyCallBack_QL_FlatDiscountCurve, QL::Curve> cl(M("QL"), "FlatDiscountCurve", "");
		cl.def( pybind11::init<class idouble>(), pybind11::arg("r") );

		cl.def( pybind11::init( [](PyCallBack_QL_FlatDiscountCurve const &o){ return new PyCallBack_QL_FlatDiscountCurve(o); } ) );
		cl.def( pybind11::init( [](QL::FlatDiscountCurve const &o){ return new QL::FlatDiscountCurve(o); } ) );
		cl.def("discount", (class idouble (QL::FlatDiscountCurve::*)(class idouble) const) &QL::FlatDiscountCurve::discount, "C++: QL::FlatDiscountCurve::discount(class idouble) const --> class idouble", pybind11::arg("x"));
		cl.def("assign", (class QL::FlatDiscountCurve & (QL::FlatDiscountCurve::*)(const class QL::FlatDiscountCurve &)) &QL::FlatDiscountCurve::operator=, "C++: QL::FlatDiscountCurve::operator=(const class QL::FlatDiscountCurve &) --> class QL::FlatDiscountCurve &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
