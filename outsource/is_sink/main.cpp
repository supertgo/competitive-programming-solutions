#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> adj;

public:
  Graph(int n) {
    int v;
    this->adj.resize(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> v;
        this->adj[i].push_back(v);
      }
    }

    std::cout << this->dfs(n) << std::endl;
  }
  int dfs(int n) {
    int i, j;

    i = j = 0;
    while (i < n && j < n) {
      this->adj[i][j] == 0 ? j += 1 : i += 1;
    }

    if (i > n)
      return -1;

    return find_sink_vertex(i);
  }

  int find_sink_vertex(int candidate) {
    for (int j = 0; j < adj.size(); j++) {
      if (this->adj[candidate][j] == 1)
        return -1;

      if (this->adj[j][candidate] == 0 && candidate != j)
        return -1;
    }

    return candidate;
  }
};

int main() {
  int n;

  std::cin >> n;

  Graph g = Graph(n);

  return 0;
}
