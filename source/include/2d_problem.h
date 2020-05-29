#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H
#include "merge_sort.h"
#include <vector>

typedef std::pair<std::pair<Point, Point>, double> DResult;

DResult closestPair(vector<Point>& L);
void print_points(vector<Point> points);

#endif