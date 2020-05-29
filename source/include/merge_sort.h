#ifndef MERGESORT_H
#define MERGESORT_H
#include "point.h"
#include <vector>

using namespace std;

vector<Point> merge_sort(vector<Point>& L, bool x);
vector<Point> merge(vector<Point> const &L1, vector<Point> const &L2, bool x);

#endif