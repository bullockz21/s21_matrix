#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (s21_wrong(A) || result == NULL) {
    exit_code = INCORRECT_MATRIX;
  } else if ((A->rows != A->columns)) {
    exit_code = CALC_ERROR;
  } else {
    double count = 0;
    s21_determinant(A, &count);
    if (fabs(count) < 1e-6) {
      exit_code = CALC_ERROR;
    } else if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = (1 / count);
    } else {
      matrix_t add = {0};
      matrix_t transponce_add = {0};
      s21_calc_complements(A, &add);
      s21_transpose(&add, &transponce_add);
      s21_mult_number(&transponce_add, 1 / count, result);
      s21_remove_matrix(&add);
      s21_remove_matrix(&transponce_add);
    }
  }
  return (exit_code);
}
