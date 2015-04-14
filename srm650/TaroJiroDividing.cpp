#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class TaroJiroDividing {
  public:
    int getNumber(int A, int B) {
        int ret=0;
        int bigger = max(A,B);
        int smaller = min(A,B);
        while(bigger > smaller && bigger%2==0) {
            bigger /= 2;
        }
        while(bigger==smaller && bigger%2==0) {
            bigger/=2;
            smaller/=2;
            ret++;
        }
        if (bigger==smaller) {
            ret++;
        }
        return ret;
    }
};

int main() {
    TaroJiroDividing cn;
    int A=15;
    int B=18;;
    int rc = cn.getNumber(A,B);
    cout<<rc<<endl;

    return 1;
}
