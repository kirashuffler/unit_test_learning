#include <vector>
#include <math.h>
#include <stdexcept>

constexpr double e = 10e-10;

bool isZero(double value){
  return (value - e <= 0) && (value + e >= 0);
}

bool lessThanZero(double value){
  return value < -e;
}

bool greaterThanZero(double value){
  return value > e;
}

std::vector<double> solve(double a, double b, double c){
  if (isZero(a))
    throw std::runtime_error("Coefficient a must not be zero");

  std::vector<double> solutions;
  auto D = b*b - 4 * a * c;

  if (lessThanZero(D))
    return solutions;

  if (isZero(D)){
    auto x = (-b) / (2 * a);
    solutions.emplace_back(x);
    return solutions;
  }

  auto x1 = (-b + sqrt(D)) / (2 * a);
  auto x2 = (-b - sqrt(D)) / (2 * a);
  solutions.emplace_back(x1);
  solutions.emplace_back(x2);
  return solutions;
}
