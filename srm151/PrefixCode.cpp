#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class PrefixCode {
  public:
    int findIndex(vector<string> words, string word) {
        int ret = -1;
        for(int i=0; i<(int)words.size(); i++) {
            if (word==words[i]) {
                ret = i;
                break;
            }
        }
        return ret;
    }

    string isOne(vector <string> words) {
        string ret("Yes");
        vector<string> wordss;
        for(int i=0; i<(int)words.size(); i++) wordss.push_back(words[i]);
        sort(wordss.begin(),wordss.end());
        int currIdx=51;
        for(int i=0; i<(int)wordss.size()-1;i++) {
            for(int j=i+1; j<(int)wordss.size(); j++) {
                if (wordss[j].substr(0,wordss[i].size())==wordss[i]) {
                    int idx = findIndex(words, wordss[i]);
                    if (idx<currIdx) {
                        ret="";
                        ret.append("No, ");
                        stringstream ss;
                        ss<<idx;
                        ret.append(ss.str());
                        currIdx=idx;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    PrefixCode cn;
    vector <string> words = {"10001","011","100","001","10"};
    string rc = cn.isOne(words);
    cout<<rc<<endl;

    return 1;
}
