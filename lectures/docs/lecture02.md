# Lecture 2: Bentley Rules for Optimizing Work

- Program work (on a given input) is sum total of all operations executed
- Reducing program work does not automatically reduce running time (due to complex nature of computer hardwware)
  - Serves as good heuristic for reducing overall runtime
- New "Bentley" Rules
  - Data structures: packing and encoding, augmentation, precomputation, compile-time initialization, caching, lazy evaluation, sparsity
  - Loops: hosting, sentinels, loop unrolling, loop fusion, eliminating wasted iterations
  - Logic: constant folding and propagation, common-subexpression elimination, algebraic identities, short-circuiting, ordering tests, creating fast paths, combining tests
  - Functions: inling, tail-recursion elimination, coarsening recursion
- Packing: store moer than one data value in machine words
  ```c
  typedef struct {
    int year: 13;
    int month: 4;
    int day: 5;
  } date_t;
  ```
- Encoding: convert data values into representation requiring fewer bits
- Augmentation: add information to data structures to make common operations do less work (e.g. augment singly linked list with pointer to tail for fast appends)
- Precomputation: perform calculations in advance rather than at "mission-critical" times
- Compile-time initialization: store values of constants during compilation (saves work at execution time)
- Caching: store results that have been accessed recently to avoid re-computation (depends on data statistics, otherwise slower)
- Sparsity: avoid storing and computing on zeroes (depends on data statistics)
- Constant folding and propagation: evalue constant expressions and substitute results into further expressions, all during compilation (with a sufficiently high optimization level)
- Common-subexpression elimination: avoid computing same expression multiple times by evaluating and storing result for later use
- Exploiting algebraic identities: replace expensive algebraic expressions with (rough or exact) equivalents requiring less work
- Short-circuiting: stop evaluating series of tests immediately after answer is known
  - `&&` and `||` are short-circuiting logical operators
- Ordering tests: sequence logic tests to perform those are more/less likely
- Fast paths: computation might be trivial if certain properties are known
- Combining tests: replace sequence of tests with one test or switch
- Hosting: avoid recomputing loop-invariant code through body of loop (e.g. constant factor computed once outside loop)
- Sentinels: special dummy values placed in data structures to simplify logic of boundary conditions and loop-exit tests
- Loop unrolling: combining several consecutive iterations of loop into single iteration, to reduce number of times that loop controlling instructions must be executed (e.g. `++i`)
  - Lower number of instructions in loop control code
  - Enables more compiler optimizations
  - Too much can cause poor use of instruction cache (compilers probably know best)
- Loop fusion (jamming): combine multiple loops over same index range into single loop body (avoid overhead of loop control)
- Eliminating wasted iterations: modify loop bounds to avoid executing loop iterations over essentially empty loop bodies (e.g. `j < n` vs `j < i`)
- Inlining: avoid overhead of function call by replacing call to function with function body itself (can be just as efficient as preprocessor macros)
- Tail-recursion elimination: replace recursive call occuring as last step of function with branch to save function-call overhead
- Coarsening recursion: increase size of base case and handle with more efficient code avoiding function-call overhead
- Compiler automates many low-level optimizations
