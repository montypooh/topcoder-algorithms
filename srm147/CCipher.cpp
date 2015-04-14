#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <sstream>
#include <iostream>

using namespace std;

class CCipher {
  public:
    string decode(string cipherText, int shift) {
        string ret("");
        for(int i=0; i<(int)cipherText.size(); i++) {
            char c = cipherText[i];
            for(int j=0; j<shift; j++) {
                c--;
                if(c=='A'-1)
                    c = 'Z';
            }
            stringstream ss;
            ss<<c;
            string s;
            ss>>s;
            ret.append(s);
        }
        return ret;
    }
};

int main() {
    CCipher cn;
    string cipherText("VQREQFGT");
    int shift=2;
    string rc = cn.decode(cipherText,shift);
    cout<<rc<<endl;
    return 1;
}
