#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = OK;
  if (s21_wrong(A) == 0 && s21_wrong(B) == 0) {
    if (A->columns == B->columns && A->rows == B->rows) {
      exit_code = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      exit_code = CALC_ERROR;
    }
  } else {
    exit_code = INCORRECT_MATRIX;
  }
  return (exit_code);
}
