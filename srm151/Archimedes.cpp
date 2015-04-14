#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class Archimedes {
  public:
    double approximatePi(int numSides) {
        double ret=0;
        double base = sin(M_PI/numSides);
        double perimeter = numSides*2*base;
        ret = perimeter / 2; // radius 1
        return ret;
    }
};

int main() {
    Archimedes cn;
    int numSides=17280;
    double rc = cn.approximatePi(numSides);
    cout<<rc<<endl;

    return 1;
}


//Powered by FileEdit
