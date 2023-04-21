#pragma once

#include <vector>

class DisjointSet {
public:
  DisjointSet(unsigned int num_sets);
  DisjointSet(DisjointSet &source);
  
  ~DisjointSet();

  DisjointSet &operator=(DisjointSet const &source);

  void union_sets(unsigned int set0, unsigned int set1);

  unsigned int find(unsigned int set);
  bool is_root(unsigned int set);

  unsigned int get_num_sets() const;
  unsigned int get_num_elems() const;

private:
  void copy_from(DisjointSet const &source);

  unsigned int num_sets;
  unsigned int num_elems;
  std::vector<int> sets;
};
