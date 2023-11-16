#pragma once 
#include <stddef.h>
#include "vec.h"
#include "mat2.h"

typedef union 
{
    vec3 cols[3];
    float d[3][3];
} mat3;

static inline
mat3 make_mat3_1(float value) 
{ 
    return (mat3)
    { 
        {
            make_vec3_3(value, 0.0f, 0.0f), 
            make_vec3_3(0.0f, value, 0.0f), 
            make_vec3_3(0.0f, 0.0f, value)
        } 
    }; 
}

static inline
mat3 make_mat3_9(
        float a00, float a01, float a02,
        float a10, float a11, float a12,
        float a20, float a21, float a22) 
{ 
    return (mat3)
    { 
        {
            make_vec3_3(a00, a10, a20), 
            make_vec3_3(a01, a11, a21), 
            make_vec3_3(a02, a12, a22)
        } 
    }; 
}

static inline
mat3 m3a(mat3 a, mat3 b) 
{ 
    return (mat3)
    {
        {
            v3a(a.cols[0], b.cols[0]), 
            v3a(a.cols[1], b.cols[1]),
            v3a(a.cols[2], b.cols[2])
        }
    };
}

static inline 
mat3 m3af(mat3 a, float b)
{
    return m3a(a, make_mat3_1(b));
}

static inline 
mat3 fam3(float b, mat3 a)
{
    return m3a(a, make_mat3_1(b));
}

static inline 
vec3 m3mv3(mat3 a, vec3 b)
{
    return v3a(v3a(v3mf(a.cols[0], b.x), v3mf(a.cols[1], b.y)), v3mf(a.cols[2], b.z));
}

static inline 
mat3 m3m(mat3 a, mat3 b)
{
    return (mat3)
    {
        {
            m3mv3(a, b.cols[0]),
            m3mv3(a, b.cols[1]),
            m3mv3(a, b.cols[2])
        }
    };
}

static inline 
mat3 m3mf(mat3 a, float b)
{
    return (mat3)
    {
        {
            v3mf(a.cols[0], b),
            v3mf(a.cols[1], b),
            v3mf(a.cols[2], b)
        }
    };
}

static inline 
mat3 fmm3(float b, mat3 a)
{
    return m3mf(a, b);
}

static inline 
mat3 m3s(mat3 a, mat3 b)
{
    return (mat3)
    {
        {
            v3s(a.cols[0], b.cols[0]),
            v3s(a.cols[1], b.cols[1]),
            v3s(a.cols[2], b.cols[2])
        }
    };
}

static inline 
mat3 m3sf(mat3 a, float b)
{
    return m3af(a, -b);
}

static inline 
mat3 fsm3(float b, mat3 a)
{
    return m3af(a, -b);
}

static inline 
mat3 m3df(mat3 a, float b)
{
    return m3mf(a, 1.0f/b);
}

static inline 
mat3 m3t(mat3 a)
{
    return make_mat3_9(
            a.d[0][0], a.d[0][1], a.d[0][2],
            a.d[1][0], a.d[1][1], a.d[1][2],
            a.d[2][0], a.d[2][1], a.d[2][2]);
}

static inline 
float det3(mat3 a) 
{ 
    return  + a.d[0][0] * a.d[1][1] * a.d[2][2] 
            + a.d[1][0] * a.d[2][1] * a.d[0][2]
            + a.d[2][0] * a.d[0][1] * a.d[1][2]
            - a.d[2][0] * a.d[1][1] * a.d[0][2]
            - a.d[0][0] * a.d[2][1] * a.d[1][2]
            - a.d[1][0] * a.d[0][1] * a.d[2][2];
}

static inline 
float m3_alg_compl(mat3 m, size_t row, size_t col)
{
    mat2 other;
    for (size_t c = 0, j = 0; c < 3; ++c, ((c == col) ? j : ++j), ++c)
    for (size_t r = 0, i = 0; r < 3; ++r, ((r == row) ? i : ++i), ++r)
    {
        if (c != col && r != row) other.d[j][i] = m.d[c][r];
    }
    return det2(other) * ((row+col)%2 ? 1 : -1);
}

static inline 
mat3 m3i(mat3 a)
{
    mat3 union_matrix = m3t(make_mat3_9(
        m3_alg_compl(a, 0, 0), m3_alg_compl(a, 0, 1), m3_alg_compl(a, 0, 2),
        m3_alg_compl(a, 1, 0), m3_alg_compl(a, 1, 1), m3_alg_compl(a, 1, 2),
        m3_alg_compl(a, 2, 0), m3_alg_compl(a, 2, 1), m3_alg_compl(a, 2, 2)));
    return m3df(union_matrix, det3(a));
}