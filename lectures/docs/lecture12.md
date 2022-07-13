# Lecture 12: Parallel Storage Allocation

- Strategy 1: Global Heap
  - Default C allocator, slow (acquiring lock is like L2-cache access), contention inhibits scalability
- Strategy 2: Local Heaps
  - Fast (no synchronization), suffers from memory drift (blocks allocated on one thread freed by another)
- Strategy 3: Local Ownership
  - Fast alocation and free of local objects, free requires synchronization, resilience to false sharing
- Allocators can induce false sharing:
  - Actively: allocator satisfies memory requests using same cache block
  - Passively: program passes objects lying on same cache line to different threads
- Hoard allocator involved orgnaizing memory into large superblocks of size $S$
  - Only superblocks are moved between local heaps and global heap
