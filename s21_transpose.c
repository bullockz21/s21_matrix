#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (s21_wrong(A) || s21_create_matrix(A->columns, A->rows, result) != OK) {
    return INCORRECT_MATRIX;
  }
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return (exit_code);
}
