#pragma once

class Graph {

};

namespace graph_algs {
  template <typename Graph, template <typename E, typename W> class PriorityQueue>
  Graph kruskal(Graph const &g);

  template <typename Graph, template <typename E, typename W> class PriorityQueue>
  Graph prims(Graph const &g);
}
