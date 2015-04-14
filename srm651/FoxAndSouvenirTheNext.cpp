#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

class FoxAndSouvenirTheNext {
  public:
    bool pos(int sum, int idxs, vector<int> value) {
        int s=0, elements=0;
        for(int i=0; i<(int)value.size(); i++) {
            s+=value[i];
            elements++;
            if (elements==idxs && s==sum) return true;
            s+=value[(int)value.size()-1-i];
            elements++;
            if (elements==idxs && s==sum) return true;
        }
        return false;
    }

    string ableToSplit(vector <int> value) {
        if (value.size()%2==1) return "Impossible";
        else {
            sort(value.begin(),value.end());
            int sum=0;
            for(int i=0; i<(int)value.size(); i++) {
                sum+=value[i];
            }
            sum /= 2;
            int idxs=(int)value.size();
            idxs /= 2;
            if (pos(sum,idxs,value)) return "Possible";
            else return "Impossible";
        }
    }
};

// int main() {
//     FoxAndSouvenirTheNext cn;
//     vector<int> v = {1,2,3,4};
//     string s = cn.ableToSplit(v);
//     cout<<s<<endl;
// }
