#pragma once 
#include "vec.h"

typedef union 
{
    vec2 cols[2];
    float d[2][2];
} mat2;

static inline
mat2 make_mat2_1(float value) 
{ 
    return (mat2){{make_vec2_2(value, 0.0f), make_vec2_2(0.0f, value)}}; 
}

static inline
mat2 make_mat2_4(float a00, float a01, float a10, float a11) 
{ 
    return (mat2){{make_vec2_2(a00, a10), make_vec2_2(a01, a11)}};
}

static inline
mat2 m2a(mat2 a, mat2 b) 
{ 
    return (mat2){{v2a(a.cols[0], b.cols[0]), v2a(a.cols[1], b.cols[1])}};
}

static inline 
mat2 m2af(mat2 a, float b)
{
    return m2a(a, make_mat2_1(b));
}

static inline 
mat2 fam2(float b, mat2 a)
{
    return m2a(a, make_mat2_1(b));
}

static inline 
vec2 m2mv2(mat2 a, vec2 b)
{
    return v2a(v2mf(a.cols[0], b.x), v2mf(a.cols[1], b.y));
}

static inline 
mat2 m2m(mat2 a, mat2 b)
{
    return (mat2)
    {
        {
            m2mv2(a, b.cols[0]),
            m2mv2(a, b.cols[1])
        }
    };
}

static inline 
mat2 m2mf(mat2 a, float b)
{
    return (mat2)
    {
        {
            v2mf(a.cols[0], b),
            v2mf(a.cols[1], b)
        }
    };
}

static inline 
mat2 fmm2(float b, mat2 a)
{
    return m2mf(a, b);
}

static inline 
mat2 m2s(mat2 a, mat2 b)
{
    return (mat2)
    {
        {
            v2s(a.cols[0],b.cols[0]),
            v2s(a.cols[1],b.cols[1])
        }
    };
}

static inline 
mat2 m2sf(mat2 a, float b)
{
    return m2af(a, -b);
}

static inline 
mat2 fsm2(float b, mat2 a)
{
    return m2af(a, -b);
}

static inline 
mat2 m2df(mat2 a, float b)
{
    return m2mf(a, 1.0f/b);
}

static inline 
mat2 m2t(mat2 a)
{
    return (mat2)
    {
        .d = 
        {
            { a.d[0][0], a.d[1][0] },
            { a.d[0][1], a.d[1][1] }
        }
    };
}

static inline 
float det2(mat2 a) { return a.d[0][0] * a.d[1][1] - a.d[0][1]*a.d[1][0]; }

static inline 
mat2 m2i(mat2 a)
{
    return m2df
    (
        (mat2)
        { 
            .d = 
            { 
                {  a.d[0][0], -a.d[0][1] }, 
                { -a.d[1][0],  a.d[1][1] } 
            }
        }, 
        det2(a)
    );
}

