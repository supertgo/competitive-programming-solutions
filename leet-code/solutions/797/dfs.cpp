#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
  vector<vector<int>> graph;
  int destination;
  int n;
  vector<vector<int>> res;
  vector<int> path;

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    this->n = graph.size();
    this->graph = graph;
    this->destination = this->n - 1;
    queue<vector<int>> q;
    vector<int> path;

    q.push({0});

    while (!q.empty()) {
      path = q.front();
      q.pop();

      if (path.back() == this->destination) {
        res.push_back(path);
      }

      for (int i; i < graph[path.back()].size(); i++) {
        vector<int> temp = path;
        temp.push_back(graph[path.back()][i]);
        q.push(temp);
      }
    }

    return this->res;
  }
};
