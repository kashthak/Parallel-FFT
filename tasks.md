# Lab 3 — Limits of Parallelism

## Objectives

In this lab, you will investigate why parallel programs do not always scale linearly.

You will explore:

- non-linear speedup
- memory vs compute bottlenecks
- false sharing

Run each experiment multiple times and focus on trends, not exact numbers.
---

## Step 1 — Setup

Checkout the lab:

```bash
git checkout Lab3
git pull origin Lab3
git checkout -b <username>/lab3
```

---

## Step 2 — Compile Programs

Compile each file:

```bash
g++ memory_bound.cpp -O2 -fopenmp -o memory_bound
g++ compute_bound.cpp -O2 -fopenmp -o compute_bound
g++ false_sharing.cpp -O2 -fopenmp -o false_sharing
```

(macOS)

```bash
g++-13 memory_bound.cpp -O2 -fopenmp -o memory_bound
g++-13 compute_bound.cpp -O2 -fopenmp -o compute_bound
g++-13 false_sharing.cpp -O2 -fopenmp -o false_sharing
```

---

## Step 3 — Scaling Behavior

Open `memory_bound.cpp`.

Change:

```cpp
#define NUM_THREADS X
```

Test with:

```
1, 2, 4, 8
```

Run each time:

```bash
./memory_bound
```

### Observe

- How does runtime change as threads increase?
- Does doubling threads halve the runtime?

---

## Step 4 — Memory vs Compute

Run both programs with the same thread counts:

```bash
./memory_bound
./compute_bound
```

### Observe

- Which program scales better?
- Which one benefits more from additional threads?

---

## Step 5 — False Sharing

Run:

```bash
./false_sharing
```

This runs two versions:
- BAD (false sharing)
- FIXED

### Observe

- Which version is faster?
- Why does the slower version perform worse even though threads use different indices?

---

## Step 6 — Analysis

Answer briefly:

1. Why does increasing threads not give linear speedup?
2. Which program is limited by memory?
3. Which program is limited by computation?
4. What is false sharing in your own words?
5. How was false sharing fixed?

---

## Deliverables

- Answers (as comments or a `README.md`)
- No code changes required

---

## Key Takeaway

Parallelism is limited by:

- non-parallel portions of code
- memory bandwidth
- hardware effects such as false sharing