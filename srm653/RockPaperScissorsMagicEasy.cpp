#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

#define LIMIT 2001
#define MOD 1000000007

class RockPaperScissorsMagicEasy {
  public:
    int count(vector <int> card, int score) {
        int bi[LIMIT][LIMIT+1];
        int sz_card = (int)card.size();
        if (score>sz_card) {
            return 0;
        }
        int wins = score, losses = sz_card-score;
        bi[0][0]=1;
        for(int i=1; i<=sz_card; i++) {
            bi[i][0]=bi[i][i]=1;
            for(int j=1; j<i; j++) {
                bi[i][j]=(bi[i-1][j-1]+bi[i-1][j])%MOD;
            }
        }
        int res=bi[sz_card][wins];
        while(losses--) {
            res*=2;
            res%=MOD;
        }
        return res;
    }
};

// int main() {
//     RockPaperScissorsMagicEasy cn;
//     vector <int> card;
//     int score;
//     int rc = cn.count(card, score);
//     cout<<rc<<endl;
//     return 0;
// }
