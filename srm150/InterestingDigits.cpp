#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class InterestingDigits {
  public:
    bool checkDigitSum(int multiple, int digit, int base) {
        int tmp=multiple;
        int digitSum=0;
        while(tmp>0) {
            digitSum += tmp%base;
            tmp/=base;
        }
        if (digitSum%digit==0) return true;
        return false;
    }
    bool isInteresting(int digit, int base) {
        bool ret = true;
        int limit = pow(base, 3);
        // check all multiples and its sums
        for(int i=digit; i<limit; i+=digit) {
            if (!checkDigitSum(i, digit, base)) {
                ret = false;
                break;
            }
        }
        return ret;
    }
    vector <int> digits(int base) {
        vector<int> ret;
        for(int i=2; i<base; i++) { // try all digits
            if (isInteresting(i, base)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

// int main() {
//     InterestingDigits cn;
//     int base=10;
//     vector <int> rc = cn.digits(base);
//     int sz=(int)rc.size();
//     for(int i=0; i<sz; ++i) {
//         cout<<rc[i]<<","<<endl;
//     }
//     return 0;
// }
