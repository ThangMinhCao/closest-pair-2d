#include<iostream>
#include<cmath>
#include<utility>
#include<limits>
#include "../include/2d_problem.h"
#include <algorithm>
// #include "merge_sort.h"
// #include "point.h"
// #include<vector>

DResult dist(Point p, Point q) {
  double xDiff = p.coordinate[0] - q.coordinate[0];
  double yDiff = p.coordinate[1] - q.coordinate[1];
  return std::pair<std::pair<Point, Point>, double>
          {std::pair<Point, Point> {p, q}, sqrt(xDiff * xDiff + yDiff * yDiff)};
}
void print_points(vector<Point> points);

double compareX(Point p, Point q) {
  return p.coordinate[0] < q.coordinate[0];
}

double compareY(Point p, Point q) {
  return p.coordinate[1] < q.coordinate[1];
}

DResult closestPair(vector<Point>& L) {
  std::sort(L.begin(), L.end(), compareX);
  vector<Point> res_points; 
  DResult d, d1, d2;
  int n = L.size();
  int mid_point = n / 2;
  double mid = L[mid_point].coordinate[0];
  if (n <= 1) {
    return DResult
            {std::pair<Point, Point>{Point(), Point()}, std::numeric_limits<double>::infinity()}; 
  } else if (n == 2) {
    return dist(L[0], L[1]);
  }
  // merge_sort(L, true);
  vector<Point> L1, L2, L_strip;
  for (int i = 0; i < n; i++) {
    if (i < mid_point) {
      L1.push_back(L[i]);
    } else {
      L2.push_back(L[i]);
    }
  }
  d1 = closestPair(L1);
  d2 = closestPair(L2);
  d = d1.second < d2.second ? d1 : d2;

  for (int i = L1.size() - 1; i >= 0; i--) {
    if (L1[i].coordinate[0] > mid - d.second) {
      L_strip.push_back(L1[i]);
    }
  }
  for (int i = 0; i < L2.size(); i++) {
    if (L2[i].coordinate[0] < mid + d.second) {
      L_strip.push_back(L2[i]);
    }
  }
  sort(L_strip.begin(), L_strip.end(), compareY);
  L = merge(L1, L2, false);
  if (L_strip.size() <= 1) {
    return d;
  } else {
    DResult d_strip = DResult
        {std::pair<Point, Point>{Point(), Point()}, std::numeric_limits<double>::infinity()};
    for (int i = 0; i < L_strip.size(); i++) {
      // for (int j = i + 1; j < L_strip.size(); j++) {
      for (int j = i + 1; j < i + 8; j++) {
        if (j >= L_strip.size()) {
          break;
        }
        DResult dist_successor = dist(L_strip[i], L_strip[j]);
        d_strip = dist_successor.second < d_strip.second ? dist_successor : d_strip;
      }
    }
    return d.second < d_strip.second ? d : d_strip;
  }
}


void print_points(vector<Point> points) {
  for (Point p: points) {
    std::cout << p; 
  }
  std::cout << endl;
}
