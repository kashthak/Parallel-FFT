# Lab 4 - Learning Resources

This lab is about recognizing the **shape of computation** before trying to parallelize it.

You do not need to read every page fully. Use these resources to build intuition for:

- map: independent work
- reduction: structured dependency
- scan: dependency that needs restructuring

Estimated time: **20-30 minutes**

---

## Required

## 1. Prefix Sum / Scan

Read:

https://en.algorithmica.org/hpc/algorithms/prefix/

Focus only on:

- the definition of prefix sum / scan
- the small sequential prefix sum loop
- the idea that each output depends on earlier values
- the block-based intuition shown near the beginning

You can skip:

- SIMD details
- assembly code
- low-level CPU optimization sections

---

## 2. OpenMP Reduction Clause

Read:

https://hpc-tutorials.llnl.gov/openmp/reduction_clause/

Focus only on:

- what `reduction` means
- the C/C++ syntax: `reduction(+:result)`
- the dot product example
- why each thread needs its own private partial result

You can skip:

- Fortran examples
- the long restrictions table
- advanced clause details

---

## 3. Reduction Concept

Read:

https://theartofhpc.com/pcse/omp-reduction.html

Focus only on:

- why updating one shared variable directly causes problems
- why reductions are better than using a critical section for every update
- the idea of combining partial results

You can skip:

- MPI comparisons
- advanced OpenMP features
- performance details that go beyond the basic reduction idea

---

## Recommended Videos

## 4. Parallel Prefix Sum Visualization

Watch:

https://www.youtube.com/watch?v=1G8CZioSjnM

Focus only on:

- how prefix sum is computed in stages
- why the work is not just one simple `parallel for`
- the visual idea of values being combined and passed through levels

You can stop once the video moves into CUDA-specific optimization details.

---

## 5. Parallel Reduction Visualization

Watch:

https://www.youtube.com/watch?v=prLb1MbAm8M

Focus only on:

- how values are grouped and combined
- the tree-like shape of a reduction
- why combining partial results is different from every thread writing to one variable

---

## Optional

## 6. Scan in Real Systems

Read only if you are curious:

https://developer.nvidia.com/gpugems/gpugems3/part-vi-gpu-computing/chapter-39-parallel-prefix-sum-scan-cuda

Focus only on:

- Section 39.1 Introduction
- the examples showing what scan produces
- why scan is considered an important parallel primitive

You can skip:

- CUDA code
- GPU memory optimization
- bank conflicts
- performance tuning sections
