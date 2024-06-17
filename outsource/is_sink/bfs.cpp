#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<int> visited;
  std::vector<int> snapshot;
  int sink = -1;

public:
  Graph(int n) {
    int neighbors, u;
    this->graph.resize(n);
    this->visited.resize(n, 0);

    for (int i = 0; i < n; i++) {
      std::cin >> neighbors;

      for (int j = 0; j < neighbors; j++) {
        std::cin >> u;
        this->graph[i].push_back(u);
      }
    }

    this->bfs(0);

    std::cout << this->sink << std::endl;
  }

  void bfs(int n) {
    std::queue<int> q;

    q.push(n);
    this->visited[n] = 1;

    while (!q.empty()) {
      int current = q.front();

      q.pop();

      for (int i : this->graph[current]) {
        if (!this->visited[i]) {
          q.push(i);
          this->visited[i] += 1;
        }
      }
    }

    for (int i = 0; i < this->graph.size(); i++) {
      if (this->graph[i].empty() && this->visited[i] == 1) {
        this->sink = i;
        break;
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
