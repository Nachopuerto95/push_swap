<p align="left">
  <strong>🌐 Change language:</strong><br>
  <a href="multilang/README.es.md">
    <img src="multilang/ES.png" alt="Español" width="32">
  </a>
  <a href="/README.md">
    <img src="/multilang/EN.png" alt="English" width="32">
  </a>
</p>


# Push Swap (42cursus)

### 📌 Description

Push Swap is a project from the 42 curriculum that consists of sorting a stack of integers using a limited set of operations and an auxiliary stack. The main goal is to achieve the sorting with the fewest number of moves possible, turning it into an algorithm optimization challenge.

This repository contains a complete implementation of the Push Swap project, developed in C language, using the well-known Turkish algorithm — a heuristic strategy designed to balance performance and efficiency in terms of operation count.

### 🚀 Project Objectives

Manipulate data structures (linked lists).

Develop a custom sorting algorithm.

Optimize the number of instructions (moves).

Respect the constraints of the allowed operations.

Apply the Turkish algorithm effectively for good results on medium and large input sets.

### 🧠 What is the Turkish Algorithm?

The Turkish algorithm is a heuristic strategy that efficiently sorts by using a chunking-like approach. The stack is divided into value fragments (chunks), and elements are moved smartly between stacks A and B to minimize the number of rotations, pushes, and reinsertions. Its implementation strikes a balance between simplicity and efficiency, making it ideal for medium to large input sizes (100–500 numbers).

Core principles:

- All numbers except three are pushed to stack B; the remaining three are sorted in stack A.
- In each iteration:<br>
  1 - The target of each number is calculated — the number in stack A on top of which it should be placed (the largest number smaller than the current one).<br>
  2 - Once the target is known, the "cost" (or price) of each move is calculated — the number of operations needed to bring both the element and its target to the top of their respective stacks.<br>
  3 - After calculating the cost for all elements, the cheapest one is moved, and the targets and prices are recalculated.<br>

### 🔧 How to Use

Compilation:

```c
make
```

Execution:

```c
./push_swap <number1> <number2> <number3> ...
```

Example:

```c
./push_swap 5 34 6 -7 233
```

Expected output:

The program will print to stdout the sequence of operations needed to sort the stack in the most efficient way possible.
If the input is invalid (non-numeric values, duplicates, etc.), it will print Error to stderr.

### ✅ Allowed Operations

The program can only use the following operations on the stacks:

`sa` / `sb` / `ss` – Swap the first two elements of a stack. <br>
`pa` / `pb` – Push the top element from one stack to the other. <br>
`ra` / `rb` / `rr` – Rotate a stack upward.<br>
`rra` / `rrb` / `rrr` – Rotate a stack downward.<br>
