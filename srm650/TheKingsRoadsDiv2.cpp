#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class TheKingsRoadsDiv2 {
    vector<int> dfsv;
    vector<pair<int,int> > edges;
  public:
    bool unvisited(int node) {
        return dfsv.end()==find(dfsv.begin(),dfsv.end(),node);
    }
    
    vector<int> getNeighbors(int v, vector<int> a, vector<int> b) {
        vector<int> ret;
        for(int i=0; i<(int)a.size(); i++) {
            if (a[i]==v) ret.push_back(b[i]);
            else if (b[i]==v) ret.push_back(a[i]);
        }
        return ret;
    }

    void dfs(int v, vector<int> a, vector<int> b) {
        dfsv.push_back(v);
        vector<int> neighbors = getNeighbors(v,a,b);
        edges.push_back(pair<int,int>(v,(int)neighbors.size()));
        for(int i=0; i<(int)neighbors.size(); i++)
            if (unvisited(neighbors[i]))
                dfs(neighbors[i],a,b);
    }

    bool check(int h) {
        int c1=0,c2=0,c3=0;
        for(int i=0; i<(int)edges.size(); i++) {
            if (edges[i].second==1) c1++; // leaves
            else if (edges[i].second==2) c2++; // roots
            else if (edges[i].second==3) c3++; // nodes
            else return 0;
        }

        int numLeaves=1;
        for(int i=0; i<h-1; i++) numLeaves<<1; // num leaves
        
        int totNodes=1;
        for(int i=0; i<h; i++) totNodes<<1; // total num nodes
        totNodes--;

        if (c1==numLeaves && c2==1 && c3==totNodes-c1-c2) return true;
        else return false;

    }

    int getRoot() {
        for(int i=0; i<(int)edges.size(); i++) {
            if (edges[i].second==2) return edges[i].first;
        }
        return 0;
    }

    string getAnswer(int h, vector <int> a, vector <int> b) {
        // only one cycle in graph && fully connected graph

        int aa=0,bb=0;
        for(int i=0; i<(int)a.size(); i++) {
            aa = *a.begin(), bb = *b.begin();
            a.erase(a.begin());
            b.erase(b.begin());
            dfs(a[0],a,b);
            int root = getRoot();
            if(root>0) {
                dfs(root);
            }
            edges.clear();
            if (check(h)) return "Correct";
            edges.clear();
            dfsv.clear();
            a.push_back(aa);
            b.push_back(bb);
        }
        
        return "Incorrect";
    }
};

int main() {
    TheKingsRoadsDiv2 cn;
    int h=3;
    vector <int> a={4,7,7,1,1,1,4};
    vector <int> b={6,5,1,7,4,3,2};
    string rc = cn.getAnswer(h,a,b);
    cout<<rc<<endl;

    return 1;
}
