#include <queue>
#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<bool> visited;
  int count = 0;

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
  }

  void dfs(int source) {
    this->visited[source] = 1;
    this->count++;

    for (int i: this->graph[source]) {
      if (!this->visited[i]) {
        dfs(i);
      }
    }
  }

  bool is_connected() {
    dfs(0);
    
    return this->count == this->graph.size();
  }
};

int main (int argc, char *argv[]) {
  int n;

  std::cin >> n;

  Graph g = Graph(n);

  std::cout << g.is_connected() << std::endl;
  return 0;
}
