#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class PeopleCircle {
  public:
    string order(int numMales, int numFemales, int K) {
        string ret("");
        int sum = numMales+numFemales;
        for(int i=0; i<sum; i++)
            ret.append("M");

        int index=sum-1;
        for(int i=0; i<numFemales; i++) {
            for(int j=0; j<K; j++) {
                do {
                    index=(index+1)%sum;
                } while (ret[index]=='F');
            }
            ret[index]='F';
        }
        return ret;
    }
};

int main() {
    PeopleCircle pc;
    int numMales=25,numFemales=25,K=1000;
    string s = pc.order(numMales,numFemales,K);
    cout<<s<<endl;
    return 1;
}
