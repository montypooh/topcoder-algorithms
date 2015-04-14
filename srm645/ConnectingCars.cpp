#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    return p1.first<p2.first;
}

class ConnectingCars {
  public:
    long long minimizeCost(vector <int> positions, vector <int> lengths) {
        long long ret;

        // sort by length for both of them
        vector<pair<int,int> > pl;
        for(int i=0; i<(int)positions.size(); i++) {
            pl.push_back(pair<int,int>(positions[i],lengths[i]));
        }
        sort(pl.begin(),pl.end(),comp);
        vector<int> pp, ll;
        for(int i=0; i<(int)pl.size(); i++) {
            pp.push_back(pl[0].first);
            ll.push_back(pl[0].second);
        }
        
        // push everything towards the center
        // if even numbers, push the one on the right
        ret=0;
        int sz = (int)pl.size();
        int left = pl[sz/2].first;
        for(int i=sz/2-1; i>=0; i--) {
            ret += left - (pl[i].first+pl[i].second);
            left -= pl[i].second;
        }
        int right = pl[sz/2].first+pl[sz/2].second;
        for(int i=sz/2+1; i<sz; i++) {
            ret += pl[i].first - right;
            right += pl[i].second;
        }

        return ret;
    }
};

int main() {
    ConnectingCars cc;
    vector<int> p={5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427};
    vector<int> l={42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540};
    long long cost = cc.minimizeCost(p,l);
    cout<<cost<<endl;
    return cost;
}
