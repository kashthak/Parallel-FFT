# Lab 4: Parallel Patterns

In Lab 3, you learned that parallel programs do not keep getting faster just because we add more threads. Real hardware has limits: memory bandwidth, cache behavior, synchronization costs, and communication overhead all matter.

Lab 4 shifts the question.

Instead of asking:

> How many threads make this faster?

we now ask:

> What shape does this computation have?

Some computations are naturally easy to parallelize. Some have dependencies, but those dependencies are structured. Some look sequential at first, but can be redesigned into a parallel form.

This lab introduces three core parallel patterns:

1. **Map**
2. **Reduction**
3. **Scan**

These patterns are small, but they appear everywhere in real parallel algorithms.

## Why This Lab Matters

This course is not mainly about OpenMP syntax. It is about how computation scales on real hardware.

So far:

- **Lab 1** taught you how to write and measure C++ programs.
- **Lab 2** showed that parallelism can work, break, and be fixed.
- **Lab 3** showed that parallel speedup has real hardware limits.

Now Lab 4 teaches structure.

Before writing parallel code, we need to understand the computation first. In this lab, the main task is to recognize whether a problem has independent work, structured dependency, or a dependency chain that needs to be reshaped.

## Pattern 1: Map

A **map** applies the same operation independently to every element of an array.

Example:

```cpp
for (int i = 0; i < n; i++) {
    output[i] = input[i] * input[i] + 3.0;
}
```

Each iteration only depends on `input[i]` and writes to `output[i]`.

There is no dependency between different iterations.

That makes map the simplest parallel pattern.

### Key Idea

Map teaches **independence**.

If each element can be computed without needing the result of another element, the loop is usually easy to parallelize.

### What You Will Do

You will implement:

- A sequential map.
- A parallel map using OpenMP.
- A short explanation of why the loop is safe to parallelize.

## Pattern 2: Reduction

A **reduction** combines many values into one result.

Examples:

```cpp
sum = a[0] + a[1] + a[2] + ... + a[n - 1];
```

```cpp
max_value = max(a[0], a[1], a[2], ..., a[n - 1]);
```

```cpp
dot = a[0] * b[0] + a[1] * b[1] + ... + a[n - 1] * b[n - 1];
```

Unlike map, a reduction has a dependency: many operations contribute to the same final value.

If multiple threads update the same variable at the same time, the result can be wrong.

### Key Idea

Reduction teaches **structured dependency**.

The computation is not fully independent, but the dependency has a predictable shape. Partial results can be computed separately and then combined.

This only works safely when the combining operation is associative, or close enough for the purpose of the program.

For example:

```cpp
(a + b) + c == a + (b + c)
```

Mathematically, addition is associative. In floating-point arithmetic, the result may differ slightly because of rounding, but the pattern is still widely used.

### What You Will Do

You will implement:

- A sequential reduction.
- A parallel reduction using OpenMP.
- A short explanation of what dependency exists.
- A short explanation of why the reduction version is safe.

## Pattern 3: Scan

A **scan**, also called a **prefix sum**, computes all running totals of an array.

Example input:

```text
[3, 1, 4, 2]
```

Inclusive prefix sum:

```text
[3, 4, 8, 10]
```

Each output element depends on all previous input elements:

```cpp
output[0] = input[0];
output[1] = input[0] + input[1];
output[2] = input[0] + input[1] + input[2];
output[3] = input[0] + input[1] + input[2] + input[3];
```

At first, this looks completely sequential.

```cpp
for (int i = 1; i < n; i++) {
    output[i] = output[i - 1] + input[i];
}
```

The value at `output[i]` depends directly on `output[i - 1]`.

That means we cannot simply add `#pragma omp parallel for` and expect the program to be correct.

### Key Idea

Scan teaches **restructuring**.

Some computations are not parallelized by wrapping the existing loop in a parallel directive. Instead, the algorithm must be reshaped.

Scan is the bridge between simple loop parallelism and more advanced algorithms like FFT.

### What You Will Do

You will implement:

- A sequential scan.
- A guided parallel scan approach.
- A short explanation of why the direct loop cannot be parallelized safely.
- A short explanation of how the staged version changes the dependency structure.

## Build and Run

Use C++ with OpenMP enabled.

Example build commands:

```bash
g++ -O2 -fopenmp starter_code/map.cpp -o map
g++ -O2 -fopenmp starter_code/reduction.cpp -o reduction
g++ -O2 -fopenmp starter_code/scan.cpp -o scan
```

Example run commands:

```bash
./map
./reduction
./scan
```

On Windows with MinGW, the commands may look similar:

```bash
g++ -O2 -fopenmp starter_code/map.cpp -o map.exe
g++ -O2 -fopenmp starter_code/reduction.cpp -o reduction.exe
g++ -O2 -fopenmp starter_code/scan.cpp -o scan.exe
```

Then run:

```bash
./map.exe
./reduction.exe
./scan.exe
```

## Timing Expectations

You may measure runtime, but this is not mainly a thread-scaling lab.

Do not spend most of your effort trying many thread counts.

For each pattern, it is enough to compare:

- Sequential version.
- Parallel version.
- Correctness of output.
- Dependency structure.

The timing should support your thinking, not replace it.

## Correctness First

Every program should check that the sequential and parallel results match.

For integer results, exact equality is usually expected.

For floating-point results, small differences may occur because parallel reductions can combine values in a different order.

Use a small tolerance when comparing floating-point values.

Example:

```cpp
double tolerance = 1e-6;
```

## Final Takeaway

Parallel programming is not just about adding threads.

Good parallel programming starts by recognizing the shape of the computation.

In this lab:

- Map showed independent work.
- Reduction showed structured dependency.
- Scan showed that some algorithms need to be reshaped.

These three patterns will keep appearing as the course moves toward divide-and-conquer algorithms and FFT.
