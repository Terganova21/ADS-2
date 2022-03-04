// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double k;
  uint16_t i;
  k = value;
  if (n == 0) {
    return 1;
  }
  for (i = 2; i <= n; i++) {
    k = k * value;
  }
  return k;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint64_t i = 1; i <= n; i++)
    result *= i;
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double ex = 1;
  for (uint16_t i = 1; i <= count; i++) {
    ex += calcItem(x, i);
  }
  return ex;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1; i <= count; i++) {
    sum += pown(-1, (i-1)) * calcItem(x, (2 * i - 1));
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum2 = 0;
  for (uint16_t m = 1; m <= count; m++) {
    sum2 += pown(-1, (m-1)) * calcItem(x, (2 * m - 2));
  }
  return sum2;
}
