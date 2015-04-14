#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

#define INF 100000000

using namespace std;

class TheConsecutiveIntegersDivTwo {
  public:
    int find(vector <int> numbers, int k) {
        sort(numbers.begin(), numbers.end());

        int mindiff=INF;
        for(int i=0; i<(int)numbers.size()-1; i++) {
            if(mindiff>numbers[i+1]-numbers[i]) {
                mindiff = numbers[i+1]-numbers[i];
            }
        }
        if (k==2)
            return mindiff-1;
        else if(k==1)
            return 0;
        return 0;
    }
};

int main() {
    vector<int> vi = {-96, -53, 82, -24, 6, -75};
    int k = 2;
    TheConsecutiveIntegersDivTwo t;
    int i = t.find(vi,k);
    cout<<i<<endl;
    return 0;
}
