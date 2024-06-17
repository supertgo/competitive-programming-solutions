#include <queue>
#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;  
  std::vector<int> visited;
  int count = 1;

  void bfs(int source) {
    
    std::queue<int> q;

    this->visited[source] = 1;
    q.push(source);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int v: this->graph[current]) {
        if (!this->visited[v]) {
          this->visited[v] = 1;
          this->count++;
          q.push(v);
        }
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
        this->graph[i].push_back(u);
      }
    }
  }

  bool is_connected() {
    bfs(0);

    return this->count == this->graph.size();
  }
};

int main () {
  int n;

  std::cin >> n;
  Graph g = Graph(n);

  std::cout << g.is_connected() << std::endl;

  return 0;
}
