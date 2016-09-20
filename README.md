# Benchmarking primitives

## Proposal

* [proposal.md](proposal.md) - proposal text

## Reference implementation

Portable implementation. Known limitation: works only for TriviallyCopyable
types.

* [benchmark.h](ref-impl/benchmark.h)

## GCC/Clang implementation

Reference implementation works with recent versions of GCC and Clang. It is
x86_64-specific.

* [benchmark.h](gcc-impl/benchmark.h) - implementation
* [test.cc](gcc-impl/test.cc) - usage
