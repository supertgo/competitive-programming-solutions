#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>>& graph;
    vector<bool> visited;
    int count = 0;

    int findCircleNum(vector<vector<int>>& isConnected) {
      this->graph = isConnected;

      for (int i = 0; i < this->graph.size(); i++) {
        if (this->visited[i] == 0) {
          bfs(i);
          this->count++; 
        }
      } 

      return this->count;
    }

    void bfs(int v) {
      queue<int> q;

      q.push(v);
      this->visited[v] = true;

      while (!q.empty()) {
        
        int current = q.front();
        q.pop();

        for (int i = 0; i < this->graph[current].size(); i++) {
          if (this->visited[i] == 0 && this->graph[current][i] == 1) {
            q.push(i);
            this->visited[i] = true;
          }
        }
      }
    }
};
