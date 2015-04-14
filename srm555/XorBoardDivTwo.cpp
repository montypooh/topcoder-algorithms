#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class XorBoardDivTwo {
  public:
    int flip(int row, int col, vector<string> board) {
        int sz_row = (int)board.size();
        int sz_col = (int)board[0].size();
        for(int j=0; j<sz_col; j++) board[row][j] = (board[row][j]=='0') ? '1':'0';
        for(int i=0; i<sz_row; i++) board[i][col] = (board[i][col]=='0') ? '1':'0';
        int ret=0;
        for(int i=0; i<sz_row; i++) {
            for(int j=0; j<sz_col; j++) {
                if (board[i][j]=='1') ret++;
            }
        }
        return ret;
    }
    int theMax(vector <string> board) {
        int sz_row = (int)board.size();
        int sz_col = (int)board[0].size();
        int ret=0;
        for(int i=0; i<sz_row; ++i) {
            for(int j=0; j<sz_col; ++j) {
                ret = max(ret, flip(i,j,board));
            }
        }
        
        return ret;
    }
};

int main() {
    XorBoardDivTwo cn;
    vector <string> board = {"101",
                             "010",
                             "101"};
    int rc = cn.theMax(board);
    cout<<rc<<endl;
    return 0;
}
