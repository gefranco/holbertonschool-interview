#!/usr/bin/python3
import sys


def put_queens(n, initial_col):
    i = 0
    j = 0
    total_columns = 0
    solution = []
    
    while i < n:
        queen_pos = [0,0]
        queen_pos[0] = i;
        # table[i][j] = 1;
        queen_pos[1] = j
        solution.append(queen_pos)
        if not check_queens(solution):
            solution.pop()
            j += 1
            if j >= n:
                i = 0
                solution.clear()
                j = 1
            # i -= 1 
        else:
            i += 1
            if j >= n - 1:
                j = 0
    print(solution)

def check_queens(solution):
    if len(solution) == 1:
        return True;
#    print("solution: ", solution) 
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


#    table = [];
#    solution = [];
#    for i in range(n):
#        raw = [];
#        for j in range(n):
#            raw.append(0);
#        table.append(raw);
#    for i in range(n):
    put_queens(n, 0)


