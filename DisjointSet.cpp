#include "DisjointSet.h"

DisjointSet::DisjointSet(unsigned int num_sets)
  : num_sets(num_sets), num_elems(num_sets) {
  sets = new int[num_sets];

  for (unsigned int set_index = 0; set_index < num_sets; set_index++) {
    sets[set_index] = -1;
  }
}

DisjointSet::DisjointSet(DisjointSet &source) {
  copy_from(source);
}

DisjointSet::~DisjointSet() {
  delete[] sets;
}

DisjointSet &DisjointSet::operator=(DisjointSet const &source) {
  if (this != &source) {
    copy_from(source);
  }

  return *this;
}

void DisjointSet::union_sets(unsigned int set0, unsigned int set1) {
  // TODO
  
}

unsigned int DisjointSet::find(unsigned int set) {
  // TODO

  return 0;
}

unsigned int DisjointSet::get_num_sets() const {
  // TODO

  return 0;
}

unsigned int DisjointSet::get_num_elems() const {
  // TODO

  return 0;
}

void DisjointSet::copy_from(DisjointSet const &source) {
  // TODO

}
