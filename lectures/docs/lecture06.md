# Lecture 6: Multicore Programming

- Each cache line is labeled with state:
  - **M:** cache block has been modified. No other caches contain this block in **M** or **S** states
  - **S:** other caches may be sharing this block
  - **I:** cache block is invalid (same as not being there)
- Concurrency platform abstracts processor cores, handles synchronization and communication protocols, and performs load balancing (e.g. Pthreads, OpenMP, Cilk)
- Pthreads: standard API for threading specified by ANSI/IEEE POSIX 1003.1-2008
  - Built as library of functions with "special" non-C semantics
  - Library functions mask protocols involved in interthread coordination
  - Threads communicate through shared memory
  - Thread pools can help avoid cost of creating threads (more than 10,000 cycles)
- OpenMP: specification by an industry consortium (running on top of native threads)
  - Linguistic extensions to C/C++ and Fortran via compiler pragmas
  - Supplies variety of synchronization constructs: barriers, atomic updates, and mutex locks
