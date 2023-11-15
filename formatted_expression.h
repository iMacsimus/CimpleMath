#pragma once

#define ARG23(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, ...) a23
#define OPERATIONS_COUNT(...) ARG23(dummy, ## __VA_ARGS__, 10, 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0)

#define fhelper1(cnt, ...) fhelper2(cnt, __VA_ARGS__)
#define fhelper2(cnt, ...) ff##cnt(__VA_ARGS__)
#define f(X) fhelper1(OPERATIONS_COUNT(X), X)

#define ff1(X, operation, Y) operation(X, Y)
#define ff2(X, first, Y, second, ...) ff1(ff1(X, first, Y), second, __VA_ARGS__)
#define ff3(X, first, Y, second, ...) ff2(ff1(X, first, Y), second, __VA_ARGS__)
#define ff4(X, first, Y, second, ...) ff3(ff1(X, first, Y), second, __VA_ARGS__)
#define ff5(X, first, Y, second, ...) ff4(ff1(X, first, Y), second, __VA_ARGS__)
#define ff6(X, first, Y, second, ...) ff5(ff1(X, first, Y), second, __VA_ARGS__)
#define ff7(X, first, Y, second, ...) ff6(ff1(X, first, Y), second, __VA_ARGS__)
#define ff8(X, first, Y, second, ...) ff7(ff1(X, first, Y), second, __VA_ARGS__)
#define ff9(X, first, Y, second, ...) ff8(ff1(X, first, Y), second, __VA_ARGS__)
#define ff10(X, first, Y, second, ...) ff9(ff1(X, first, Y), second, __VA_ARGS__)