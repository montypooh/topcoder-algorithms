#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

class BinaryCode {

  public:
    vector<string> decode(string str) {
        vector<string> res;
        vector<int> q(str.size(),0);
            
        // convert string to int
        for(int i=0; i<(int)str.size(); i++) {
            stringstream ss(str.substr(i,1));
            ss>>q[i];
        }

        for(int p0=0; p0<=1; p0++) {
            vector<int> p;
            p.push_back(p0);
            bool valid = true;
            for(int i=1; i<(int)str.size(); i++) {
                int currP;
                if(i==1)
                    currP=q[i-1]-p[i-1];
                else
                    currP=q[i-1]-p[i-1]-p[i-2];
                if(currP != 0 && currP != 1) {
                    valid = false;
                    break;
                }
                p.push_back(currP);
            }
            for(int i=0; i<(int)str.size(); i++) {
                if(i==0) {
                    if(q[i] != p[i] + p[i+1]) {
                        valid = false;
                    }
                }
                else if(i==(int)str.size()-1) {
                    if(q[i] != p[i-1] + p[i]) {
                        valid = false;
                    }
                }
                else {
                    if(q[i] != p[i-1] + p[i] + p[i+1]) {
                        valid = false;
                    }
                }
            }
                
            if(!valid) {
                res.push_back("NONE");
            } else {
                string s;
                for(int i=0; i<(int)str.size(); i++) {
                    stringstream ss;
                    ss<<p[i];
                    s.append(ss.str());
                }
                res.push_back(s);
            }
        }
        return res;
    }
};

/*
int main() {

    string s("0");
    BinaryCode bc;
    vector<string> decoded = bc.decode(s);
    cout << decoded[0] << endl;
    cout << decoded[1] << endl;

    return 1;
}
// Powered by FileEdit
*/


// Powered by FileEdit
