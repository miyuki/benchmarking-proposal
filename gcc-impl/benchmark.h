#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <type_traits>

namespace benchmark {

#ifdef __x86_64__
#define MAX_GPR_SIZE    8
#else
#define MAX_GPR_SIZE    4
#endif

template<typename T>
__attribute__((always_inline))
inline std::enable_if_t<sizeof(T) <= MAX_GPR_SIZE>
keep(T&& x) noexcept
{
    asm volatile("" : : "g" (x) : );
}

template<typename T>
__attribute__((always_inline))
inline std::enable_if_t<(sizeof(T) > MAX_GPR_SIZE)>
keep(T&& x) noexcept
{
    asm volatile("" : : "m" (x) : );
}

template<typename T>
__attribute__((always_inline))
inline std::enable_if_t<sizeof(T) <= MAX_GPR_SIZE>
touch(T& x) noexcept
{
    static_assert(!std::is_const<T>(), "touch argument is writeable");
    asm volatile("" : "+r" (x) : : );
}

template<typename T>
__attribute__((always_inline))
inline std::enable_if_t<(sizeof(T) > MAX_GPR_SIZE)>
touch(T& x) noexcept
{
    static_assert(!std::is_const<T>(), "touch argument is writeable");
    asm volatile("" : "+m" (x) : : );
}

}

#endif
