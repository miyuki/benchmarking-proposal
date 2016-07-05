#include <array>
#include "benchmark.h"

void test_int()
{
    int x = 2;
    int y = 2;
    benchmark::touch(x);
    benchmark::touch(y);
    int z = x + y;
    benchmark::keep(z);
}

void test_array()
{
    constexpr int N = 10;
    std::array<int, N> x;
    std::array<int, N> y;
    for (auto *p : { &x, &y })
        for (int &elem : *p)
            elem = 2;
    benchmark::touch(x);
    benchmark::touch(y);
    std::array<int, N> z;
    for (int i = 0; i < N; i++)
        z[i] = x[i] + y[i];
    benchmark::keep(z);
}

void test_longlong()
{
    long long x = 2;
    long long y = 2;
    benchmark::touch(x);
    benchmark::touch(y);
    long long z = x + y;
    benchmark::keep(z);
}

class int_wrapper
{
public:
    explicit int_wrapper(int value) : value_(value) { }
    int get() const { return value_; }
private:
    int value_;
};

static int_wrapper operator+(const int_wrapper& a, const int_wrapper& b)
{
    return int_wrapper(a.get() + b.get());
}

void test_class_type()
{
    int_wrapper x(2);
    int_wrapper y(2);
    benchmark::touch(x);
    benchmark::touch(y);
    int_wrapper z(x + y);
    benchmark::keep(z);
}

void check_dce()
{
    int x = 2;
    int y = 2;
    int z = x + y;
    (void)z;
}

void check_const_fold()
{
    int x = 2;
    int y = 2;
    int z = x + y;
    benchmark::keep(z);
}

