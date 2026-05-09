# Lab 3 — Conclusions

## Scaling Behavior

The runtime decreased as the number of threads increased initially.  
For the memory-bound program, the best performance was achieved at 4 threads. Increasing the number of threads further to 8 caused the runtime to increase slightly instead of decreasing.

This shows that parallel speedup is not always linear. Beyond a certain point, adding more threads introduces overhead and memory contention, reducing performance gains.

---

## Memory-Bound vs Compute-Bound

The memory-bound program showed limited scalability because the threads spent significant time waiting for memory access.

The compute-bound program scaled much better. Runtime continued to decrease up to 16 threads because the program performed more computations per memory access, allowing the CPU cores to stay busy.

However, at 20 threads, the runtime increased slightly. This was likely due to hardware limitations, thread scheduling overhead, and contention between threads.

---

## False Sharing

The BAD version in the false sharing experiment was slower even though different threads accessed different indices.

This happened because the variables used by different threads were located in the same cache line. As a result, the CPU cache had to repeatedly synchronize data between threads, causing unnecessary slowdown.

The FIXED version improved performance by separating the variables into different cache lines, reducing cache contention.

---

## Key Takeaways

- Parallelism improves performance only up to a certain limit.
- Memory bandwidth can become a bottleneck in memory-bound programs.
- Compute-bound programs generally scale better with additional threads.
- Hardware effects such as false sharing can significantly reduce performance.
- More threads do not always guarantee faster execution.
