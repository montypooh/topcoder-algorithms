#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class DivisorDigits {
  public:
    int howMany(int number) {
        stringstream ss;
        ss<<number;
        string s;
        ss>>s;
        int sz = s.size();
        vector<int> vi;
        for(int i=0; i<sz; i++) {
            if (s[i]!='0')
                vi.push_back(s[i]-'0');
        }
        int ret=0;
        for(int i=0; i<(int)vi.size(); i++) {
            if(number%vi[i]==0)
                ret++;
        }
        return ret;
    }
};

int main() {
    DivisorDigits cn;
    int number=730000000;
    int rc = cn.howMany(number);
    cout<<rc<<endl;

    return 1;
}
