#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class TaroFillingAStringDiv2 {
  public:
    int getNumber(string S) {
        int ret=0;

        bool done = false;
        
        bool allQ = true;
        for(int i=0; i<(int)S.size(); i++) {
            if (S[i]!='?') {
                allQ = false;
            }
        }
        
        if (allQ) S[0]='A';
        
        while(!done) {
            done = true;
            for(int i=0; i<(int)S.size(); i++) {
                if (S[i]=='?') {
                    done = false;
                    if (i==0) {
                        if (S[i+1]=='A') S[i]='B';
                        else if (S[i+1]=='B') S[i]='A';
                    } else if (i==(int)S.size()-1) {
                        if (S[i-1]=='A') S[i]='B';
                        else if (S[i-1]=='B') S[i]='A';
                    } else {
                        if (S[i+1]=='A' && S[i-1]=='A') S[i]='B';
                        else if (S[i+1]=='B' && S[i-1]=='B') S[i]='A';
                        else if (S[i+1]=='A' && S[i-1]=='B') S[i]='A';
                        else if (S[i+1]=='B' && S[i-1]=='A') S[i]='A';
                        else if (S[i+1]=='A' && S[i-1]=='?') S[i]='B';
                        else if (S[i+1]=='B' && S[i-1]=='?') S[i]='A';
                        else if (S[i+1]=='?' && S[i-1]=='A') S[i]='B';
                        else if (S[i+1]=='?' && S[i-1]=='B') S[i]='A';
                    }
                }
            }
        }

        for(int i=0; i<(int)S.size()-1; i++) {
            if (S[i]==S[i+1]) {
                ret++;
            }
        }
        return ret;
    }
};

int main() {
    TaroFillingAStringDiv2 t;
    string S("??????B");
    int num = t.getNumber(S);
    cout<<num<<endl;
}
