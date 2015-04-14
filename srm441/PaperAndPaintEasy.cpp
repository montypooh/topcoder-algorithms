#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class PaperAndPaintEasy {
  public:

    long long computeArea(int width,int height,int xfold,int cnt,
                          int x1,int y1,int x2,int y2) {
        long long ret = 0;

        int divide = min(xfold, width-xfold);
        int p1dist,p2dist = 0;

        if (x1 <= divide && divide <= x2) {
            p1dist = divide - x1;
            p2dist = x2 - divide;
        } else if (x1 >= divide) {
            p1dist=0;
            p2dist=x2-x1;
        } else if (x2 <= divide) {
            p1dist=x2-x1;
            p2dist=0;
        } else {
            assert(false);
        }

        unsigned long long p1 = (unsigned long long)(y2-y1)*p1dist*(cnt+1)*2;
        unsigned long long p2 = (unsigned long long)(y2-y1)*p2dist*(cnt+1);
        ret = (unsigned long long)width*height - p1 - p2;
        return ret;
    }
};

int main() {
    PaperAndPaintEasy cn;
    long long rc = cn.computeArea(202780277,318110070,40044318,9,1144186,10474356,2849401,25512278);
    //    long long rc = cn.computeArea(585340691,793305207,505054788,2,252473233,39901138,499276031,77553381);
    cout<<rc<<endl;
    return 1;
}
