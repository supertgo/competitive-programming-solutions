#include <queue>
#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<int> visited;
  std::vector<int> parent;
  int source, destination;
public:
  Graph(int n, int source, int destination) {
    int neighbors, u;
    this->graph.resize(n);
    this->visited.resize(n, false);
    this->parent.resize(n, -1);
    this->source = source;
    this->destination = destination;

    for (int i = 0; i < n; i++) {
      std::cin >> neighbors;

      for (int j = 0; j < neighbors; j++) {
        std::cin >> u;
        this->graph[i].push_back(u);
      }
    }
  }
  void shortest_path() {
    dfs(this->source);

    std::vector<int> path;
    int current = this->destination;

    path.push_back(current);

    while(this->parent[current] != -1) {
      path.push_back(this->parent[current]);
      current = this->parent[current];
    }

    path.push_back(this->source);

    std::cout << "Path: ";

    for (int p = path.size() - 1; p >= 0; p--) {
      std::cout << p << " ";
    }

    std::cout << std::endl;
  }
 
  void dfs(int source) {
    if (source == this->destination) {
      return;
    }

    this->visited[source] = 1;

    for(int i : this->graph[source]) {
      if (!this->visited[i]) {
        this->parent[i] = source;
        dfs(i);
      }
    }
  }
};

int main () {
  int n, source, destination;
  std::cin >> n >> source >> destination;

  Graph g = Graph(n, source, destination);

  g.shortest_path();
  return 0;
}
