#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class BuildingTowers {
  public:

    long long maxHeight(int N, int K, vector<int> x, vector<int> t) {

        vector<int> bldgs;
        bldgs.push_back(0);
        for(int i=0; i<N-1; i++) {
            bldgs.push_back(K);
        }
        for(int i=0;i<(int)x.size(); i++) {
            bldgs[x[i]] = t[i];
        }
        for(int i=0; i<(int)x.size(); i++) {
            int rl = bldgs.size()-x[i];
            int ll = x[i];
            int lim = max(ll,rl);
            for(int j=1; j<lim; j++) {
                if (x[i]-j>=0) {
                    if (i>0) {
                        if (x[i]-j>x[i-1]) {
                            bldgs[x[i]-j]=bldgs[x[i]-j+1] + K;
                        }
                    } else {
                        bldgs[x[i]-j]=bldgs[x[i]-j+1] + K;
                    }
                }
                if (x[i]+j<(int)bldgs.size()) {
                    if (i<(int)bldgs.size()-1) {
                        if (x[i]+j<x[i+1]) {
                            bldgs[x[i]+j]=bldgs[x[i]+j-1]+K;
                        }
                    } else {
                        bldgs[x[i]+j]+=1;
                    }
                }
            }
        }
        
        while(true) {
            
        }
        return 0;
    }
};

int main() {
    BuildingTowers cn;
    int N=10;
    int K=1;
    vector <int> x={3,8};
    vector <int> t={1,1};
    long long rc = cn.maxHeight(N,K,x,t);
    cout<<rc<<endl;

    return 1;
}
