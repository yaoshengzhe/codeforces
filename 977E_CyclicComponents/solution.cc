#include <stdio.h>
#include <vector>

using namespace std;

constexpr int MAX_N = 300000;

vector<int> graph[MAX_N];
int degree[MAX_N];
bool visited[MAX_N];
vector<int> current_component;

void dfs(int node) {
  if (visited[node]) {
    return;
  }

  visited[node] = true;
  current_component.push_back(node);
  
  for (int neighbor : graph[node]) {
    dfs(neighbor);
  }
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);

  for (int i=0; i < m; ++i) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);

    degree[u]++;
    degree[v]++;
    
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int result = 0;
  
  for (int i=0; i < n; ++i) {
    if (!visited[i]) {
      current_component.clear();
      dfs(i);

      bool is_cycle = true;
      for (int node : current_component) {
        if (degree[node] != 2) {
          is_cycle = false;
          break;
        }
      }

      if (is_cycle) {
        result++;
      }
    }
  }

  printf("%d\n", result);
  return 0;
}
