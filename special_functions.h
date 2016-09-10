#ifndef KLETCH_MATH_SPECIAL_FUNCTIONS_H
#define KLETCH_MATH_SPECIAL_FUNCTIONS_H

#include "prefix.h"

namespace kletch {

using std::abs;
using std::copysign;
using std::signbit;
using std::cos;
using std::sin;
using std::sqrt;
using std::hypot;
using std::log;
using std::floor;

#undef min
#undef max

inline int abs(int x) { return x >= 0 ? x : -x; }
inline float log(float b, float x) { return log(x) / log(b); }
inline float sgn(float x) { return signbit(x) ? -1.0f : 1.0f; }
inline double sgn(double x) { return signbit(x) ? -1.0 : 1.0; }
template <class T> inline T sq(T x) { return x * x; }
template <class T> inline T lerp(T v0, T v1, T a) { return (1 - a) * v0 + a * v1; }
template <class T, class S> inline common_t<T, S> min(T const& a, S const& b) { return a<b ? a:b; }
template <class T, class S> inline common_t<T, S> max(T const& a, S const& b) { return a>b ? a:b; }

} // namespace kletch

#endif // KLETCH_MATH_SPECIAL_FUNCTIONS_H
