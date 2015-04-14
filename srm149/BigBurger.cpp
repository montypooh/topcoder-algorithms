#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class BigBurger {
  public:
    int maxWait(vector <int> arrival, vector <int> service) {
        int max=0;
        int prev=0;
        for(int i=1; i<(int)arrival.size(); i++) {
            int wt=arrival[i-1]+service[i-1]-arrival[i]+prev;
            if (wt>max)
                max = wt;
            if (wt<0)
                wt = 0;
            prev = wt;
        }
        return max;
    }
};

int main() {
    BigBurger cn;
    vector <int> arrival = {3,3,9};
    vector <int> service = {2,15,14};
    
    int rc = cn.maxWait(arrival,service);
    cout<<rc<<endl;

    return 1;
}
