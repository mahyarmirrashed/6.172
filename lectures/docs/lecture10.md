# Lecture 10: Measurement and Timing

- DVFS: technique to reduce power by adjusting clock frequency and supply voltage to transistors
  - Reduce operating frequency if chip is too hot or to conserve (especially battery) power
  - Wreaks havoc on performance measurements
- If possible to reduce variability, compensate for systematic and random measurement errors
- Quiescing system tips:
  - Shut down daemons and cron jobs, disconnect network, don't touch mouse, don't run on core 0 (for serial jobs), turn off hyperthreading, turn off DVFS, turn off turbo boosting, pin workers to cores
- Changing order in which object files appear in linker can have larger effect than going between `-O2` to `-O3`
- Aligned code is more likely to avoid performance anomalies but can be slower
  - `-align-all-functions=<uint>`: force function alignment
  - `align-all-blocks=<uint>`: force function block alignment
  - `align-all-nofallthru-blocks=<uint>`: force all blocks with no fall-through predecessors (don't add nops) alignment
- Executable's name ends up in an environment variable (and on call stack)
  - Data access slows when crossing page boundaries (name length affects stack alignment)
- Ways to measure programs:
  - Externally (e.g. `/usr/bin/time`)
    - `real` is wall-clock time, `user`: time spent in user-mode code, `sys` amount of time spent in kernel within process
  - Instrument program (include timing call in program)
  - Interrupt program (e.g. `gprof`)
  - Simulate program (e.g. `cachegrind`)
- Basic performance-engineering workflow
  1. Measure performance of program $A$
  2. Make change to program $A$ to make a hopefully faster Program $A'$
  3. Measure performance of $A'$
  4. If $A'$ beats $A$, set $A = A'$
  5. If $A$ not fast enough, go back to step 2
- Use geometric mean to compare trials of two programs (invertible)
- Use P-value to compare two programs when measurements are noisy
