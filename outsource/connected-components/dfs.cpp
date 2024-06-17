#include <queue>
#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<int> visited;

  void connected_components() {
    std::vector<int> path;

    for (int i = 0; i < this->graph.size(); i++) {
      if (!this->visited[i]) {
        path.clear();
        this->dfs(i, path);

        for (int p : path) {
          std::cout << p << " ";
        }

        std::cout << std::endl;
      }
    }
  }

  void dfs(int source, std::vector<int> &path) {
    this->visited[source] = 1;
    path.push_back(source);

    for (int u: graph[source]) {
      if (!this->visited[u]) {
        dfs(u, path);
      }
    }
  }

public:
  Graph(int n) {
    int neighbors, u;
    this->graph.resize(n);
    this->visited.resize(n, false);


    for (int i = 0; i < n; i++) {
      std::cin >> neighbors;

      for (int j = 0; j < neighbors; j++) {
        std::cin >> u;
        graph[i].push_back(u);
      }
    }

    this->connected_components();
  }
};

int main () {
  int n;
  std::cin >> n;

  Graph g = Graph(n);
  
  return 0;
}
