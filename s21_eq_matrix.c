#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int exit_code = SUCCESS;
  if (s21_wrong(A) == 0 && s21_wrong(B) == 0 && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
          exit_code = FAILURE;
        }
    }
  } else {
    exit_code = FAILURE;
  }
  return (exit_code);
}

int s21_wrong(matrix_t *matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}
