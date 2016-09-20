#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <cstring>

namespace benchmark {

template<typename T>
inline void keep(T&& x) noexcept
{
    volatile char buf[sizeof(T)];
    std::memcpy(&buf, &x, sizeof(T));
}

template<typename T>
inline void touch(T& x) noexcept
{
    volatile char buf[sizeof(T)];
    std::memcpy(&buf, &x, sizeof(T));
    std::memcpy(&x, &buf, sizeof(T));
}

}

#endif
