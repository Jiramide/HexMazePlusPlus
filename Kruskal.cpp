#include "graph.h"

#include "DisjointSet.h"

template <typename Graph, template <typename E, typename W> class PriorityQueue>
Graph graph_algs::kruskal(Graph const &g) {
  using Vertex = typename Graph::vertex_type;
  using Edge = typename Graph::edge_type;
  using Weight = typename Edge::weight_type;

  Graph mst;
  PriorityQueue<Edge, Weight> edges;
  DisjointSet sets(g.vertices().size());

  while (sets.get_num_sets() > 1) {
    Edge min_edge = edges.remove_min();

    Vertex source = min_edge.get_source();
    Vertex target = min_edge.get_target();

    if (sets.find(source) != sets.find(target)) {
      sets.union_sets(source, target);
      mst.add_edge(min_edge, min_edge.weight);
    }
  }

  return mst;
}
