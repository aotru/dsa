
// 785. Is Graph Bipartite?
#include "includes.h"

using namespace std;

class Solution {
 public:
  enum Color : int8_t { uncolored, white, black };

  Color oppositeColor(Color color) { return color == white ? black : white; }

  // A graph is bipartite if it is 2-colorable.
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), uncolored);
    queue<int> frontier;

    // Graph may not be connected, so it may be necessary to perform multiple
    // breadth-first searches.
    for (int node = 0; node < graph.size(); ++node) {
      // If node has not been discovered, perform a bfs with start = node.
      if (colors[node] == uncolored) {
        colors[node] = black;
        frontier.push(node);

        while (!frontier.empty()) {
          int curr = frontier.front();
          frontier.pop();
          for (int neighbor : graph[curr]) {
            if (colors[neighbor] == uncolored) {
              frontier.push(neighbor);
              colors[neighbor] = oppositeColor(colors[curr]);
            } else if (colors[curr] == colors[neighbor]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};