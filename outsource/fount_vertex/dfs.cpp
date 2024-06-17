#include <iostream>
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> adj;
  int sink = -1;
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

  }
};

int main() {
  int n;

  std::cin >> n;

  Graph g = Graph(n);

  return 0;
}
