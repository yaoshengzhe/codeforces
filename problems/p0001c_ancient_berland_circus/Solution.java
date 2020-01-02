package problems.p0001c_ancient_berland_circus;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution {
  BufferedReader in;
  PrintWriter out;
  StringTokenizer tok = new StringTokenizer("");

  public static void main(String[] args) throws Exception {
    new Solution().run();
  }

  private static boolean isProd() {
    return System.getProperty("ONLINE_JUDGE") != null;
  }

  public static double[] findCenter(
      double x1, double y1, double x2, double y2, double x3, double y3) {

    double x1_square = x1 * x1;
    double x2_square = x2 * x2;
    double x3_square = x3 * x3;
    double y1_square = y1 * y1;
    double y2_square = y2 * y2;
    double y3_square = y3 * y3;

    double A = x1 - x2;
    double B = y1 - y2;
    double C = x1_square - x2_square + y1_square - y2_square;
    double D = x1 - x3;
    double E = y1 - y3;
    double F = x1_square - x3_square + y1_square - y3_square;

    double z = 2 * (A * E - B * D);

    double a = (C * E - B * F) / z;
    double b = (A * F - C * D) / z;

    return new double[] {a, b};
  }

  void solve() throws IOException {
    double x1 = readDouble();
    double y1 = readDouble();
    double x2 = readDouble();
    double y2 = readDouble();
    double x3 = readDouble();
    double y3 = readDouble();

    double[] center = findCenter(x1, y1, x2, y2, x3, y3);

    double a = center[0];
    double b = center[1];

    double r_square = (a - x1) * (a - x1) + (b - y1) * (b - y1);

    double angle1 = Math.atan2(y1 - b, x1 - a);
    double angle2 = Math.atan2(y2 - b, x2 - a);
    double angle3 = Math.atan2(y3 - b, x3 - a);

    double epsilon = 1E-5;

    for (int i = 3; i < 101; i++) {
      if ((Math.abs(Math.sin(i * (angle1 - angle2) / 2)) < epsilon)
          && (Math.abs(Math.sin(i * (angle1 - angle3) / 2)) < epsilon)) {
        double area = i * (r_square * Math.sin(2 * Math.PI / i)) / 2;

        System.out.printf("%.6f\n", area);
        break;
      }
    }

    System.err.printf("center: (%f, %f)\n", center[0], center[1]);
  }

  public void run() throws IOException {
    long startTimeMillis = 0;

    if (isProd()) {
      in = new BufferedReader(new InputStreamReader(System.in));
      out = new PrintWriter(System.out);
    } else {
      startTimeMillis = System.currentTimeMillis();

      System.out.printf("Current directory: %s\n", Paths.get(".").toAbsolutePath().normalize());

      in = new BufferedReader(new FileReader("inputs/input.txt"));
      out = new PrintWriter("output.txt");
    }

    Locale.setDefault(Locale.US);
    solve();
    in.close();
    out.close();

    if (!isProd()) {
      System.err.printf(
          "Total Run Time: %,d millis\n", System.currentTimeMillis() - startTimeMillis);
    }
  }

  String readString() throws IOException {
    while (!tok.hasMoreTokens()) {
      tok = new StringTokenizer(in.readLine());
    }
    return tok.nextToken();
  }

  int readInt() throws IOException {
    return Integer.parseInt(readString());
  }

  long readLong() throws IOException {
    return Long.parseLong(readString());
  }

  double readDouble() throws IOException {
    return Double.parseDouble(readString());
  }
}
