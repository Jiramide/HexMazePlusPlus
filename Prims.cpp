#include "graph.h"

#include <set>

template <typename Graph, template <typename E, typename W> class PriorityQueue>
Graph graph_algs::prims(Graph const &g) {
  using Vertex = typename Graph::vertex_type;
  using Edge = typename Graph::edge_type;
  using Weight = typename Graph::weight_type;

  Graph mst;
  PriorityQueue<Vertex, Weight> vertices;
  std::set<Vertex> visited;

  for (unsigned int partitions = g.vertices().size(); partitions > 1; partitions--) {
    Vertex vertex = vertices.remove_min();
    visited.insert(vertex);

    for (Edge &out_edge : g.out_edges(vertex)) {
      Vertex neighbour = out_edge.get_target();

      if (visited.find(neighbour) != visited.end()) {
        if (out_edge.weight < vertices.get_weight(neighbour)) {

        }
      }
    }
  }

  return mst;
}
