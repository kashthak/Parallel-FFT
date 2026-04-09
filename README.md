# Lab 3 — Limits of Parallelism

## Introduction

In the previous lab, you explored how parallel execution can lead to speedups, especially for problems that exhibit **data parallelism** — where the same operation is applied independently across different elements of data.

However, you would have also observed an important limitation:

> More threads ≠ proportional speedup

In theory, increasing the number of threads should reduce execution time linearly.  
In practice, this rarely happens.

---

## Objective

In this lab, you will investigate **why parallel programs do not scale linearly**, and where performance bottlenecks arise in real systems.

You will run experiments, observe behavior, and build intuition about performance.

---

## Topics Covered

The following concepts will be explored:

1. **Amdahl’s Law (light overview)**  
   Some parts of a program cannot be parallelized, which limits overall speedup.

2. **Memory Bandwidth Bottlenecks**  
   Many programs are limited not by computation, but by how fast data can be moved in and out of memory.

3. **False Sharing (Introduction)**  
   Threads may interfere with each other even when working on different data, due to shared cache lines.

---

## Key Idea

This lab shifts the focus from:

```text
"How do we make programs parallel?"
```

to:

```text
"Why doesn't parallelism always make programs faster?"
```

---

## Repository Workflow

```bash
git checkout Lab3
git pull origin Lab3
git checkout -b <username>/lab3
```

---

## Compilation

Compile using OpenMP:

```bash
g++ starter_code/scaling_experiments.cpp -O2 -fopenmp -o experiment
```

On macOS (if needed):

```bash
brew install gcc
g++-13 starter_code/scaling_experiments.cpp -O2 -fopenmp -o experiment
```

---

## Running Experiments

Control number of threads using:

```bash
export OMP_NUM_THREADS=1
./experiment
```

Try with:

```text
1, 2, 4, 8 threads
```

Observe how runtime changes.

---

## Experiments Overview

You will perform experiments to understand:

- how performance scales with threads
- differences between compute-heavy and memory-heavy workloads
- effects of false sharing

---

## Deliverables

- completed `scaling_experiments.cpp`
- brief observations (in code comments or a `CONCLUSIONS.md`)

---

## What You Should Learn

After this lab, you should understand:

- why speedup is not linear
- when memory becomes the bottleneck
- how hardware affects parallel performance
- why naive parallelism is not always efficient