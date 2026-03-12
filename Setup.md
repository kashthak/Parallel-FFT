# Development Environment Setup

This course uses the following tools:

- C++ (compiled using `g++`)
- Git (version control)
- Visual Studio Code (editor)

By the end of this setup you should be able to:

- compile and run a C++ program
- clone the course repository
- create a personal Git branch
- edit code using VS Code

---

## 1. Install Git

Git is used to track code and submit your lab work.

### Linux (Ubuntu / Debian)

```bash
sudo apt update
sudo apt install git
```

Verify installation:

```bash
git --version
```

---

### macOS

Install Xcode Command Line Tools:

```bash
xcode-select --install
```

Verify:

```bash
git --version
```

If Git is missing, install using Homebrew.

Install Homebrew:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install Git:

```bash
brew install git
```

---

### Windows

Recommended method: **MSYS2**

1. Download MSYS2  
   https://www.msys2.org/

2. Install and open the **MSYS2 terminal**

3. Install Git

```bash
pacman -S git
```

Verify installation:

```bash
git --version
```

---

## 2. Configure Git Authentication (SSH)

To push code to GitHub you must authenticate.  
The recommended method is **SSH authentication**.

### Check for existing SSH keys

Run:

```bash
ls ~/.ssh
```

If you see files such as:

```
id_rsa
id_rsa.pub
id_ed25519
id_ed25519.pub
```

you may already have an SSH key.

If no keys exist, generate one.

---

### Generate a new SSH key

Run:

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

Press **Enter** to accept the default file location.

This creates two files:

```
~/.ssh/id_ed25519
~/.ssh/id_ed25519.pub
```

The `.pub` file is your **public key**.

---

### Start the SSH agent

Start the SSH agent:

```bash
eval "$(ssh-agent -s)"
```

Add your key:

```bash
ssh-add ~/.ssh/id_ed25519
```

---

### Copy your public key

Display the key:

```bash
cat ~/.ssh/id_ed25519.pub
```

Copy the entire output. It should look similar to:

```
ssh-ed25519 AAAAC3... your_email@example.com
```

---

### Add the key to GitHub

Open GitHub and navigate to:

```
Settings → SSH and GPG keys
```

Click **New SSH key**, paste your key, and save.

---

### Test the SSH connection

Run:

```bash
ssh -T git@github.com
```

Expected output:

```
Hi <username>! You've successfully authenticated.
```

If you see this message, SSH authentication is working.

---

## 3. Install a C++ Compiler (g++)

This course uses the GNU C++ compiler.

### Linux

Install build tools:

```bash
sudo apt install build-essential
```

Verify:

```bash
g++ --version
```

---

### macOS

The compiler is included with the Xcode command line tools.

Verify:

```bash
g++ --version
```

---

### Windows (MSYS2)

Install the compiler:

```bash
pacman -S mingw-w64-x86_64-gcc
```

Verify:

```bash
g++ --version
```

---

## 4. Install Visual Studio Code

Download:

https://code.visualstudio.com/

Recommended extensions:

- **C/C++ (Microsoft)**
- **GitLens (optional)**

VS Code will be used only as a **code editor**.  
Compilation will be done from the **terminal**.

---

## 5. Test Your C++ Environment

Create a file called:

```
hello.cpp
```

Add this code:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello Parallel World\n";
}
```

Compile:

```bash
g++ hello.cpp -O2 -o hello
```

Run:

Linux / macOS:

```bash
./hello
```

Windows:

```bash
./hello.exe
```

Expected output:

```
Hello Parallel World
```

If this works, your C++ environment is correctly configured.

---

## 6. Clone the Course Repository

Clone the repository:

```bash
git clone <repository-url>
```

Enter the directory:

```bash
cd parallel-fft-course
```

---

## 7. Create Your Personal Branch

Each student works on **their own branch**.

First switch to the lab branch:

```bash
git checkout lab1
```

Create your personal branch:

```bash
git checkout -b <yourname>_lab1
```

Example:

```bash
git checkout -b keshav_lab1
```

Verify your branch:

```bash
git branch
```

---

## 8. Submitting Your Work

After completing tasks:

```bash
git add .
git commit -m "Completed Lab 1"
git push origin <yourname>_lab1
```

Example:

```bash
git push origin keshav_lab1
```

Your branch will contain your lab solutions.

---

## 9. Getting Updates for New Labs

When a new lab is released:

```bash
git checkout lab2
git pull origin lab2
```

Create a new branch:

```bash
git checkout -b <yourname>_lab2
```

You will repeat this process for each lab.