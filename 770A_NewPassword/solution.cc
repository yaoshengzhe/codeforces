#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int k;
  scanf("%d", &k);

  string result;

  for (int i=0; i < n; i+=k) {
    for (int j=0; j < k; j++) {
      if (i + j == n) {
        break;
      }
      result += ('a'+j);
    }
  }
  
  printf("%s", result.c_str());
}
