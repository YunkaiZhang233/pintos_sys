#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H
#include <stdint.h>

static int f = 16384; // f = 2 ^ 14

typedef int fixed_point;

static inline fixed_point int_to_fixed_point(int n) {
    return n * f;
}

static inline int fixed_point_to_int(fixed_point x) {
    return x / f;
}

static inline int fixed_point_to_int_round(fixed_point x) {
    if (x >= 0) {
       return  ((x + f / 2) / f);
    } else {
        return ((x - f / 2) / f);
    }
}

static inline fixed_point ff_add(fixed_point x, fixed_point y) {
    return x + y;
}

static inline fixed_point ff_sub(fixed_point x, fixed_point y) {
    return x - y;
}

static inline fixed_point ff_mul(fixed_point x, fixed_point y) {
    return (((int64_t) x) * y / f);
}

static inline fixed_point ff_div(fixed_point x, fixed_point y) {
    return (((int64_t) x) * f / y);
}

static inline fixed_point fi_add(fixed_point x, int n) {
    return x + n * f;
}

static inline fixed_point fi_sub(fixed_point x, int n) {
    return x - n * f;
}

static inline fixed_point fi_mul(fixed_point x, int n) {
    return x * n;
}

static inline fixed_point fi_div(fixed_point x, int n) {
    return x / n;
}
#endif /**< threads/fixed_point.h */