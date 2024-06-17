#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> graph;
  vector<bool> visited;
  bool found;

public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    this->graph.resize(n);
    this->found = false;

    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    visited.resize(n);

    bfs(source, destination);
    return this->found;
  }

  void bfs(int source, int destination) {
    this->visited[source] = true;

    for (int current = 0; current < this->graph[source].size(); current++) {
      if (current == destination) {
        this->found = 1;
        break;
      }

      if (visited[current] == 0) {
        visited[current] = 1;
        bfs(current, destination);
      }
    }
  }
};
