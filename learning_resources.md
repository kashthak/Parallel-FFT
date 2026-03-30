# OpenMP Learning Resources

This lab introduces **OpenMP**, a simple way to write parallel programs in C++.

You only need a **small subset of OpenMP** for this lab.

Estimated time: **30–60 minutes**

    (Read the entire markdown the FIRST time)
---

## 1. What Problem Does OpenMP Solve?

Modern CPUs have multiple cores.

A normal program runs:

- one instruction at a time
- on a single core

This limits performance.

OpenMP allows you to:

- split work across multiple threads
- use multiple CPU cores
- speed up computation

OpenMP works by adding simple directives like:

```cpp
#pragma omp parallel for
```

This tells the compiler to run the loop in parallel.

OpenMP is a **shared-memory model**, meaning all threads can access the same memory.

---

## 2. Parallel Loops (Core Idea)

Basic usage:

```cpp
#pragma omp parallel for
for (int i = 0; i < N; i++)
{
    // work
}
```

What happens:

- iterations are divided among threads
- each thread executes a subset
- execution happens concurrently

---

## 3. Race Conditions (Very Important)

A race condition occurs when:

- multiple threads access the same variable
- at least one thread modifies it
- there is no synchronization

Example:

```cpp
sum += v[i];
```

Why this is a problem:

- multiple threads update `sum` at the same time
- updates overlap and overwrite each other
- result becomes incorrect

Key idea:

> The result depends on execution order, which is unpredictable in parallel programs.

---

## 4. Reduction (Fixing Race Conditions)

OpenMP provides a clean solution:

```cpp
#pragma omp parallel for reduction(+ : sum)
```

What this does:

- each thread gets its own private copy of `sum`
- threads compute independently
- results are combined at the end

This ensures:

- correctness
- no race conditions

---

## 5. Controlling Number of Threads

You can control how many threads are used.

### Using environment variable (Linux / macOS)

```bash
export OMP_NUM_THREADS=4
```

### Inside code

```cpp
#include <omp.h>

omp_set_num_threads(4);
```

---

## 6. Compilation

Compile with OpenMP enabled:

```bash
g++ file.cpp -O2 -fopenmp -o program
```

---

## 7. Video Resource (Recommended)

Watch:

Intro to Parallel Programming: 
    https://www.youtube.com/watch?v=qLFB376KZPc. 


Race conditions:
    https://www.youtube.com/watch?v=7ENFeb-J75k. 

Reduction:
    http://youtube.com/watch?v=gW9EiEQAkDU. 


Slightly advanced, but well documented:
https://hpc-tutorials.llnl.gov/openmp/parallel_construct/#purpose. 

http://hpc-tutorials.llnl.gov/openmp/reduction_clause/. 

https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG. 


    (Don't worry if they all don't make sense or you can't follow along, we just want to grasp the basic concepts)

Focus on:

- what parallel programming is
- how `parallel for` works
- why race conditions occur
- how reduction fixes them

---

## 8. What You Should Understand After This

You are ready for the lab if you understand:

- how to parallelize a loop using `#pragma omp parallel for`
- what a race condition is
- why `sum += ...` fails in parallel
- how reduction fixes it