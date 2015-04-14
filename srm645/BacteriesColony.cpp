#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class BacteriesColony {
  public:
    vector <int> performTheExperiment(vector <int> colonies) {
        bool done = false;
        vector<int> inc;
        vector<int> dec;
        while(!done) {
            done = true;
            for(int i=1; i<(int)colonies.size()-1; i++) {
                if(colonies[i] < colonies[i-1] && colonies[i] < colonies[i+1]) {
                    inc.push_back(i);
                    done = false;
                }
                else if(colonies[i] > colonies[i-1] && colonies[i] > colonies[i+1]) {
                    dec.push_back(i);
                    done = false;
                }
            }
            for(int i=0; i<(int)inc.size(); i++)
                colonies[inc[i]]++;
            for(int i=0; i<(int)dec.size(); i++)
                colonies[dec[i]]--;
            inc.clear();
            dec.clear();
        }
	return colonies;
    }
};

int main() {
    BacteriesColony bc;
    vector<int> in = {1,5,4,9};
    vector<int> vi = bc.performTheExperiment(in);
    return 1;
}
