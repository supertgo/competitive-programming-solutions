#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Graph {
private:
  std::vector<std::vector<int>> graph;
  std::vector<bool> visited;
  std::vector<int> predecessor;
  int source;
  int destination;

public:
  Graph(int n, int source, int destination) {
    int neighbors, u;
    this->graph.resize(n);
    this->visited.resize(n, false);
    this->predecessor.resize(n, -1);
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
    std::queue<int> q;
    q.push(this->source);
    this->visited[this->source] = true;

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int i : this->graph[current]) {

        if (!this->visited[i]) {
          this->visited[i] = true;
          this->predecessor[i] = current;
          q.push(i);

          if (i == this->destination) {
            break;
          }
        }
      }
    }

    std::vector<int> path;
    int current = this->destination;
    path.push_back(current);

    while(this->predecessor[current] != 1) {
      path.push_back(this->predecessor[current]);
      current = this->predecessor[current];
    }

    path.push_back(this->source);
    std::cout << "The path is: ";

    for (int p = path.size() - 1; p >= 0; p--) {
      std::cout << path[p] << " ";
    }

    std::cout << std::endl;
    std::cout << "of size: " << this->predecessor.size() << std::endl;
  }
};

int main() {
  int n, source, destination;
  std::cin >> n >> source >> destination;

  Graph g = Graph(n, source, destination);

  g.shortest_path();
  return 0;
}
