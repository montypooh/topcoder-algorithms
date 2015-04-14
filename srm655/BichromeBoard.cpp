#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class BichromeBoard {
  public:
    string ableToDraw(vector <string> board) {
        int sz_row = (int)board.size();
        int sz_col = (int)board[0].size();
        
        int i0=-1, j0=-1;
        for(int i=0; i<sz_row; i++) {
            for(int j=0; j<sz_col; j++) {
                if (board[i][j]!='?') {
                    i0=i;
                    j0=j;
                }
            }
        }
        
        if (i0!=-1) {
            char begin = board[i0][j0];
            char end = (begin=='W') ? 'B':'W';
            if ((i0%2==0 && j0%2==0) || (i0%2==1 && j0%2==1)) {
                for(int i=0; i<sz_row; i++) {
                    for(int j=0; j<sz_col; j++) {
                        if ((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
                            if (board[i][j]==end) return "Impossible";
                        } else {
                            if (board[i][j]==begin) return "Impossible";
                        }
                    }
                }
            } else {
                for(int i=0; i<sz_row; i++) {
                    for(int j=0; j<sz_col; j++) {
                        if ((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
                            if (board[i][j]==begin) return "Impossible";
                        } else {
                            if (board[i][j]==end) return "Impossible";
                        }
                    }
                }
            }
            return "Possible";
        } else {
            return "Possible";
        }
    }
};

// int main() {
//     BichromeBoard cn;
//     vector <string> board={"W?W",
//                            "??B",
//                            "???"};
//     string rc = cn.ableToDraw(board);
//     cout<<rc<<endl;
//     return 0;
// }
