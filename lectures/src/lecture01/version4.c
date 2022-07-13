#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 4096

double A[N][N];
double B[N][N];
double C[N][N];

float diff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

int main(void) {
  for (int i = 0; i < N; i += 1) {
    for (int j = 0; j < N; j += 1) {
      A[i][j] = (double)rand() / (double)RAND_MAX;
      B[i][j] = (double)rand() / (double)RAND_MAX;
      C[i][j] = (double)0;
    }
  }

  struct timeval start, end;

  gettimeofday(&start, NULL);

#pragma omp parallel for
  for (int i = 0; i < N; i += 1) {
    for (int k = 0; k < N; k += 1) {
      for (int j = 0; j < N; j += 1) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  gettimeofday(&end, NULL);

  printf("%0.6f\n", diff(&start, &end));

  return EXIT_SUCCESS;
}
