#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

#define EPS 1e-9

class Inventory {
  public:
    int monthlyOrder(vector <int> sales, vector <int> daysAvailable) {
        int sz=(int)sales.size();
        double ret=0;
        int c=0;
        for(int i=0; i<sz; i++) {
            if (daysAvailable[i]!=0) {
                ret += (double)sales[i]*((double)30/daysAvailable[i]);
                c++;
            }
        }
        ret /= c;
        ret -= EPS;
        ret = ceil(ret);
        return ret;
    }
};

int main() {
    Inventory cn;
    vector <int> sales={75,120,0,93};
    vector <int> daysAvailable={24,30,0,30};
    int rc = cn.monthlyOrder(sales,daysAvailable);
    cout<<rc<<endl;

    return 1;
}
