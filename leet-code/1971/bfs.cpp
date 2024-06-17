#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> graph;

public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    this->graph.resize(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      if (current == destination)
        return true;

      for (auto &i : graph[current]) {
        if (visited[i] == 0) {
          q.push(i);
          visited[i] = true;
        }
      }
    }

    return false;
  }
};
