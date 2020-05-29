#include "../include/merge_sort.h"
// #include "point.h"
// #include <vector>
#include <cmath>

using namespace std;

vector<Point> merge(vector<Point> const &L1, vector<Point> const &L2, bool x);

vector<Point> merge_sort(vector<Point> &L, bool x) {
  if (L.size() <= 1) {
    return L;
  }

  vector<Point> L1, L2;
  int mid = ceil(L.size() / 2);

  for (auto i = L.begin(); i != L.begin() + mid; i++) {
    L1.push_back(*i);
  }

  for (auto i = L.begin() + mid; i != L.end(); i++) {
    L2.push_back(*i);
  }

  L1 = merge_sort(L1, x);
  L2 = merge_sort(L2, x);
  L = merge(L1, L2, x);
  return L;
}

vector<Point> merge(vector<Point> const &L1, vector<Point> const &L2, bool x) {
  int coor = x ? 0 : 1;
  vector<Point> res;
  int L1_ptr = 0;
  int L2_ptr = 0;
  while (L1_ptr < L1.size() and L2_ptr < L2.size()) {
    if (L1[L1_ptr].coordinate[coor] <= L2[L2_ptr].coordinate[coor]) {
      res.push_back(L1[L1_ptr++]);
    } else {
      res.push_back(L2[L2_ptr++]);
    }
  }
  if (L1_ptr == L1.size()) {
    res.insert(res.end(), L2.begin() + L2_ptr, L2.end());
  } else if (L2_ptr == L2.size()) {
    res.insert(res.end(), L1.begin() + L1_ptr, L1.end());
  }
  return res;
}
