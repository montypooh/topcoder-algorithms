#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class PeacefulLine {
  public:
    string makeLine(vector <int> x) {
        sort(x.begin(),x.end());
        int ct=1, max=0;
        for(int i=1; i<(int)x.size(); i++) {
            if (x[i]==x[i-1]) {
                ct++;
                if(ct>max)
                    max=ct;
            } else {
                ct=1;
            }
        }
        int sz=(int)x.size();
        if (sz%2==0) {
            if (max<=sz/2)
                return "possible";
        } else {
            if (max<=sz/2+1)
                return "possible";
        }
        return "impossible";
    }
};

int main() {
    PeacefulLine cn;
    vector <int> x={1,1,2,2,3,3,4,4};
    string rc = cn.makeLine(x);
    cout<<rc<<endl;

    return 1;
}
