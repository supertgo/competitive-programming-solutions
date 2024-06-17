#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<int> visited;

public:
  Graph(int n) {
    graph.resize(n);
    visited.resize(n);

    int neighbors, u;

    for (int i = 0; i < n; i++) {
      std::cin >> neighbors;
      for (int j = 0; j < neighbors; j++) {
        std::cin >> u;
        this->graph[i].push_back(u);
      }
    }

    this->connected_components();
  }

  void connected_components() {
    std::vector<int> path;

    for (int i = 0; i < this->graph.size(); i++) {
      if (!this->visited[i]) {
        std::cout << "called" << std::endl;
        path.clear();
        bfs(i, path);

        for (int p = 0; p < path.size(); p++) {
          std::cout << path[p] << " ";
        }

        std::cout << std::endl;
      }
    }
  }

  void bfs(int source, std::vector<int> &path) {
    std::queue<int> q;

    q.push(source);
    path.push_back(source);
    this->visited[source] = 1;

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int i : graph[current]) {
        if (!this->visited[i]) {
          this->visited[i] = 1;
          q.push(i);
          path.push_back(i);
        }
      }
    }
  }
};

int main() {
  int v;

  std::cin >> v;

  Graph g = Graph(v);

  return 0;
}
