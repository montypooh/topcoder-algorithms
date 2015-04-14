#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream> // stringstream

using namespace std;

class FormatAmt {
  public:
    string amount(int dollars, int cents) {
        string ret("");
        ret.append("$");
        stringstream ss;
        ss<<dollars;
        string buf("");
        ss>>buf;
        for(int i=0; i<(int)buf.size(); i++) {
            ret.append(1,buf[i]);
            if (((int)buf.size()-i-1)%3==0&&i!=(int)buf.size()-1)
                ret.append(",");
        }
        ret.append(".");
        ss.clear();
        ss<<cents;
        buf = "";
        if(cents<10)
            ret.append("0");
        ss>>buf;
        for(int i=0; i<(int)buf.size(); i++) {
            ret.append(1,buf[i]);
        }
        return ret;
    }
};

int main() {
    FormatAmt cn;
    int dollars=12345674;
    int cents=0;
    string rc = cn.amount(dollars,cents);
    cout<<rc<<endl;

    return 1;
}
