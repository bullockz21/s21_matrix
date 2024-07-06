#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int exit_code = OK;
  if (rows < 1 || columns < 1) {
    exit_code = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
  }
  return (exit_code);
}
