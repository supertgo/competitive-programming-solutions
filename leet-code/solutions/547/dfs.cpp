#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    int provinces;
    vector<vector<int>> graph;

    int findCircleNum(vector<vector<int>>& isConnected) {
        this->visited.resize(isConnected.size(), false);
        this->provinces = 0;
        this->graph = isConnected;
        
        for (int i = 0; i < this->graph.size(); i++) {
          if (visited[i] == 0) {
            dfs(i);
            this->provinces++;
          }
    }
        
        return this->provinces;
    }

    void dfs(int v) {
      for (int i = 0; i < this->graph[v].size(); i++) {
        if (this->visited[i] == 0 && this->graph[v][i] == 1) {
            this->visited[i] = true;
            dfs(i);
        }
      }
    }
};
