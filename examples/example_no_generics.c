#include <stdio.h>

//#define GENERIC_SUPPORTED 1
#include <CimpleMath/all.h>

int main(void)
{
    mat2 m = make_mat2_1(2.0f);
    vec2 v = make_vec2_2(3.0f, 4.0f);
    vec2 res = f( m m2mulv2 v v2div f(m m2mulv2 v) );
    printf("%f %f\n", res.x, res.y);
    mat4 m2 = make_mat4_1(0.5f);
    m2 = m4i(m2);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%f ", m2.d[j][i]);
        }
        printf("\n");
    }
}