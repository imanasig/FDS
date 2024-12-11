# Write a Python program to compute following computation on matrix: 
# a) Addition of two matrices 
# b) Subtraction of two matrices 
# c) Multiplication of two matrices 
# d) Transpose of a matrix

def add_matrices(matrix1, matrix2):
    # Adds two matrices and returns the result.
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def subtract_matrices(matrix1, matrix2):
    # Subtracts the second matrix from the first and returns the result.
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def multiply_matrices(matrix1, matrix2):
    # Multiplies two matrices and returns the result.
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            value = 0
            for k in range(len(matrix2)):
                value += matrix1[i][k] * matrix2[k][j]
            row.append(value)
        result.append(row)
    return result

def transpose_matrix(matrix):
    # Returns the transpose of the given matrix.
    result = []
    for i in range(len(matrix[0])):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[j][i])
        result.append(row)
    return result

def display_matrix(matrix):
    # Displays a matrix row by row. 
    for row in matrix:
        print(" ".join(str(element) for element in row))

def input_matrix(rows, cols):
    # Takes user input to create a matrix with given dimensions. 
    matrix = []
    print("Enter the elements of the matrix ({}x{}):".format(rows, cols))
    for i in range(rows):
        row = list(map(int, input().split()))
        while len(row) != cols:
            print("Please enter exactly {} values:".format(cols))
            row = list(map(int, input().split()))
        matrix.append(row)
    return matrix

def main():
    rows1 = int(input("Enter the number of rows for Matrix 1: "))
    cols1 = int(input("Enter the number of columns for Matrix 1: "))
    matrix1 = input_matrix(rows1, cols1)

    rows2 = int(input("Enter the number of rows for Matrix 2: "))
    cols2 = int(input("Enter the number of columns for Matrix 2: "))
    matrix2 = input_matrix(rows2, cols2)

    print("Matrix 1:")
    display_matrix(matrix1)

    print("\nMatrix 2:")
    display_matrix(matrix2)

    if rows1 == rows2 and cols1 == cols2:
        print("\nAddition of matrices:")
        result = add_matrices(matrix1, matrix2)
        display_matrix(result)

        print("\nSubtraction of matrices:")
        result = subtract_matrices(matrix1, matrix2)
        display_matrix(result)
    else:
        print("\nAddition and subtraction are not possible as the dimensions of the matrices do not match.")

    if cols1 == rows2:
        print("\nMultiplication of matrices:")
        result = multiply_matrices(matrix1, matrix2)
        display_matrix(result)
    else:
        print("\nMultiplication is not possible as the number of columns of Matrix 1 does not match the number of rows of Matrix 2.")

    print("\nTranspose of Matrix 1:")
    result = transpose_matrix(matrix1)
    display_matrix(result)

main()
