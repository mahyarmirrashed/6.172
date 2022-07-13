import java.util.Random;

public class version2 {
  static private final int N = 1024;
  static private final double[][] A = new double[N][N];
  static private final double[][] B = new double[N][N];
  static private final double[][] C = new double[N][N];

  public static void main(String[] args) {
    Random r = new Random();

    for (int i = 0; i < N; i += 1) {
      for (int j = 0; j < N; j += 1) {
        A[i][j] = r.nextDouble();
        B[i][j] = r.nextDouble();
        C[i][j] = 0.0;
      }
    }

    long start = System.nanoTime();

    for (int i = 0; i < N; i += 1) {
      for (int j = 0; j < N; j += 1) {
        for (int k = 0; k < N; k += 1) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }

    long stop = System.nanoTime();

    System.out.println((stop - start) * 1e-9);
  }
}
