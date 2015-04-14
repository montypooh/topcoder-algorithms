#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class YahtzeeScore {
  public:
    int maxPoints(vector <int> toss) {
        int ret=0;
        sort(toss.begin(),toss.end());
        
        int prev;
        int maxp=0, sum=0;
        if (toss.size()>0)
            prev = toss[0];
        else
            return 0;
        for(int i=0; i<(int)toss.size(); i++) {
            if(toss[i]!=prev)
                sum=toss[i];
            else
                sum+=toss[i];
            if(sum>maxp)
                maxp = sum;
            prev=toss[i];
        }
        ret = maxp;
        return ret;
    }
};

int main() {
    YahtzeeScore ys;
    vector<int> vect = {5,3,5,3,3};
    int mp = ys.maxPoints(vect);
    cout<<mp<<endl;
    return 1;
}
