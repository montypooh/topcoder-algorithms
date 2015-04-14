#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

class FoldingPaper2 {
  public:
    int getDist(int a, int b)
    { // calculate # of folds required from length a to b
        if (a==b) return 0;
        else if (b>=(a+1)/2) return 1;
        else return (1+getDist((a+1)/2, b));
    }
    int solve(int W, int H, int A)
    {
        vector<pair<int,int> > factors;
        for(int i=1; i<=A; ++i) if (A%i==0) factors.push_back(pair<int,int>(A/i,i));
        int sz_factors = (int)factors.size();
        int mindist=INT_MAX;
        int w = max(W,H);
        int h = min(W,H);
        for(int i=0; i<sz_factors; ++i) {
            int fw = factors[i].first;
            int fh = factors[i].second;
            if (w>=fw && h>=fh) mindist = min(mindist, getDist(w,fw)+getDist(h,fh));
        }
        if (mindist==INT_MAX) return -1;
        return mindist;
    }
};

// int main() {
//     FoldingPaper2 cn;
//     int W=207, H=202, A=10403;
//     int rc = cn.solve(W, H, A);
//     cout<<rc<<endl;
//     return 0;
// }
