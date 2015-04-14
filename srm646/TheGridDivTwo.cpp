#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 

using namespace std;

struct Node {
    int x;
    int y;
    vector<Neighbor*> neighbors;
    Node(int x, int y): x(x),y(y) {}
};

struct Neighbor {
    Node n;
    int dist;
    Neighbor(Node n): n(n) {}
}

class TheGridDivTwo {
  public:
    bool coordinateE(vector<int> x, vector<int> y, int xc, int yc) {
        bool ret = false;
        for (int i=0; i<(int)x.size(); i++) {
            if (xc==x[i] && yc==y[i])
                ret = true;
        }
        return ret;
    }

    int find(vector <int> x, vector <int> y, int k) {
        vector<Node> nodes;
        int graph[4*k+1][4*k+1]; // from -2k to 0 to 2k in xy
        for(int yc=-2*k; yc<=2*k; yc++) {
            for(int xc=-2*k; xc<=2*k; xc++) {
                if (!coordinateE(x,y,xc,yc)) {
                    Node* n = new Node(xc,yc);
                    if (xc>-2*k) {
                        Node* nn = new Node(xc-1, yc);
                        Neighbor ne = new Neighbor(nn,1);
                        n.neighbors.push_back(ne);
                        ne.n.neighbors
                    }
                    nodes.push_back(n);
                }
            }
        }
        for (int i=0; i<(int)nodes.size(); i++) {
            

        }
        return ret;
    }
};

int main() {
    TheGridDivTwo cn;
    vector <int> x={1,1,1,1};
    vector <int> y={-2,-1,0,1};
    int k=4;
    int rc = cn.find(x,y,k);

    return rc;
}


// Powered by FileEdit
