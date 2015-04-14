#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class RectangularGrid {
  public:
    long long countRectangles(int width, int height) {
        long long ret=0;
        for(int w=1; w<=width; w++) {
            for(int h=1; h<=height; h++) {
                if(w==h)
                    continue;
                ret+=(width-w+1)*(height-h+1);
            }
        }
        return ret;
    }
};


int main() {
    RectangularGrid rg;
    long long count = rg.countRectangles(10,10);
    cout<<count<<endl;
    return 1;
}
