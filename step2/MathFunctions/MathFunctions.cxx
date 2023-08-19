#include "MathFunctions.h"
#include "mySqrt.h"

#ifndef USE_MY
#include <cmath>
#endif

namespace MathFunctions
{

        int add(int a, int b)
        {
#ifdef USE_MY
                return ::add(a, b);
#else
                return 100;
#endif
        }

        int sub(int a, int b)
        {
#ifdef USE_MY
                return ::sub(a, b);
#else
                return 100;
#endif
        }

        int mul(int a, int b)
        {
#ifdef USE_MY
                return ::mul(a, b);
#else
                return 100;
#endif
        }

        int sqrt(int a)
        {
#ifdef USE_MY
                return ::sqrt(a);
#else
                return 100;
#endif
        }
}
