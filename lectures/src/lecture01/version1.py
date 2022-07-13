#!/usr/bin/python3
import random
import time

N = 1024

A = [[random.random() for _ in range(N)] for _ in range(N)]
B = [[random.random() for _ in range(N)] for _ in range(N)]
C = [[0.0 for _ in range(N)] for _ in range(N)]

start = time.time()

for i in range(N):
  for j in range(N):
    for k in range(N):
      C[i][j] += A[i][k] * B[k][j]

end = time.time()

print(f"{end - start:0.6f}")
