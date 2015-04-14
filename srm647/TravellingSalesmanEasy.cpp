#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class TravellingSalesmanEasy {
  public:
    int maxProfitAt(int city, vector<int>& profit, vector<int> cities) {
        vector<int> currCityIdxs;
        for(int i=0; i<(int)cities.size(); i++) {
            if (city==cities[i]) {
                currCityIdxs.push_back(i);
            }
        }
        if (currCityIdxs.empty()) {
            return 0;
        }
        int max=0;
        int idx=-1;
        for(int i=0;i<(int)currCityIdxs.size(); i++) {
            if (max<profit[currCityIdxs[i]]) {
                max=profit[currCityIdxs[i]];
                idx = currCityIdxs[i];
            }
        }
        if (idx!=-1) {
            profit[idx]=0;
        }
        return max;
    }

    int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
        int ret=0;
        for(int i=0; i<(int)visit.size(); i++) {
            ret += maxProfitAt(visit[i],profit,city);
        }
        return ret;
    }
};
/*
int main() {
    TravellingSalesmanEasy cn;
    int M=6;
    vector <int> profit={77,33,10,68,71,50,89};
    vector <int> city={4,1,5,6,2,2,1};
    vector <int> visit={6,5,5,6,4};
    int rc = cn.getMaxProfit(M,profit,city,visit);
    cout<<rc<<endl;

    return 1;
}
*/
