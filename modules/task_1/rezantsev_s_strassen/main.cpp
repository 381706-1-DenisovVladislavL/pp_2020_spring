// Copyright 2020 Rezantsev Sergey
#include "../../modules/task_1/rezantsev_s_strassen/strassen.h"
#include "gtest/gtest.h"

TEST(Strassen, correct_sum) {
  int n = 2;
  double *a = new double[n * n], *b = new double[n * n], *c = new double[n * n],
         *res = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = n * n - i;
    c[i] = 4;
  }
  res = sumMatrix(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, res, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] res;
}

TEST(Strassen, correct_size) {
  int n = 64;
  int m = 50;
  int l = 31;
  ASSERT_EQ(checkSize(n), 64);
  ASSERT_EQ(checkSize(m), 64);
  ASSERT_EQ(checkSize(l), 32);
}

TEST(Strassen, correct_resize) {
  int n = 3;
  double *a = new double[n * n];
  double b[16] = {0, 1, 2, 0, 3, 4, 5, 0, 6, 7, 8, 0, 0, 0, 0, 0};
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
  }
  a = resizeMatrix(a, n);
  ASSERT_TRUE(isEqMatrix(a, b, n));
  delete[] a;
}

TEST(Strassen, correct_subt) {
  int n = 2;
  double *a = new double[n * n], *b = new double[n * n], *c = new double[n * n],
         *res = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = i;
    c[i] = 0;
  }
  res = subtMatrix(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, res, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] res;
}

TEST(Strassen, correct_mult) {
  int n = 2;
  double *a = new double[n * n], *b = new double[n * n], *c = new double[n * n],
         *res = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i + 1;
    b[i] = i + n * n + 1;
  }
  c[0] = 19;
  c[1] = 22;
  c[2] = 43;
  c[3] = 50;
  res = multMatrix(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, res, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] res;
}

TEST(Strassen, correct_split) {
  int n = 4;
  int m = 2;
  double *a = new double[n * n];
  double *a11 = new double[m * m];
  double *a12 = new double[m * m];
  double *a21 = new double[m * m];
  double *a22 = new double[m * m];
  double b11[4] = {0, 1, 4, 5};
  double b12[4] = {2, 3, 6, 7};
  double b21[4] = {8, 9, 12, 13};
  double b22[4] = {10, 11, 14, 15};
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
  }
  splitMatrix(a, a11, a22, a12, a21, n);
  ASSERT_TRUE(isEqMatrix(b11, a11, m));
  ASSERT_TRUE(isEqMatrix(b12, a12, m));
  ASSERT_TRUE(isEqMatrix(b22, a22, m));
  ASSERT_TRUE(isEqMatrix(b21, a21, m));
  delete[] a;
  delete[] a11;
  delete[] a22;
  delete[] a21;
  delete[] a12;
}

TEST(Strassen, correct_collect) {
  int n = 4;
  int m = 2;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double b11[4] = {0, 1, 4, 5};
  double b12[4] = {2, 3, 6, 7};
  double b21[4] = {8, 9, 12, 13};
  double b22[4] = {10, 11, 14, 15};
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
  }
  b = collectMatrix(b11, b22, b12, b21, m);
  ASSERT_TRUE(isEqMatrix(b, a, n));
  delete[] a;
  delete[] b;
}

TEST(Strassen, correct_strassen_4x4) {
  int n = 4;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c = new double[n * n];
  double *d = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = n * n - i;
  }
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

TEST(Strassen, correct_strassen_8x8) {
  int n = 8;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c = new double[n * n];
  double *d = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = n * n - i;
  }
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

TEST(Strassen, correct_strassen_16x16) {
  int n = 16;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c = new double[n * n];
  double *d = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = n * n - i;
  }
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

TEST(Strassen, correct_strassen_16x16_1) {
  int n = 16;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c = new double[n * n];
  double *d = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i;
    b[i] = (n * n - i) * 2;
  }
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

TEST(Strassen, correct_strassen_16x16_2) {
  int n = 16;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c = new double[n * n];
  double *d = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    a[i] = i * n;
    b[i] = n * n - i;
  }
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

TEST(Strassen, correct_strassen_10x10) {
  int n = 10;
  double *a = new double[n * n];
  double *b = new double[n * n];
  double *c;
  double *d;
  for (int i = 0; i < n * n; i++) {
    a[i] = i * n;
    b[i] = n * n - i;
  }
  a = resizeMatrix(a, n);
  b = resizeMatrix(b, n);
  n = checkSize(n);
  c = multMatrix(a, b, n);
  d = strassen(a, b, n);
  ASSERT_TRUE(isEqMatrix(c, d, n));
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
