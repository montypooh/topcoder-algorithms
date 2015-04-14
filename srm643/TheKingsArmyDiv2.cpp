#include <string>
#include <vector>
#include <algorithm>

typedef unsigned int uint;

using namespace std;

class TheKingsArmyDiv2 {
  public:
    int getNumber(vector <string> state) {
        int neighbors=0;
        int happy=0;
        for (uint i=0; i<state.size(); i++)
            for (uint j=0; j<state[0].size(); j++)
                if (state[i][j]=='H') {
                    happy++;
                    if (i<state.size()-1)
                        if (state[i][j]==state[i+1][j])
                            neighbors++;
                    if (j<state[0].size()-1)
                        if (state[i][j]==state[i][j+1])
                            neighbors++;
                }
        if (neighbors>0)
            return 0;
        else if (happy==0)
            return 2;
        else if (neighbors==0 && happy>0)
            return 1;

    }
};

/*
int main() {
    string s1("SSSSS");
    string s2("SSHHS");
    string s3("SSSSS");
    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    TheKingsArmyDiv2 t;
    int ret = t.getNumber(v);
    return 1;
}
*/
