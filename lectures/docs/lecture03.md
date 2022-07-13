# Lecture 3: Bit Hacks

- Complementary relationship: `-x = ~x + 1`
- Set `k`th bit: `y = x | (1 << k)`
- Clear `k`th bit: `y = x & ~(1 << k)`
- Toggle `k`th bit: `y = x ^ (1 << k)`
- Extract bit field: `(x & mask) >> shift`
- Set bit field: `x = (x & ~mask) | (y << shift)`
  - Safety sake: `x = (x & ~mask) | ((y << shift) & mask)`
- Least significant bit: `y = x & (-x)`
- No-temp swap: `x ^= y; y ^= x; x ^= y;`
  - Poor performance (cannot exploit good instruction-level parallelism)
- Mispredicted branches (e.g. finding minimum of two integers) empties processor pipeline
- Modern compilers usually better at performing branching optimizations than performance engineers
