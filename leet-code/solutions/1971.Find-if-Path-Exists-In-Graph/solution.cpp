#include <stack>
#include <vector>

struct FindReturn {
  int i;
  int j;
};

class Solution {
public:
  bool validPath(int n, std::vector<std::vector<int>> &edges, int source,
                 int destination) {
    std::stack<int> stack;
    FindReturn coordinates = findVertex(edges,  source,  destination);

    stack.push(edges[coordinates.i][coordinates.j]);
    while (!stack.empty()) {
      
    }
  }

  FindReturn findVertex(std::vector<std::vector<int>> &edges, int source,
                        int destination) {

    for (int i = 0; i < edges.size(); i++) {
      for (int j = 0; j < edges[i].size(); j++) {
        if (edges[i][j] == source || edges[i][j] == destination) {
          return {i, j};
        }
      }
    }
  }
};
