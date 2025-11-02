# 42sh Epitech Project 2021

> **“You know the answer.”**
> A full-featured Unix shell written **in C**, inspired by **TCSH**.

---

## 🧩 Overview

**42sh** is a complete Unix shell designed to emulate the behavior of **TCSH**, developed as final first year project made in a group of 4 members.

The goal here is to build a shell emitating TCSH behavior and commands.

---

## ⚙️ Compilation

Compile the shell using the provided **Makefile**:

```bash
make
```

### Makefile Rules

```
make        # Compile 42sh
make clean  # Remove object files
make fclean # Remove binaries
make re     # Full rebuild
```

---

## 🖥️ Usage

Simply launch your shell:

```bash
./42sh
```

You’ll then enter an interactive terminal session capable of executing system commands, managing jobs, handling environment variables, and supporting scripting.

If the shell encounters a runtime error, it exits with **the same error code as tcsh**.

---

## 🧠 Objectives

The goal of this project is to build a **stable and feature-complete Unix shell**, focusing on correctness and compatibility rather than adding fragile or incomplete features.

### 🧾 Requirements

* Fully functional shell based on **tcsh syntax**
* No partial or buggy features: **stability > quantity**
* Organized teamwork, modular architecture, and consistent code style

---

## 🧩 Mandatory Features

Your shell must support the following:

| Category              | Features                                               |
| --------------------- | ------------------------------------------------------ |
| **Inhibitors**        | `' '` single quotes to inhibit special characters      |
| **Globbing**          | `*`, `?`, `[ ]` pattern matching                       |
| **Job Control**       | `&`, `fg`, `bg` (background/foreground management)     |
| **Backticks**         | Command substitution using `` `command` ``             |
| **Parentheses**       | Command grouping `( ... )`                             |
| **Variables**         | Local and environment variables                        |
| **Special Variables** | `term`, `precmd`, `cwdcmd`, `cwd`, `ignoreeof`, etc.   |
| **History**           | Command recall with `!` syntax                         |
| **Aliases**           | Define shortcuts (e.g. `alias ls "ls --color"`)        |
| **Line Edition**      | Multiline input, dynamic key rebinding, autocompletion |
| **Scripting**         | Support for basic shell scripting syntax               |

---

## 🧩 Example Session

```bash
$ ./42sh
> echo "Hello World"
Hello World

> setenv USER "Nelryn"
> echo $USER
Nelryn

> alias ll "ls -la"
> ll
total 12
drwxr-xr-x  3 nelryn  staff   96 Jan 24 15:23 .
drwxr-xr-x  5 nelryn  staff  160 Jan 24 15:23 ..

> ls *.c
main.c prompt.c history.c parser.c
```

---

## 🧠 Development Guidelines

### 👥 Teamwork

* Team of **4–5 developers**
* Use **Git branches** for feature isolation
* Conduct **code reviews**
* Ensure each module can be maintained by anyone on the team

### 🧪 Testing

* Write **unit tests** as new features are implemented
* Validate **command parsing**, **execution**, and **memory management**
* Use `valgrind` or similar tools to ensure no leaks

### 🧩 Design Tips

* Modularize command parsing, execution, and I/O
* Avoid hard dependencies across modules
* Implement error recovery for user input and system calls

---

## 🧾 Exit Codes

| Code | Meaning                           |
| ---- | --------------------------------- |
| `0`  | Successful execution              |
| `>0` | Error (same as `tcsh` equivalent) |

---

## 📂 Project Structure

```
42sh_Epitech_Project_2021/
├── src/
├── lib/                 # C Library
├── include/             # Header files
├── tests/               # Unit tests
├── Makefile             # Build rules
└── README.md            # Documentation
```

Would you like me to tailor this README to **your actual implementation** (e.g., builtins implemented, custom features, or CLI behavior from your repository)?
If you confirm, I can align it precisely with your repo’s code and design choices.
