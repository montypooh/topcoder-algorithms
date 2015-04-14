#line 5 "DifferentStrings.cpp"
#include <string>
#include <vector>
#include <cassert>
#include <iostream>

#define MAX 50

using namespace std;

class DifferentStrings {
  public:

    int getDist(string A, string B) {
        assert(A.length()==B.length());
        int dist=0;
        for(unsigned int i=0; i<A.length(); i++)
            if (A[i]!=B[i])
                dist++;
        return dist;
    }
    
    int minimize(string A, string B) {
        int minDist=MAX;
        for(unsigned int i=0; i<=B.length()-A.length(); i++) {
            string subB = B.string::substr(i,A.length());
            int thisDist = getDist(A,subB);
            if (minDist > thisDist)
                minDist = thisDist;
        }
        return minDist;
    }
};


int main() {
    string s1("adaabc");
    string s2("aababbc");
    DifferentStrings ds;
    int i = ds.minimize(s1, s2);
    cout << i << endl;
    return 1;
}
