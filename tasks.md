# Lab 2 — Parallel Programming with OpenMP

## Objectives

In this lab you will:

- introduce parallel programming using OpenMP
- parallelize loops from Lab 1
- observe performance improvements
- understand race conditions and reductions

---

## Step 1 — Checkout Lab 2

```bash
git checkout Lab2
git pull origin Lab2
```

Create your working branch:

```bash
git checkout -b <username>_lab2
```

---

## Step 2 — Compile with OpenMP

Compile using:

```bash
g++ starter_code/vector_operations.cpp -O2 -fopenmp -o vector_ops
```

If this fails on macOS:

```bash
brew install gcc
g++-13 starter_code/vector_operations.cpp -O2 -fopenmp -o vector_ops
```

---

## Step 3 — Run the Baseline

Run the program:

```bash
./vector_ops
```

Observe and note the runtime.

---

## Step 4 — Parallelize `scale_vector`

Open `starter_code/vector_operations.cpp`.

Add the following line **above the loop** in `scale_vector`:

```cpp
#pragma omp parallel for
```

Recompile and run:

```bash
g++ starter_code/vector_operations.cpp -O2 -fopenmp -o vector_ops
./vector_ops
```

Observe the change in runtime.

---

## Step 5 — Parallelize `sum_vector`

Add the following line above the loop in `sum_vector`:

```cpp
#pragma omp parallel for
```

Recompile and run.

You may observe:

- incorrect output
- inconsistent results across runs

---

## Step 6 — Fix Using Reduction

Replace the parallel directive with:

```cpp
#pragma omp parallel for reduction(+ : sum)
```

Recompile and run again.

Verify:

- output is now correct
- runtime is still improved

---

## Step 7 — Control Number of Threads

Set the number of threads.

Linux / macOS:

```bash
export OMP_NUM_THREADS=1
./vector_ops
```

```bash
export OMP_NUM_THREADS=2
./vector_ops
```

```bash
export OMP_NUM_THREADS=4
./vector_ops
```

```bash
export OMP_NUM_THREADS=8
./vector_ops
```

Observe how runtime changes.

---

## Step 8 — Observations

Answer briefly:

- Did performance improve after parallelization?
- Was the speedup linear?
- Why did the naive parallel sum fail?
- What limits the speedup?

You may include answers as comments in the code or a `README.md`.

---

## Step 9 — Commit Your Work

```bash
git add starter_code/vector_operations.cpp
git commit -m "Lab2: OpenMP parallelization"
git push origin <username>/lab2
```

---

## Deliverables

- updated `starter_code/vector_operations.cpp`
- observations (comments or README)

---

## What You Learned

- parallel loops using OpenMP
- race conditions in shared memory
- reduction for correctness
- basic performance scaling