//Brandon Feng yf2km threexinput.cpp 5PM
#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int);

int main() {
  int x;
  int n;
  timer t;
  
  cout << "Enter value: " << endl;
  cin >> x;
  cout << "Enter runs: " << endl;
  cin >> n;

  t.start();
  for (int i = 0; i < n; i++) {
    threexplusone(x);
  }
  t.stop();

  double time = t.getTime();

  cout << "Steps: " << threexplusone(x) << endl;
  cout << "Average time: "<< 1000*time <<" milliseconds" << endl;
  return 0;
}
