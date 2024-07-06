#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int exit_code = OK;
  if (s21_wrong(A) || result == NULL) {
    exit_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    exit_code = CALC_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = det(A);
  }
  return (exit_code);
}

double det(matrix_t *A) {
  double deter = 0;
  if (A->rows == 1)
    deter = A->matrix[0][0];
  else if (A->rows > 1) {
    matrix_t square = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &square);
    for (int sign = 1, i = 0; i < A->columns; i++, sign *= (-1)) {
      s21_square_matrix(0, i, A, &square);
      deter += sign * A->matrix[0][i] * det(&square);
    }
    s21_remove_matrix(&square);
  }
  return deter;
}
