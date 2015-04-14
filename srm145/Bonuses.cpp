#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class Bonuses {
  public:
    vector <int> getDivision(vector <int> points) {
        vector<int> ret;
        int sum=0;
        for(int i=0; i<(int)points.size(); i++) {
            sum+=points[i];
        }
        int rem=100;
        for(int i=0; i<(int)points.size(); i++) {
            ret.push_back(100*points[i]/sum);
            rem -= ret[i];
        }

        vector<int> retcopy = ret;
        vector<int> fedIndex;

        for(int i=0; i<rem; i++) {
            // find index with highest points
            int highestIndex=0;
            int highestPoint=0;
            for(int j=0; j<(int)points.size(); j++) {
                if(points[j]>highestPoint &&
                   fedIndex.end() == find(fedIndex.begin(),
                                          fedIndex.end(),
                                          j)) {
                    highestIndex = j;
                    highestPoint = points[j];
                }
            }
            fedIndex.push_back(highestIndex);
            // increment highest point index
            ret[highestIndex]+=1;
        }
        return ret;
    }

};

int main() {
    Bonuses b;
    vector<int> in = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
                      255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};

    vector<int> out = b.getDivision(in);
    for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<",";
    return 1;
}

