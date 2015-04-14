#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

int difference(vector<int> v1, vector<int> v2) {
    assert(v1.size()==v2.size());
    int res = 0;
    for(int i=0; i<(int)v1.size(); i++)
        if (v1[i]!=v2[i])
            res++;
    return res;
}

bool sortByDiff(pair<vector<int>,vector<int> > p1, pair<vector<int>,vector<int> > p2) {
    return difference(p1.first, p1.second) < difference(p2.first, p2.second);
}

class PerfectPermutationHard {
  public:

    vector<int> makeChild(vector<int> parent) {
        vector<int> res;
        res.push_back(0);
        for (int i=1; i<(int)parent.size(); i++)
            res.push_back(parent[res[i-1]]);
        return res;
    }

    bool checkDuplicates(vector<int> child) {
        sort(child.begin(),child.end());
        for(int i=0; i<(int)child.size()-1; i++)
            if (child[i]==child[i+1])
                return false;
        return true;
    }

    int getFactorial(int x) {
        for(int i=x-1; i>1; i--)
            x*=i;
        return x;
    }

    vector<int> reorder(vector<int> P) {

        vector<int> buf = P;
        vector<pair<vector<int>,vector<int> > > candidates;
        long long permutations=getFactorial((int)P.size());
        
        for(long long i=0; i<permutations; i++) {
            next_permutation(buf.begin(), buf.end());
            vector<int> child=makeChild(buf);
            bool isPerfect=checkDuplicates(child);
            if (isPerfect) {
                pair<vector<int>,vector<int> > pc(buf,P);
                candidates.push_back(pc);
            }
        }
        
        sort(candidates.begin(), candidates.end(), sortByDiff);
        
        vector<vector<int> > candidates2;
        for (int i=0; i<(int)candidates.size()-1; i++) {
            if (difference(candidates[i].first, candidates[i].second) ==
                difference(candidates[i+1].first, candidates[i+1].second)) {
                candidates2.push_back(candidates[i].first);
            } else {
                candidates2.push_back(candidates[i].first);
                break;
            }
        }

        vector<int> res;

        if ((int)candidates2.size() > 1) {
            sort(candidates2.begin(),candidates2.end());
            res = *candidates2.begin();
        } else {
            res = candidates.begin()->first;
        }
        return res;
    }
};

int main() {
    PerfectPermutationHard pph;
    vector<int> v = {2,7,3,0,6,4,5,1};

    v = pph.reorder(v);
    for(int i=0; i<(int)v.size(); i++) cout<<v[i]<<","<<endl;
    return 1;
}
