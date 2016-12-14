#include <iostream>
#include <stdlib.h>
#include <climits>
using namespace std;
// A program that tries to find the roots of a function.
// initial function defined and given

// Calculates the y value of the given x value based on the function x^3-2.75x+1.2
float f(float x) {
  return (x*x*x - 2.75*x + 1.2);
}

float rootFind(float left, float right, float precision) {

  // checks if it is a valid interval such that both left and right are not
  // positive or negative.
  if (f(left) <= 0 && f(right) <= 0 || f(left) > 0 && f(right) > 0) {
    cerr << "Error: invalid interval";
    return INT_MIN;
  }
  float mid = (left+right)/2; // calculates the new midpoint
  // continually halves the interval if the root is not found
  while (f(mid) > precision || f(mid) < -precision) {
    mid = (left+right)/2; // calculates the new midpoint
    cout << mid;

      if (f(left) < 0) {
        if (f(mid) < 0) {
          left = mid;
        } else {
          right = mid;
        }
      } else {
        if (f(mid) > 0) {
          left = mid;
        } else {
          right = mid;
        }
      }
  }
  return mid;
}

int main() {
  float b = rootFind(-100, 100, 0.00001);
  cout << endl;
  cout << b;
}
