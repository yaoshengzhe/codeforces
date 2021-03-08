#include <stdio.h>
#include <vector>

using namespace std;

constexpr int N = 1000000+1;
char seq[N];

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  scanf("%s", seq);

  int left = 0;
  int right = 0;

  int result = 0;
  int left_minus_right = 0;
  int substring_len = 0;
  for (int i=0; i < n; ++i) {
    int prev = left_minus_right;
    
    if (seq[i] == '(') {
      left++;
      left_minus_right++;
    } else {
      right++;
      left_minus_right--;
    }

    if (prev < 0 || left_minus_right < 0) {
      substring_len++;
    }
    
    if (prev < 0 && left_minus_right == 0) {
      result += substring_len;
      substring_len = 0;
      left_minus_right = 0;
    }
  }

  if (left != right) {
    printf("-1");
  } else {
    printf("%d", result);
  }
}
