#!/usr/bin/python3
import sys


def put_queens(n, row, solution):
    
    if(n == row):
        print(solution)
    else:
        for col in range(n):
            queen = [row, col]
            solution.append(queen)
            if not all_queens_save(solution):
                solution.pop()
                #print(solution) 
            else:
                put_queens(n, row + 1, solution)
                solution.pop()

def all_queens_save(solution):
    if len(solution) == 1:
        return True;
    #print("solution: ", solution) 
    for i in range(len(solution)):
        for j in range(i + 1, len(solution)):
            if (solution[i][1] == solution[j][1] or 
                solution[i][0] - solution[i][1] == solution[j][0] - solution[j][1] or
                solution[i][0] + solution[i][1] == solution[j][0] + solution[j][1]):
#                print("ataking")
                return False
    return True    

def print_table():
    print(table);
    for i in range(n):
        for j in range(n):
            print(table[i][j], end=" ")
        print()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        n = int (sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    
    if n < 4:
        print("N must be at least 4")
        exit(1)


    solution = [];
    put_queens(n, 0,solution)


