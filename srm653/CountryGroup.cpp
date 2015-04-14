#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class CountryGroup {
  public:
    int solve(vector <int> a) {
        int types=0;
        int sz=(int)a.size();
        for(int i=0; i<sz; ++i) {
            int current=a[i];
            int counter=1;
            types++;
            while (counter<current) {
                counter++;
                i++;
                if (a[i]!=current || i==sz) {
                    return -1;
                }
            }
        }
        return types;
    }
};

// int main() {
//     CountryGroup cn;
//     vector <int> a = {2,2,3,3,3};
//     int rc = cn.solve(a);
//     cout<<rc<<endl;
// }
