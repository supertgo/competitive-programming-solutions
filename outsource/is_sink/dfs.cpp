#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<int> visited;
  int sink = -1;

public:
  Graph(int n) {
    int neighbors, u;
    this->graph.resize(n);
    this->visited.resize(n, false);

    for (int i = 0; i < n; i++) {
      std::cin >> neighbors;

      for (int j = 0; j < neighbors; j++) {
        std::cin >> u;
        this->graph[i].push_back(u);
      }
    }

    this->dfs(0);
    std::cout << this->sink << std::endl;
  }

  void dfs(int n) {
    if (graph[n].size() == 0) {
      this->sink = n;
      return;
    }

    visited[n] = 1;

    for (int v : this->graph[n]) {
      if (!visited[v]) {
        this->sink = v;
        dfs(v);
      }
    }
  }
};

int main() {
  int n;

  std::cin >> n;

  Graph g = Graph(n);

  return 0;
}
