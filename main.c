#include <stdio.h>
#include "mat4.h"
#include "operations.h"
#include "formatted_expression.h"

int main(void)
{
    mat2 m = make_mat2(2.0f);
    vec2 v = make_vec2(3.0f, 4.0f);
    vec2 res = f( m mul v div f(m mul v) );
    printf("%f %f\n", res.x, res.y);
}