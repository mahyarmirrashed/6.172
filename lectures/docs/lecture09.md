# Lecture 9: What Compilers Can and Cannot Do

- Compilers transform data structures to store as much as possible in registers
- Function inlining and additional transformations can eliminate cost of function abstraction
- Use link-time optimization (LTO) to enable whole-program optimization
- `restrict` keyword allows compiler to assume address calculations based on pointer will not alias those based on other pointers
- `const` keyword indicates that addresses from particular pointer will only be read
- Annotate function to indicate they do not modify any memory via `__attribute__((const))`
- Use signed integer types unless absolutely need unsigned type (allows vectorization on certain loops)
- Take a look at compiler reports and help out compiler if possible
- Compiler optimizations can be fragile because compiler must act conservatively
