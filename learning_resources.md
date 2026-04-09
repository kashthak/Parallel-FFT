# Lab 3 — Learning Resources

This lab focuses on understanding **why parallel programs do not scale linearly**.

You are not expected to learn detailed hardware architecture.  
Instead, focus on building intuition through simple ideas and observations.

Estimated time: **30–45 minutes**

---

## 1. Amdahl’s Law (Limits of Parallelism)

Watch:

https://www.youtube.com/watch?v=tEmJvzXQeXU

Focus on:

- what portion of a program cannot be parallelized
- why this limits total speedup
- why adding more threads gives diminishing returns

Key idea:

```
If part of the program is serial, it limits overall speedup.
```

---

## 2. Memory Bottleneck (Intuition)

Watch:

https://www.youtube.com/watch?v=IAkj32VPcUE

Focus on:

- how the CPU processes data
- why data needs to be fetched before computation
- the difference between computation and data access

Key idea:

```
Sometimes programs are not slow because of computation,
but because they are waiting for data from memory.
```

You will observe this directly in the lab.

---

## 3. False Sharing (After Experiment)

Watch:

https://www.youtube.com/watch?v=3gAQ7LvFJSE

Focus on:

- why threads interfere even when using different variables
- what “sharing” means at the hardware level
- how changing memory layout improves performance

Key idea:

```
Variables that are close in memory can still interfere,
even if they are logically independent.
```

---

## 4. What You Should Understand

After going through the resources and experiments, you should understand:

- why speedup is not linear
- the difference between compute-bound and memory-bound programs
- how memory access can limit performance
- what false sharing is and how it affects performance