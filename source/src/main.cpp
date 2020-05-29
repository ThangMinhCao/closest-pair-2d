#include<iostream>
#include<cmath>
#include <random>
#include "../include/2d_problem.h"
#include <fstream>
// #include "matplotlibcpp.h"

/**
 * Run in terminal to compile:
 $ g++ -c merge_sort.cpp 2d_problem.cpp main.cpp && g++ merge_sort.o 2d_problem.o main.o -o my_program && ./my_program 
 * */
int main() {
  int point_num = 100000;
  int rangeS = 0;
  int rangeE = 100000;
  srand(time(0));
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<> distr(rangeS, rangeE);
  vector<Point> points;
  clock_t tStart = clock();
  for (int i = 0; i != point_num; i++) {
    vector<double> coor{distr(generator), distr(generator)};
    points.push_back(Point(coor));
  }
  printf("Time taken to initialize: \033[0;32m%fs\033[0m\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  printf("\nThere are \033[1;31m%d\033[0m points, whose coordinates are in the interval \033[1;31m[%d, %d]\033[0m.\n\n", point_num, rangeS, rangeE);
  tStart = clock();
  DResult res = closestPair(points);
  printf("The closest pair of points is: \033[0;33m%s\033[0m and \033[0;33m%s\033[0m, with the distance \033[1;31m%f\033[0m.\n\n",
          res.first.first.toString().c_str(), res.first.second.toString().c_str(), res.second);
  printf("Time taken: \033[0;32m%fs\033[0m\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  ofstream file, fres;
  file.open("plot.txt");
  for (Point p: points) {
    file << p.coordinate[0] << "  " << p.coordinate[1] << std::endl;
  }
  file.close();
  fres.open("res.txt"); 
  fres << res.first.first.coordinate[0] << "  " << res.first.first.coordinate[1] << std::endl;
  fres << res.first.second.coordinate[0] << "  " << res.first.second.coordinate[1] << std::endl;
  fres.close();
  system("gnuplot -e \"plot 'plot.txt' using 1:2 pt 7 ps 1 title 'Points', 'res.txt' using 1:2 pt 7 ps 1 lc rgb 'red' title 'Result'; pause -1\"");
  return 0;
}
