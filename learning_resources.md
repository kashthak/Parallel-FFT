# Learning Resources

This course assumes **no prior experience with Git** and only **basic familiarity with programming**.

You will learn just enough C++ and Git to complete the labs.

Estimated preparation time: **2–4 hours**.

---

# 1. C++ Learning Resources

Primary reference:

LearnCpp

https://www.learncpp.com/

This is one of the best written beginner C++ tutorials.

You **do not need to read the entire website**.
Only the sections listed below.

---

# Required C++ Topics

These topics are required before starting Lab 1.

---

## 1.1 Basic Program Structure

Learn how a C++ program starts and how `main()` works.

Read:

https://www.learncpp.com/cpp-tutorial/introduction-to-cpp/

Example program:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello world\n";
}
```

---

## 1.2 Variables and Data Types

Understand variables and basic numeric types.

Read:

https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/

https://www.learncpp.com/cpp-tutorial/fundamental-data-types/

Types used in this course:

```
int
float
double
```

---

## 1.3 Functions

Programs should be organized using functions.

Read:

https://www.learncpp.com/cpp-tutorial/introduction-to-functions/

Example:

```cpp
float square(float x)
{
    return x * x;
}
```

---

## 1.4 Loops

Loops are critical for numerical programs.

Read:

https://www.learncpp.com/cpp-tutorial/for-statements/

Example:

```cpp
for (int i = 0; i < n; i++)
{
    sum += data[i];
}
```

Later labs will **parallelize loops like this**.

---

## 1.5 Vectors (Important)

Vectors are the primary data structure used in this course.

Read:

https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdvector/

Example:

```cpp
std::vector<float> data(1000);
```

Vectors store elements **contiguously in memory**.

Memory layout:

```
|d0|d1|d2|d3|d4|
```

This layout is important for performance.

---

## 1.6 Passing by Reference

Large objects should be passed by reference to avoid copying.

Read:

https://www.learncpp.com/cpp-tutorial/pass-by-reference/

Example:

```cpp
void fill_vector(std::vector<float>& v)
```

The `&` allows the function to modify the original vector.

---

## 1.7 Generating Random Numbers

Lab 1 fills vectors with random values.

Read:

https://www.learncpp.com/cpp-tutorial/generating-random-numbers/

---

## 1.8 Measuring Runtime

Later labs analyze program performance.

C++ timing reference:

https://www.youtube.com/watch?v=QYaQStudgnE

https://www.youtube.com/watch?v=oEx5vGNFrLk&pp=ygULc3RkOjpjaHJvbm8%3D

https://en.cppreference.com/w/cpp/chrono

Conceptually:

```
start timer
run computation
stop timer
print runtime
```

---

# 2. Video C++ Resources

Some students prefer video lectures.

Recommended:

Mike Shah — C++ 

The Cherno - C++ Series


Recommended topics:

* compilation model
* arrays and vectors
* memory layout
* timing programs

These videos explain how C++ programs interact with hardware.

---

# 3. Git Learning Resources (No Prior Experience Required)

Git is a **version control system**.

It tracks changes in code and allows multiple people to collaborate.

In this course Git will be used to:

* pull new lab instructions
* maintain your personal branch
* submit lab work

---

# 3.1 Basic Git Concepts

You should understand three ideas:

Repository
A folder tracked by Git.

Commit
A snapshot of the code.

Branch
A separate line of development.

Example:

```
main
  |
  |---- lab1
           |
           |---- keshav_lab1
```

---

# 3.2 Git Simple Guide

Beginner-friendly tutorial:

https://rogerdudler.github.io/git-guide/

Learn these commands:

```
git clone
git status
git add
git commit
git push
git pull
git branch
git checkout
```

---

# 3.3 Interactive Git Tutorial

Highly recommended:

https://learngitbranching.js.org/

This teaches Git visually.

Focus on:

* commits
* branches
* merges

---

# 4. Terminal Basics

Most programming will be done using a terminal.

Useful commands:

```
cd      change directory
ls      list files
mkdir   create directory
```

Optional resource:

https://linuxcommand.org/lc3_learning_the_shell.php

Only the basics are needed.

---

# 5. Why These Tools Matter

In this course you will:

* write C++ programs
* parallelize them using OpenMP
* analyze performance
* experiment with algorithms

C++ is used because it provides:

* high performance
* control over memory
* minimal runtime overhead

Git allows you to safely experiment while keeping a history of your work.

Later labs will introduce:

* OpenMP
* parallel loops
* reductions
* parallel FFT
