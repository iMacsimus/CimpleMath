#pragma once

typedef union 
{
    struct { float x; float y; };
    float d[2];
} vec2;

typedef union 
{
    struct { float x; float y; float z; };
    float d[3];
} vec3;

typedef union 
{
    struct { float x; float y; float z; float w; };
    float d[4];
} vec4;

static inline
vec2 make_vec2_1(float value) { return (vec2){{value, value}}; }
static inline 
vec2 make_vec2_2(float x, float y) { return (vec2){{x, y}}; }

#define make_vec2(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec2_1 \
    , float(*)[2]: make_vec2_2)(__VA_ARGS__))

static inline
vec3 make_vec3_1(float value) { return (vec3){{value, value, value}}; }
static inline
vec3 make_vec3_3(float x, float y, float z) { return (vec3){{x, y, z}}; }

#define make_vec3(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec3_1 \
    , float(*)[3]: make_vec3_3)(__VA_ARGS__))

static inline
vec4 make_vec4_1(float value) { return (vec4){{value, value, value, value}}; }
static inline 
vec4 make_vec4_4(float x, float y, float z, float w) { return (vec4){{x, y, z, w}}; }

#define make_vec4(...) \
    (_Generic( &(float[]){__VA_ARGS__} \
    , float(*)[1]: make_vec4_1 \
    , float(*)[4]: make_vec4_4)(__VA_ARGS__))

//////////////////////////////////////////////////////////////////////////////

static inline 
vec2 v2a(vec2 a, vec2 b) { return (vec2){{a.x+b.x, a.y+b.y}}; }
static inline 
vec2 v2af(vec2 a, float scalar) { return (vec2){{a.x+scalar, a.y+scalar}}; }
static inline 
vec2 fav2(float scalar, vec2 a) { return (vec2){{a.x+scalar, a.y+scalar}}; }

static inline 
vec2 v2m(vec2 a, vec2 b) { return (vec2){{a.x*b.x, a.y*b.y}}; }
static inline
vec2 v2mf(vec2 a, float scalar) { return (vec2){{a.x*scalar, a.y*scalar}}; }
static inline
vec2 fmv2(float scalar, vec2 a) { return (vec2){{a.x*scalar, a.y*scalar}}; }

static inline 
vec2 v2d(vec2 a, vec2 b) { return (vec2){{a.x/b.x, a.y/b.y}}; }
static inline
vec2 v2df(vec2 a, float scalar) { return (vec2){{a.x/scalar, a.y/scalar}}; }
static inline
vec2 fdv2(float scalar, vec2 a) { return (vec2){{scalar/a.x, scalar/a.y}}; }

static inline
vec2 v2s(vec2 a, vec2 b) { return (vec2){{a.x-b.x, a.y-b.y}}; }
static inline
vec2 v2sf(vec2 a, float scalar) { return (vec2){{a.x-scalar, a.y-scalar}}; }
static inline
vec2 fsv2(float scalar, vec2 a) { return (vec2){{scalar-a.x, scalar-a.y}}; }

//////////////////////////////////////////////////////////////////////////////

static inline 
vec3 v3a(vec3 a, vec3 b) { return (vec3){{a.x+b.x, a.y+b.y, a.z+b.z}}; }
static inline 
vec3 v3af(vec3 a, float scalar) { return (vec3){{a.x+scalar, a.y+scalar, a.z+scalar}}; }
static inline 
vec3 fav3(float scalar, vec3 a) { return (vec3){{a.x+scalar, a.y+scalar, a.z+scalar}}; }

static inline 
vec3 v3m(vec3 a, vec3 b) { return (vec3){{a.x*b.x, a.y*b.y, a.z*b.z}}; }
static inline
vec3 v3mf(vec3 a, float scalar) { return (vec3){{a.x*scalar, a.y*scalar, a.z*scalar}}; }
static inline
vec3 fmv3(float scalar, vec3 a) { return (vec3){{a.x*scalar, a.y*scalar, a.z*scalar}}; }

static inline 
vec3 v3d(vec3 a, vec3 b) { return (vec3){{a.x/b.x, a.y/b.y, a.z/b.z}}; }
static inline
vec3 v3df(vec3 a, float scalar) { return (vec3){{a.x/scalar, a.y/scalar, a.z/scalar}}; }
static inline
vec3 fdv3(float scalar, vec3 a) { return (vec3){{scalar/a.x, scalar/a.y, scalar/a.z}}; }

static inline
vec3 v3s(vec3 a, vec3 b) { return (vec3){{a.x-b.x, a.y-b.y, a.z-b.z}}; }
static inline
vec3 v3sf(vec3 a, float scalar) { return (vec3){{a.x-scalar, a.y-scalar, a.z-scalar}}; }
static inline
vec3 fsv3(float scalar, vec3 a) { return (vec3){{scalar-a.x, scalar-a.y, scalar-a.z}}; }

//////////////////////////////////////////////////////////////////////////////

static inline 
vec4 v4a(vec4 a, vec4 b) { return (vec4){{a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w}}; }
static inline 
vec4 v4af(vec4 a, float scalar) { return (vec4){{a.x+scalar, a.y+scalar, a.z+scalar, a.w+scalar}}; }
static inline 
vec4 fav4(float scalar, vec4 a) { return (vec4){{a.x+scalar, a.y+scalar, a.z+scalar, a.w+scalar}}; }

static inline 
vec4 v4m(vec4 a, vec4 b) { return (vec4){{a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w}}; }
static inline
vec4 v4mf(vec4 a, float scalar) { return (vec4){{a.x*scalar, a.y*scalar, a.z*scalar, a.w*scalar}}; }
static inline
vec4 fmv4(float scalar, vec4 a) { return (vec4){{a.x*scalar, a.y*scalar, a.z*scalar, a.w*scalar}}; }

static inline 
vec4 v4d(vec4 a, vec4 b) { return (vec4){{a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w}}; }
static inline
vec4 v4df(vec4 a, float scalar) { return (vec4){{a.x/scalar, a.y/scalar, a.z/scalar, a.w/scalar}}; }
static inline
vec4 fdv4(float scalar, vec4 a) { return (vec4){{scalar/a.x, scalar/a.y, scalar/a.z, scalar/a.w}}; }

static inline
vec4 v4s(vec4 a, vec4 b) { return (vec4){{a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w}}; }
static inline
vec4 v4sf(vec4 a, float scalar) { return (vec4){{a.x-scalar, a.y-scalar, a.z-scalar, a.w-scalar}}; }
static inline
vec4 fsv4(float scalar, vec4 a) { return (vec4){{scalar-a.x, scalar-a.y, scalar-a.z, scalar-a.w}}; }