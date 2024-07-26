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

void bind_aadc_idouble(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// idouble file:aadc/idouble.h line:286
	aadc_binders::idouble_binder(M(""));

}
