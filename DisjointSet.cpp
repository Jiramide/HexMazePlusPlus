#include <algorithm>
#include "DisjointSet.h"

DisjointSet::DisjointSet(unsigned int num_sets)
  : num_sets(num_sets), num_elems(num_sets), sets(num_sets, -1) { }

DisjointSet::DisjointSet(DisjointSet &source) {
  copy_from(source);
}

DisjointSet &DisjointSet::operator=(DisjointSet const &source) {
  if (this != &source) {
    copy_from(source);
  }

  return *this;
}

void DisjointSet::union_sets(unsigned int set0, unsigned int set1) {
  unsigned int root0 = find(set0);
  unsigned int root1 = find(set1);

  if (root0 == root1) {
    return;
  }
  
  int rank0 = -sets[root0];
  int rank1 = -sets[root1];

  if (rank0 > rank1) {
    std::swap(root0, root1);
  }

  num_sets -= 1;
  sets[root0] = root1;

  if (rank0 == rank1) {
    sets[root1] -= 1;
  }
}

unsigned int DisjointSet::find(unsigned int set) {
  if (sets[set] < 0) {
    return set;
  }

  unsigned int root = find(sets[set]);
  sets[set] = root;

  return root;
}

bool DisjointSet::is_root(unsigned int set) {
  return find(set) == set;
}

unsigned int DisjointSet::get_num_sets() const {
  return num_sets;
}

unsigned int DisjointSet::get_num_elems() const {
  return num_elems;
}

void DisjointSet::copy_from(DisjointSet const &source) {
  num_sets = source.num_sets;
  num_elems = source.num_elems;

  sets.resize(num_sets);
  std::copy(source.sets.begin(), source.sets.end(), sets.begin());
}
