# Lab 4 - Tasks

## Objectives

In this lab, you will implement and compare three common parallel patterns:

- map
- reduction
- scan

---

## Step 1 - Setup

Checkout the lab:

```bash
git checkout Lab4
git pull origin Lab4
git checkout -b <username>/lab4
```

---

## Step 2 - Compile Programs

Compile each file:

```bash
g++ starter_code/map.cpp -O2 -fopenmp -o map
g++ starter_code/reduction.cpp -O2 -fopenmp -o reduction
g++ starter_code/scan.cpp -O2 -fopenmp -o scan
```

(macOS)

```bash
g++-13 starter_code/map.cpp -O2 -fopenmp -o map
g++-13 starter_code/reduction.cpp -O2 -fopenmp -o reduction
g++-13 starter_code/scan.cpp -O2 -fopenmp -o scan
```

(Windows / MinGW)

```bash
g++ starter_code/map.cpp -O2 -fopenmp -o map.exe
g++ starter_code/reduction.cpp -O2 -fopenmp -o reduction.exe
g++ starter_code/scan.cpp -O2 -fopenmp -o scan.exe
```

---

## Step 3 - Run the Starter Code

Before editing anything, run each program:

```bash
./map
./reduction
./scan
```

On Windows:

```bash
./map.exe
./reduction.exe
./scan.exe
```

The starter code is expected to be incorrect at first. Your job is to complete the parallel versions.

---

## Step 4 - Map

Open:

```text
starter_code/map.cpp
```

Complete the function:

```cpp
parallel_map(...)
```

### Requirements

- Use OpenMP to parallelize the element-wise computation.
- Each output element should match the sequential version.
- The final output should say that results match.

---

## Step 5 - Reduction

Open:

```text
starter_code/reduction.cpp
```

Complete the function:

```cpp
parallel_reduction(...)
```

### Requirements

- Use an OpenMP reduction.
- Do not update one shared sum directly from all threads.
- The final result should match the sequential result.

---

## Step 6 - Scan

Open:

```text
starter_code/scan.cpp
```

Complete the function:

```cpp
parallel_scan(...)
```

This is the hardest part of the lab.

A direct `parallel for` on the sequential scan loop is not correct, because each output value depends on earlier values.

Use a staged approach:

1. Divide the array into chunks.
2. Compute a local scan inside each chunk.
3. Store the total for each chunk.
4. Compute offsets from the chunk totals.
5. Add the correct offset to each chunk.

### Requirements

- The final output should match the sequential scan.
- Keep the implementation simple and readable.
- Correctness matters more than speed.

---

## Step 7 - Analysis

Answer briefly:

1. Which pattern was easiest to parallelize, and why?
2. What dependency exists in reduction?
3. Why is a reduction clause needed?
4. Why does scan not work with a simple `parallel for` on the original loop?
5. How did the chunk-based scan change the dependency structure?

---

## Deliverables

Submit:

- completed `starter_code/map.cpp`
- completed `starter_code/reduction.cpp`
- completed `starter_code/scan.cpp`
- short answers to the analysis questions

Your answers may be written as comments in the code or in `answers.md`.

You do not need extensive benchmarking for this lab. A simple sequential vs parallel comparison is enough.
