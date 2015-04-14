#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

class RobotOnMoonEasy {
  public:
    pair<int,int> getPos(vector<string> board) {
        for(int i=0; i<(int)board.size(); i++) {
            for(int j=0; j<(int)board[i].size(); j++) {
                if (board[i][j] == 'S') {
                    pair<int,int> p(i,j);
                    return p;
                }
            }
        }
    }

    string isSafeCommand(vector <string> board, string S) {
        pair<int,int> point = getPos(board);
        int ymax = (int)board.size()-1;
        int xmax = (int)board[0].size()-1;
        int y=point.first;
        int x=point.second;
        for(int i=0; i<(int)S.size(); i++) {
            if (S[i]=='U') {
                if (y==0) return "Dead";
                else if (board[y-1][x]=='.') y--;
            } else if (S[i]=='D') {
                if (y==ymax) return "Dead";
                else if (board[y+1][x]=='.') y++;
            } else if (S[i]=='L') {
                if (x==0) return "Dead";
                else if (board[y][x-1]=='.') x--;
            } else if (S[i]=='R') {
                if (x==xmax) return "Dead";
                else if (board[y][x+1]=='.') x++;
            }
        }
        return "Alive";
    }
};

int main() {
    RobotOnMoonEasy cn;
    

}
