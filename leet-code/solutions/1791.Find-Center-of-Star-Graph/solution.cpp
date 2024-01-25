#include <iostream>
#include <vector>

class Solution {
private:
  int *visited;

public:
  int check(int currentI, int currentJ, std::vector<std::vector<int>> &edges) {
    int matches = 1;
    for (int i = 0; i < edges.size(); i++) {
      if (currentI == i)
        continue;

      for 
      for (int j = 0; j < edges[i].size(); j++) {
        if (edges[currentI][currentJ] == edges[i][j]) {
          matches++;
          continue;
        }
      }
    }
    return matches == edges.size() ? 1 : 0;
  }
  int findCenter(std::vector<std::vector<int>> &edges) {
    this->visited = new int[edges.size()];
    int pos = 0;

    for (int i = 0; i < edges.size(); i++) {
      for (int j = 0; j < edges[i].size(); j++) {
        if (check(i, j, edges) == 1)
          return edges[i][j];
        
        this->visited[pos++] = edges[i][j];
        continue;
      }
    }

    return 0;
  }
};

