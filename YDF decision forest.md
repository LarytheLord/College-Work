Alright — you're asking to **make this code work for Turbo C**. But here’s something important we need to clarify before diving deeper:

---

### ❗Critical Checkpoint: What is Turbo C?

**Turbo C** is a very old IDE and C compiler, mainly for **16-bit DOS applications**. It:

* Doesn't support **C++11** (or any modern C++)
* Doesn’t support **dynamic linking**, smart pointers, modern `std::string`, etc.
* Can't work with **C++ projects like Yggdrasil Decision Forests**, which rely heavily on modern C++ and even **Bazel** as the build system.

---

### ✅ So the honest answer:

> **You cannot use Yggdrasil Decision Forests with Turbo C.**

It's not a compatible environment. YDF:

* Requires a modern C++ compiler (like GCC 11+, Clang, or MSVC)
* Uses advanced features like smart pointers, C++ classes, and protocol buffers
* Needs a proper OS (Linux, Windows, or macOS), not DOS or 16-bit mode

---

## ✅ What CAN You Do Instead?

Let's focus on a **realistic, beginner-friendly way to interact with YDF from C**:

### 1. Use a modern compiler (e.g., GCC or Clang on Linux or Windows via WSL)

Turbo C is educational, but not practical for real-world projects.

### 2. Keep the wrapper in modern C++ (like we already started)

You write a simple wrapper using `extern "C"` so your C code can use it.

### 3. Compile with `g++` and link from your C program

If you’re on Windows and really need a GUI IDE, consider:

* **Code::Blocks**
* **Dev C++**
* **VS Code + MinGW**

---

## 👇 Here's a better path

Let’s say you want to call YDF from C.

* You write your **main program in C**
* You compile a **C++ wrapper library** using `g++`
* You link your C program to that wrapper

Do you want me to walk you through setting that up in **Code::Blocks** or **VS Code** using **MinGW**?

Or are you trying to stick with **Turbo C** for school? If yes, tell me *why* you need Turbo C — I can help you prepare a **parallel mini project** that mimics tree traversal in Turbo C without using YDF. That might actually be useful.

👉 So, what’s your goal?

* Use C to interact with machine learning models like YDF?
* Build decision trees yourself in C (like a practice project)?
* Or do something else entirely?

Let’s aim for something that works and builds your skills.
