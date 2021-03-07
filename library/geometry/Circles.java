package library.geometry;

public class Circles {

  public static double calculateRegularPolygonArea(double r, int polygonSize) {
    return polygonSize * (r * r * Math.sin(2 * Math.PI / polygonSize)) / 2;
  }

  /**
   * Finds the circle center given any three points.
   * x = double[0], y = double[1]
   *
   * <pre>{@code
   *    Let center be (a, b), then the pint of symmetry for (x1, y1) according to (a, b) is
   *    (2a - x1, 2b - y1).
   *    The dot product of vector dot( (x2 - x1, y2 - y1), (x2 - (2a - x1), y2 - (2b - y1)) is 0
   *    because their angle is 90 degree. Similarly for vector
   *    dot( (x3 - x1, y3 - y1), (x3 - (2a - x1), y3 - (2b - y1)).
   *
   *    We get
   *      2a(x1 - x2) + 2b(y1 - y2) = (x1^2 - x2^2) + y1^2 - y2^2
   *    and
   *      2a(x1 - x3) + 2b(y1 - y3) = (x1^2 - x3^2) + y1^2 - y3^2
   *
   *    Denote A = x1 - x2, B = y1 - y2, C = (x1^2 - x2^2) + y1^2 - y2^2
   *           D = x1 - x3, E = y1 - y3, F = (x1^2 - x3^2) + y1^2 - y3^2
   *    Then 2Aa + 2Bb = C and 2Da + 2Eb = F
   *    Therefore
   *    a = (CE - BF) / 2(AE - BD)
   *    b = (AF - CD) / 2(AE - BD)
   * }
   */
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
}
