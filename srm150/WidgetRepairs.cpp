#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class WidgetRepairs {
  public:
    int days(vector <int> arrivals, int numPerDay) {
        int ret=0;
        int i=0;
        int currwork = 0;
        int numArrivals = (int)arrivals.size();
        while(i<numArrivals || currwork>0) {
            if (i<numArrivals) currwork += arrivals[i];
            if (currwork > 0) ret++;
            currwork -= numPerDay;
            if (currwork < 0) currwork = 0;
            if (i<numArrivals) i++;
        }
        return ret;
    }
};

/*
int main() {
    WidgetRepairs cn;
    vector <int> arrivals = {6,5,4,3,2,1,0,0,1,2,3,4,5,6};
    int numPerDay=3;
    int rc = cn.days(arrivals,numPerDay);
    cout<<rc<<endl;
    return 1;
}
*/
