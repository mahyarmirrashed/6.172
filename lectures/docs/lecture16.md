# Lecture 16: Non-Deterministic Parallel Programming

- Deterministic programs always behave same way (advantage is debugging)
- Never write non-deterministic parallel programs (extremely hard to debug properly)
  - Otherwise, devise test strategies to manage non-determinism
- Atomic instructions: sequence of instructions never visible in partial execution
- Critical section: piece of code that must not be accessed by two or more threads concurrently (mutual exclusion)
- Locks in code are inherently non-deterministic (to avoid data race)
- Benign races (e.g. identifying sets of digits in array using booleans)
- Important mutex properties:
  - Yielding: returns control to operating system
  - Spinning: wastes processor cycles while blocked
  - Reentrant: allows thread to reacquire lock it already holds
  - Nonreentrant: deadlocks when thread already holding lock attempts to acquire it
  - Fair: puts all blocked threads on FIFO queue
  - Unfair: lets any waiting thread to acquire lock
- Randomized competitive mutex algorithms achieve ratio of $e/(e-1)\approx 1.58$
- Holding multiple locks is dangerous (should be avoided by design)
- Deadlocking conditions:
  1. Mutual exclusion: thread claims exclusive control over held resources
  2. Non-preemption: thread does not release held resources until use is completed
  3. Circular waiting: cycle of threads exist in which each thread is blocked waiting for resources held by next thread in cycle
