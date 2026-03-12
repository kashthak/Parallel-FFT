# Lab 1 — Git Workflow and C++ Basics

## Objectives

This lab introduces the workflow used throughout the course.

By the end of this lab you should be able to:

* use Git to commit and push code
* compile and run C++ programs
* work with vectors and loops
* measure execution time

The program written here will be **parallelized in later labs**.

---

# Repository Workflow

Each lab exists as its **own branch**.

Example:

```
main
│
├── lab1
├── lab2
├── lab3
```

You will:

1. checkout the lab branch
2. complete the tasks
3. commit your work
4. push your changes

---

# Step 1 — Checkout Lab 1

Switch to the Lab 1 branch:

```bash
git checkout lab1
```

Pull the latest version:

```bash
git pull origin lab1
```

---

# Step 2 — Git Practice Exercise

Create a file:

```
student_info.txt
```

Add:

```
Name:
GitHub username:
Operating system:
```

Example:

```
Name: Alice Smith
GitHub username: alice123
Operating system: Ubuntu
```

Add the file:

```bash
git add student_info.txt
```

Commit:

```bash
git commit -m "Added student information"
```

Push:

```bash
git push origin lab1
```

This confirms that your Git workflow is working.

---

# Step 3 — Test the C++ Compiler

Navigate to the examples directory:

```bash
cd examples
```

Compile:

```bash
g++ hello.cpp -O2 -o hello
```

Run:

Linux / macOS

```bash
./hello
```

Windows

```bash
./hello.exe
```

Expected output:

```
Hello Parallel World
```

---

# Step 4 — Examine Starter Code

Navigate to the Lab 1 starter code:

```bash
cd ../labs/lab1/starter_code
```

Open:

```
vector_operations.cpp
```

Some functions are incomplete.

You will implement them.

---

# Step 5 — Implement `fill_vector`

Function:

```
void fill_vector(std::vector<float>& v)
```

Goal:

Fill the vector with random floating-point values.

---

# Step 6 — Implement `scale_vector`

Function:

```
void scale_vector(std::vector<float>& v, float scale)
```

Operation:

```
v[i] = v[i] * scale
```

This loop will later be **parallelized in Lab 2**.

---

# Step 7 — Implement `sum_vector`

Function:

```
float sum_vector(const std::vector<float>& v)
```

Goal:

Compute the total sum of the vector.

---

# Step 8 — Compile the Program

Compile:

```bash
g++ vector_operations.cpp -O2 -o vector_ops
```

Run:

```bash
./vector_ops
```

Example output:

```
Vector size: 10000000
Sum: 4982031
Runtime: 0.21 seconds
```

---

# Step 9 — Commit Your Work

Add the completed file:

```bash
git add vector_operations.cpp
```

Commit:

```bash
git commit -m "Lab 1 completed"
```

Push:

```bash
git push origin lab1
```

---

# Deliverables

Your submission must contain:

```
student_info.txt
vector_operations.cpp
```

The program must:

* compile successfully
* run correctly
* print execution time

---

# What You Learned

This lab introduced:

* Git workflow
* C++ compilation
* vectors
* loops
* functions
* measuring runtime

In **Lab 2**, we will:

* introduce OpenMP
* parallelize loops
* measure speedup
