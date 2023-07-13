
#include "iostream"
using namespace std;

int n_ways(int dist) {
  int ways[dist+1];

  ways[0] = 0;

  if (dist >= 1)
    ways[1] = 1;
  if (dist >= 2)
    ways[2] = 2;

  for (int i = 3; i <= dist; ++i) {
    ways[i] = ways[i-1] + ways[i-2] + ways[i-3];
  }

  return ways[dist];
}


int main() {

  cout << n_ways(3) << endl;
  return 0;
}
