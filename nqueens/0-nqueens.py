#!/usr/bin/python3
"""
Solves the N-Queens problem using backtracking.
"""

import sys


def print_error_and_exit(message):
    print(message)
    exit(1)


def solve_nqueens(N):
    def is_safe(row, col, queens, diagonals1, diagonals2):
        return col not in queens and (
            row - col) not in diagonals1 and (row + col) not in diagonals2

    def solve(row, queens, diagonals1, diagonals2, current_solution):
        if row == N:
            solutions.append(current_solution[:])
            return
        for col in range(N):
            if is_safe(row, col, queens, diagonals1, diagonals2):
                queens.add(col)
                diagonals1.add(row - col)
                diagonals2.add(row + col)
                current_solution.append([row, col])

                solve(
                    row + 1, queens, diagonals1, diagonals2, current_solution)

                queens.remove(col)
                diagonals1.remove(row - col)
                diagonals2.remove(row + col)
                current_solution.pop()

    solutions = []
    solve(0, set(), set(), set(), [])
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print_error_and_exit("Usage: nqueens N")

    try:
        N = int(sys.argv[1])
    except ValueError:
        print_error_and_exit("N must be a number")

    if N < 4:
        print_error_and_exit("N must be at least 4")

    solve_nqueens(N)
