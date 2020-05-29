#ifndef POINT_H
#define POINT_H
#include <vector>
#include <ostream>

class Point {
  public:
    // only index 0 and 1 of the vector for the 2d problem
    std::vector<double> coordinate;
    Point(std::vector<double> coordinate) {
      this->coordinate = coordinate;
    }
    // Point(double x, double y) {
    //   coordinate.push_back(x);
    //   coordinate.push_back(y);
    // }
    Point(){}
    std::string toString() {
      return "(" +  std::to_string(coordinate[0]) + "," + std::to_string(coordinate[1]) + ")";
    }
    friend bool operator== (const Point& p1, const Point& p2);
    friend std::ostream& operator<<(std::ostream &strm, const Point &a) {
      return strm << "(" << a.coordinate[0] << "," << a.coordinate[1] << ")";
    }
};

inline bool operator== (const Point& p1, const Point& p2) {
  return p1.coordinate == p2.coordinate;
}

#endif