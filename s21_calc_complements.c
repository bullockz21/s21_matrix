#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (s21_wrong(A)) {
    exit_code = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    exit_code = CALC_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result) !=
                 INCORRECT_MATRIX &&
             (A->rows == 1)) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t square = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &square);
        double determinant = 0;
        s21_square_matrix(i, j, A, &square);
        s21_determinant(&square, &determinant);
        result->matrix[i][j] = pow(-1, (i + j)) * determinant;
        s21_remove_matrix(&square);
      }
    }
  }
  return (exit_code);
}

void s21_square_matrix(int rows, int columns, matrix_t *A, matrix_t *square) {
  int mini_rows = 0;
  int mini_columns = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == rows) {
      continue;
    }
    mini_columns = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == columns) {
        continue;
      }
      square->matrix[mini_rows][mini_columns] = A->matrix[i][j];
      mini_columns++;
    }
    mini_rows++;
  }
}
