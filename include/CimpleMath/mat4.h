#pragma once 
#include "vec.h"
#include "mat3.h"
#include <stddef.h>
#include <stdio.h>

typedef union 
{
    vec4 cols[4];
    float d[4][4];
} mat4;

static inline
mat4 make_mat4_1(float value) 
{ 
    return (mat4)
    { 
        {
            make_vec4_4(value, 0.0f, 0.0f, 0.0f), 
            make_vec4_4(0.0f, value, 0.0f, 0.0f), 
            make_vec4_4(0.0f, 0.0f, value, 0.0f),
            make_vec4_4(0.0f, 0.0f, 0.0f, value),
        } 
    }; 
}

static inline
mat4 make_mat4_16(
        float a00, float a01, float a02, float a03,
        float a10, float a11, float a12, float a13,
        float a20, float a21, float a22, float a23,
        float a30, float a31, float a32, float a33) 
{ 
    return (mat4)
    { 
        {
            make_vec4_4(a00, a10, a20, a30), 
            make_vec4_4(a01, a11, a21, a31), 
            make_vec4_4(a02, a12, a22, a32),
            make_vec4_4(a03, a13, a23, a33),
        } 
    }; 
}

static inline
mat4 m4a(mat4 a, mat4 b) 
{ 
    return (mat4)
    {
        {
            v4a(a.cols[0], b.cols[0]), 
            v4a(a.cols[1], b.cols[1]),
            v4a(a.cols[2], b.cols[2]),
            v4a(a.cols[3], b.cols[3])
        }
    };
}

static inline 
mat4 m4af(mat4 a, float b)
{
    return m4a(a, make_mat4_1(b));
}

static inline 
mat4 fam4(float b, mat4 a)
{
    return m4a(a, make_mat4_1(b));
}

static inline 
vec4 m4mv4(mat4 a, vec4 b)
{
    return v4a(v4a(v4a(v4mf(a.cols[0], b.x), v4mf(a.cols[1], b.y)), v4mf(a.cols[2], b.z)), 
            v4mf(a.cols[3], b.w));
}

static inline 
mat4 m4m(mat4 a, mat4 b)
{
    return (mat4)
    {
        {
            m4mv4(a, b.cols[0]),
            m4mv4(a, b.cols[1]),
            m4mv4(a, b.cols[2]),
            m4mv4(a, b.cols[3])
        }
    };
}

static inline 
mat4 m4mf(mat4 a, float b)
{
    return (mat4)
    {
        {
            v4mf(a.cols[0], b),
            v4mf(a.cols[1], b),
            v4mf(a.cols[2], b),
            v4mf(a.cols[3], b)
        }
    };
}

static inline 
mat4 fmm4(float b, mat4 a)
{
    return m4mf(a, b);
}

static inline 
mat4 m4s(mat4 a, mat4 b)
{
    return (mat4)
    {
        {
            v4s(a.cols[0], b.cols[0]),
            v4s(a.cols[1], b.cols[1]),
            v4s(a.cols[2], b.cols[2]),
            v4s(a.cols[3], b.cols[3])
        }
    };
}

static inline 
mat4 m4sf(mat4 a, float b)
{
    return m4af(a, -b);
}

static inline 
mat4 fsm4(float b, mat4 a)
{
    return m4af(a, -b);
}

static inline 
mat4 m4df(mat4 a, float b)
{
    return m4mf(a, 1.0f/b);
}

static inline 
mat4 m4t(mat4 a)
{
    return make_mat4_16(
            a.d[0][0], a.d[0][1], a.d[0][2], a.d[0][3],
            a.d[1][0], a.d[1][1], a.d[1][2], a.d[1][3],
            a.d[2][0], a.d[2][1], a.d[2][2], a.d[2][3],
            a.d[3][0], a.d[3][1], a.d[3][2], a.d[3][3]);
}

static inline 
float m4_alg_compl(mat4 m, size_t row, size_t col)
{
    mat3 other;
    for (size_t c = 0, j = 0; c < 4; ((c == col) ? j : ++j), ++c)
    for (size_t r = 0, i = 0; r < 4; ((r == row) ? i : ++i), ++r)
    {
        if (c != col && r != row) other.d[j][i] = m.d[c][r];
    }

    return det3(other) * ((row+col)%2 ? 1 : -1);
}

static inline
float det4(mat4 a) 
{   
    return  + m4_alg_compl(a, 0, 0) * a.d[0][0] 
            + m4_alg_compl(a, 0, 1) * a.d[1][0] 
            + m4_alg_compl(a, 0, 2) * a.d[2][0]
            + m4_alg_compl(a, 0, 3) * a.d[3][0];
}

static inline
mat4 m4i(mat4 a)
{
    mat4 union_matrix = m4t(make_mat4_16(
        m4_alg_compl(a, 0, 0), m4_alg_compl(a, 0, 1), m4_alg_compl(a, 0, 2), m4_alg_compl(a, 0, 3),
        m4_alg_compl(a, 1, 0), m4_alg_compl(a, 1, 1), m4_alg_compl(a, 1, 2), m4_alg_compl(a, 1, 3),
        m4_alg_compl(a, 2, 0), m4_alg_compl(a, 2, 1), m4_alg_compl(a, 2, 2), m4_alg_compl(a, 2, 3),
        m4_alg_compl(a, 3, 0), m4_alg_compl(a, 3, 1), m4_alg_compl(a, 3, 2), m4_alg_compl(a, 3, 3)));
    return m4df(union_matrix, det4(a));
}