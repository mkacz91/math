#ifndef KLETCH_MATH_BOX_H
#define KLETCH_MATH_BOX_H

#include "prefix.h"
#include "vec2.h"

namespace kletch {

template <typename T>
struct box2
{
    static const box2 EMPTY;

    T x0;
    T y0;
    T x1;
    T y1;

    box2() = default;

    box2(T x0, T y0, T x1, T y1) : x0(x0), y0(y0), x1(x1), y1(y1) { }

    void expand(T x, T y)
    {
        x0 = min(x0, x); x1 = max(x1, x);
        y0 = min(y0, y); y1 = max(y1, y);
    }

    void expand(const vec2<T>& u) { expand(u.x, u.y); }
};

typedef box2<float> box2f;
typedef box2<double> box2d;
typedef box2<real> box2r;

template <typename T>
const box2<T> box2<T>::EMPTY = box2<T>(
    std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity(),
    -std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity()
);

template <typename T>
std::ostream& operator << (std::ostream& out, const box2<T>& box)
{
    return out << '(' << box.x0 << ", " << box.y0 << ")-(" << box.x1 << ", " << box.y1 << ')';
}

} // namespace kletch

#endif // KLETCH_MATH_BOX_H
