# Operating Systems Concepts Implementation

This repository contains implementations of fundamental **Operating Systems concepts** written in **C/C++**.  
The programs demonstrate key OS mechanisms such as **CPU scheduling, memory management, process management, interprocess communication, and synchronization**.

The goal of this repository is to provide practical implementations of core OS topics commonly studied in Computer Science and to serve as a reference for students learning system-level programming.

---

## Concepts Covered

### CPU Scheduling
- FCFS (First Come First Serve) Scheduling
- SRTF (Shortest Remaining Time First) Scheduling

### Memory Management
- FCFS Page Replacement
- LRU Page Replacement

### Deadlock Avoidance
- Banker's Algorithm

### Process Management
- Orphan Process
- Zombie Process

### Process Synchronization
- Reader-Writer Problem using Semaphores

### Interprocess Communication
- Pipes

### Shell Programming
- Shell command examples
- Shell-based calculator

---

## Repository Structure


Operating-Systems-Concepts/

├── Bankers
├── FCFS_scheduling
├── SRTF_Scheduling
├── Fcfs_Page_R
├── LruPageReplacement
├── readerwriter.c
├── pipes
├── orphan
├── zombie process
├── Shell_Calculator
├── os1 shell examples.txt


Each file or folder contains a program demonstrating a specific operating systems concept.

---

## Technologies Used

- C
- C++
- Linux System Calls
- GCC Compiler

---

## How to Run

Compile programs using GCC:

```bash
gcc filename.c -o output
./output

Example:

gcc readerwriter.c -o readerwriter
./readerwriter
