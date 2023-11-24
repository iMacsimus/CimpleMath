#pragma once 

#include "vec.h"
#include "mat4.h"

#if __STDC__ && (__STDC_VERSION__ >= 201112L || GENERIC_SUPPORTED)

#define make_vec2(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec2_1 \
    , float(*)[2]: make_vec2_2)(__VA_ARGS__))

#define make_vec3(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec3_1 \
    , float(*)[3]: make_vec3_3)(__VA_ARGS__))

#define make_vec4(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec4_1 \
    , float(*)[4]: make_vec4_4)(__VA_ARGS__))

#define make_mat2(...) \
    (_Generic(&(float[]){__VA_ARGS__} \
    , float(*)[1]: make_mat2_1 \
    , float(*)[4]: make_mat2_4)(__VA_ARGS__))

#define make_mat3(...) \
    (_Generic(&(float[]){__VA_ARGS__} \
    , float(*)[1]: make_mat3_1 \
    , float(*)[9]: make_mat3_9)(__VA_ARGS__))

#define make_mat4(...) \
    (_Generic(&(float[]){__VA_ARGS__} \
    , float(*)[1]: make_mat4_1 \
    , float(*)[16]: make_mat4_16)(__VA_ARGS__))

#define plus , ADD ,
#define minus , SUB ,
#define mul , MUL ,
#define div , DIV ,

static inline
void DO_NOTHING() {}

#define ADD(X, Y) \
    _Generic((X) \
    , vec2: (_Generic((Y) \
        , vec2: v2a \
        , float: v2af \
        , default: DO_NOTHING)) \
    , vec3: (_Generic((Y) \
        , vec3: v3a \
        , float: v3af \
        , default: DO_NOTHING)) \
    , vec4: (_Generic((Y) \
        , vec4: v4a \
        , float: v4af \
        , default: DO_NOTHING)) \
    , mat2: (_Generic((Y) \
        , mat2: m2a \
        , float: m2af \
        , default: DO_NOTHING)) \
    , mat3: (_Generic((Y) \
        , mat3: m3a \
        , float: m3af \
        , default: DO_NOTHING)) \
    , mat4: (_Generic((Y) \
        , mat4: m4a \
        , float: m4af \
        , default: DO_NOTHING)) \
    , float: (_Generic((Y) \
        , vec2: fav2 \
        , vec3: fav3 \
        , vec4: fav4 \
        , mat2: fam2 \
        , mat3: fam3 \
        , mat4: fam4 \
        , default: DO_NOTHING)))(X, Y)

#define SUB(X, Y) \
    _Generic((X) \
    , vec2: (_Generic((Y) \
        , vec2: v2s \
        , float: v2sf \
        , default: DO_NOTHING)) \
    , vec3: (_Generic((Y) \
        , vec3: v3s \
        , float: v3sf \
        , default: DO_NOTHING)) \
    , vec4: (_Generic((Y) \
        , vec4: v4s \
        , float: v4sf \
        , default: DO_NOTHING)) \
    , mat2: (_Generic((Y) \
        , mat2: m2s \
        , float: m2sf \
        , default: DO_NOTHING)) \
    , mat3: (_Generic((Y) \
        , mat3: m3s \
        , float: m3sf \
        , default: DO_NOTHING)) \
    , mat4: (_Generic((Y) \
        , mat4: m4s \
        , float: m4sf \
        , default: DO_NOTHING)) \
    , float: (_Generic((Y) \
        , vec2: fsv2 \
        , vec3: fsv3 \
        , vec4: fsv4 \
        , mat2: fsm2 \
        , mat3: fsm3 \
        , mat4: fsm4 \
        , default: DO_NOTHING)))(X, Y)

#define MUL(X, Y) \
    _Generic((X) \
    , vec2: (_Generic((Y) \
        , vec2: v2m \
        , float: v2mf \
        , default: DO_NOTHING)) \
    , vec3: (_Generic((Y) \
        , vec3: v3m \
        , float: v3mf \
        , default: DO_NOTHING)) \
    , vec4: (_Generic((Y) \
        , vec4: v4m \
        , float: v4mf \
        , default: DO_NOTHING)) \
    , mat2: (_Generic((Y) \
        , mat2: m2m \
        , float: m2mf \
        , vec2: m2mv2 \
        , default: DO_NOTHING)) \
    , mat3: (_Generic((Y) \
        , mat3: m3m \
        , float: m3mf \
        , vec3: m3mv3 \
        , default: DO_NOTHING)) \
    , mat4: (_Generic((Y) \
        , mat4: m4m \
        , float: m4mf \
        , vec4: m4mv4 \
        , default: DO_NOTHING)) \
    , float: (_Generic((Y) \
        , vec2: fmv2 \
        , vec3: fmv3 \
        , vec4: fmv4 \
        , mat2: fmm2 \
        , mat3: fmm3 \
        , mat4: fmm4 \
        , default: DO_NOTHING)))(X, Y)

#define DIV(X, Y) \
    _Generic((X) \
    , vec2: (_Generic((Y) \
        , vec2: v2d \
        , float: v2df \
        , default: DO_NOTHING)) \
    , vec3: (_Generic((Y) \
        , vec3: v3d \
        , float: v3df \
        , default: DO_NOTHING)) \
    , vec4: (_Generic((Y) \
        , vec4: v4d \
        , float: v4df \
        , default: DO_NOTHING)) \
    , mat2: (_Generic((Y) \
        , float: m2df \
        , default: DO_NOTHING)) \
    , mat3: (_Generic((Y) \
        , float: m3df \
        , default: DO_NOTHING)) \
    , mat4: (_Generic((Y) \
        , float: m4df \
        , default: DO_NOTHING)) \
    , float: (_Generic((Y) \
        , vec2: fdv2 \
        , vec3: fdv3 \
        , vec4: fdv4 \
        , default: DO_NOTHING)))(X, Y)

#define transpose(M) \
    (_Generic((M) \
    , mat2: m2t \
    , mat3: m3t \
    , mat4: m4t)(M))

#define invert(M) \
    (_Generic((M) \
    , mat2: m2i \
    , mat3: m3i \
    , mat4: m4i)(M))

#define algebraic_complement(M, i, j) \
    (_Generic((M) \
    , mat3: m3_alg_compl \
    , mat4: m4_alg_compl)(M, i, j))

#endif