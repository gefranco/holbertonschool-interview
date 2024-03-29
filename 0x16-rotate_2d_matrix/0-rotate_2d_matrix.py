#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotate 2D Matrix
    """
    index_o = len(matrix) - 1
    index_i = 0
    copy_matrix = get_copy(matrix)
    inner = get_inner_square(matrix, 0)
    squares = 0

    while squares <= int((len(matrix) - 1) / 2):
        inner_row = get_row(matrix, index_i)
        outter_col = get_col(matrix, index_o)
        outter_row = get_row(matrix, index_o)
        inner_col = get_col(matrix, index_i)

        outter_col.reverse()
        inner_col.reverse()

        replace_col(matrix, index_o, inner_row, squares)
        replace_row(matrix, index_o, outter_col, squares)
        replace_col(matrix, index_i, outter_row, squares)
        replace_row(matrix, index_i, inner_col, squares)
        index_o -= 1
        index_i += 1
        squares += 1


def get_col(matrix, index_col):
    """
    return column
    """
    col_tmp = []
    for row in range(0, len(matrix)):
        i = 0
        for col in range(0, len(matrix)):
            if i == index_col:
                col_tmp.append(matrix[row][index_col])
            i += 1
    return col_tmp.copy()


def get_row(matrix, index_row):
    """
    return row
    """
    if index_row <= len(matrix):
        return matrix[index_row].copy()


def replace_col(matrix, index_col, new_col, squares):
    """
    replace col
    """
    if new_col is None:
        return
    i_r = squares
    col_tmp = []
    for row in range(squares, len(matrix) - squares):
        for col in range(squares, len(matrix) - squares):
            if index_col == col:
                matrix[row][col] = new_col[i_r]
                i_r += 1


def replace_row(matrix, index_row, new_row, squares):
    """
    repalce row
    """
    i_c = squares
    for row in range(squares, len(matrix) - squares):
        for col in range(squares, len(matrix) - squares):
            if index_row == row:
                matrix[row][col] = new_row[i_c]
                i_c += 1


def print_matrix(matrix):
    """
    Print 2D Matrix
    """
    for row in matrix:
        print(row)


def get_copy(matrix):
    """
    return a Matrix copy
    """
    copy = []
    for row in matrix:
        copy.append(row.copy())
    return copy


def get_inner_square(matrix, inner):
    """
    ...
    """
    square = []
    my_row = []
    for row in range(inner, len(matrix) - inner):
        my_row = []
        for col in range(inner, len(matrix) - inner):
            my_row.append(matrix[row][col])
        square.append(my_row)
    return square
