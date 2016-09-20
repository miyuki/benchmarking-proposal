#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <cstring>

namespace benchmark {

template<typename T>
inline void keep(T&& x) noexcept
{
    volatile char dest;
    for (std::size_t pos = 0; pos < sizeof(T); ++pos)
        dest = reinterpret_cast<const char *>(std::addressof(x))[pos];
    (void)dest;
}

template<typename T>
inline void touch(T& x) noexcept
{
    volatile char dest;
    char buf[sizeof(T)];
    for (std::size_t pos = 0; pos < sizeof(T); ++pos) {
        dest = reinterpret_cast<const char *>(std::addressof(x))[pos];
        buf[pos] = dest;
    }
    std::memcpy(&x, buf, sizeof(T));
}

}

#endif
