#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define MAX_N 1000

int acc_count[MAX_N];

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int k;
  scanf("%d", &k);

  char pwd[101];

  int correct_len = 0;
    
  for (int i=0; i < n+1; i++) {
      scanf("%s", pwd);
      string str_pwd = string(pwd);

      if (i == n) {
        correct_len = str_pwd.size();
        break;
      }
      
      acc_count[str_pwd.size()]++;
  }

  for (int i=1; i < MAX_N; i++) {
    acc_count[i] = acc_count[i] + acc_count[i-1]; 
  }

  int best_result = 1;
  best_result += acc_count[correct_len-1];
  best_result += (5 * (acc_count[correct_len-1] / k));

  int worst_result = 1;
  worst_result += (acc_count[correct_len] - 1);
  worst_result += (5 * ((acc_count[correct_len]-1) / k));
  
  
  printf("%d %d", best_result, worst_result);
}
