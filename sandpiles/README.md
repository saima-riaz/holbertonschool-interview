#  Project Sandpiles

![image](https://github.com/user-attachments/assets/e522ac60-0371-444f-bf37-a78d48f8b15f)

# Introduction

The Sandpiles Project is a fascinating exploration of a mathematical concept known as a sandpile model, which demonstrates how complex patterns can emerge from simple rules. In this project, you'll implement an algorithm to compute the sum of two 3x3 sandpiles and simulate the toppling process that occurs when cells in the grid exceed a certain threshold of stability.

A sandpile is considered stable when no cell in the grid contains more than 3 grains of sand. If a cell exceeds this threshold, it "topples" and distributes grains to its neighboring cells, potentially causing a chain reaction. The goal is to calculate the sum of two stable sandpiles and stabilize the resulting sandpile through successive topplings, printing the grid after each round of instability.

This project is part of a larger set of algorithmic challenges that not only test your problem-solving abilities but also emphasize writing efficient, well-structured code in C, adhering to industry-standard coding practices such as the Betty style.

Through this task, you'll gain a deeper understanding of the dynamics of self-organized systems and the power of simple rules in generating complex behaviors.

## Resources
- Watch: [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)

## Requirements

### General
- **Editors allowed**: `vi`, `vim`, `emacs`
- **Compilation**: All files will be compiled on **Ubuntu 14.04 LTS**.
- **Compiler**: `gcc 4.8.4` with the flags `-Wall -Werror -Wextra -pedantic`
- All files should end with a **new line**.
- Your code should follow the **Betty coding style**. This will be checked using `betty-style.pl` and `betty-doc.pl`.
- **No global variables** are allowed.
- **No more than 5 functions per file**.
- Your functions' prototypes should be in a **header file** named `sandpiles.h`.
- Your **header files must be include guarded**.
- You are not allowed to use **dynamic memory allocation**.

## Author

- [Saima RIAZ](https://github.com/saima-riaz)
