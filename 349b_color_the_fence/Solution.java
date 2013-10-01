import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int V = Integer.parseInt(stdin.nextLine());
        int[] a = new int[9];
        String[] data = stdin.nextLine().split(" ");
        for (int i=0; i < 9; ++i) {
            a[i] = Integer.parseInt(data[i]);
        }
        Map<Integer, String> cache = new HashMap<Integer, String>();
        String result = findMaxNum(V, a, cache);
        System.out.println(result.length() == 0 ? -1 : result);
    }

    public static String findMaxNum(int v, int[] a, Map<Integer, String> cache) {
        if (cache.containsKey(v)) {
            return cache.get(v);
        }
        String result = "";
        for (int i=0; i < 9; ++i) {
            int r = v - a[i];
            if (r >= 0) {
                if (!cache.containsKey(r)) {
                    cache.put(r, findMaxNum(r, a, cache));
                }
                String candidate = String.format("%d%s", i+1, cache.get(r));
                if (numCompare(result, candidate) < 0) {
                    result = candidate;
                }
            }
        }
        return result;
    }

    public static int numCompare(String a, String b) {
        if (a.length() < b.length()) {
            return -1;
        } else if (a.length() > b.length()) {
            return 1;
        } else {
            for (int i=0; i < a.length(); ++i) {
                int diff = a.charAt(i) - b.charAt(i);
                if (diff != 0) {
                    return diff;
                }
            }
            return 0;
        }
    }
}
