#pragma once

#include <cstdint>

#define AADCBOOST_CHECK_SMALL(x,y) {x; y;}
#define AADCBOOST_CHECK_CLOSE(x,y,tol) {x;y;tol;}

#define AADCBOOST_TEST1(x) {x; }
#define AADCBOOST_TEST2(x, msg) { x; }


#ifdef AADC_QL
#include <aadc/idouble.h>
#include <aadc/ibool.h>
// #include <aadc/iint.h>
#include <aadc/icomplex.h>
#include <aadc/aadc_std_vector.h>
#include <numeric>

typedef idouble Real; // define it globally
typedef ibool QLBool; // define it globally


#else
#include <aadc/aadc_passive.h>
typedef double Real;
#endif

#ifdef AADC_QL
    // #include <aadc/aadc_boost.h>
    #include <aadc/aadc_random.h>
    #include <aadc/aadc_std_type_traits.h>

    // used during AADC conversion script
    inline idouble Real_Disambiguate(const idouble& x) { return x; }
    inline idouble Real_Disambiguate(const double& x) { return x; } // NOLINT

#else
    #define aadcboost boost
    #define AAD_PASSIVE(x) (x)
    #define AAD_PASSIVE_PTR(x) (x)

    typedef Real Real_Disambiguate; // used during AADC conversion script
#endif
