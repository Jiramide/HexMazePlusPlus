#pragma once

#include <list>
#include <vector>
#include <map>

template <typename V>
class UnweightedEdge {
public:
  using weight_type = void;

  UnweightedEdge(V source, V target)
    : source(source), target(target)
  {
    // nothing ...
  };

  V get_source() const {
    return source;
  };

  V get_target() const {
    return target;
  };

  weight_type get_weight() const {
    return weight_type();
  };

  bool operator==(const UnweightedEdge<V> &rhs) const {
    return source == rhs.source
      && target == rhs.target;
  }

private:
  V source;
  V target;
};

template <typename V, typename E>
class Graph {
public:
  using vertex_type = V;
  using edge_type = E;
  

private:
  class EdgePointer {
    using EdgePointerIterator = typename std::list<EdgePointer>::iterator;

  public:
    E edge;
    EdgePointerIterator sourcePosition;
    EdgePointerIterator targetPosition;
    
    void remove() {
      sourcePosition.erase();
      targetPosition.erase();
    }
  };

  void remove_edge(E edge) {
    V source = edge.getSource();
    V target = edge.getTarget();

    const std::list<EdgePointer> &search_list
      = vertices[source].size() > vertices[target].size()
      ? vertices[target]
      : vertices[source];

    auto search_iterator = search_list.begin();

    for (; search_iterator != search_list.end(); search_iterator++) {
      if (search_iterator->edge == edge) {
        search_iterator->remove();
        search_iterator.erase();

        break;
      }
    }
  }

  std::map<V, std::list<EdgePointer>> vertices;
  std::vector<EdgePointer> edges;
};

namespace graph_algs {
  template <typename Graph, template <typename E, typename W> class PriorityQueue>
  Graph kruskal(Graph const &g);

  template <typename Graph, template <typename E, typename W> class PriorityQueue>
  Graph prims(Graph const &g);
}
