#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct pairfind {
    pairfind(int a, int b) {
        _a = a;
        _b = b;
    }
    bool operator() (const pair<int,int>& elem) const {
        if ((_a==elem.first && _b==elem.second) || (_b==elem.first && _a==elem.second))
            return true;
        else
            return false;
    }
  private:
    int _a;
    int _b;
};

class OkonomiyakiShop {
  public:
    int count(vector <int> osize, int K) {
        int res=0;
        vector<pair<int,int> > checked;
        for(int i=0; i<(int)osize.size(); i++) {
            for(int j=0; j<(int)osize.size(); j++) {
                int diff = abs(osize[i]-osize[j]);
                if (diff <= 3 && checked.end() == find_if(checked.begin(),checked.end(),pairfind(i,j))) {
                    pair<int,int> p(i,j);
                    checked.push_back(p);
                    res++;
                }
            }
        }
        return (int)checked.size();
    }
};

int main() {
    vector<int> v = {1,1,3,3,3};
    int k = 2;
    OkonomiyakiShop os;
    int c = os.count(v,k);
    cout<<c<<endl;
    return c;
}
