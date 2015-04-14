#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define INF 1000000000

bool weightAscend(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

struct findNode {
    findNode(int n) {_n=n;}
    bool operator() (pair<int,int> p) {return _n==p.first;}
  private:
    int _n;
};

class TheKingsTree {
    vector<pair<int,int> > nds; // nodes, distances
    vector<pair<int,vector<int> > > nns; // nodes, neighbors

  public:
    void dijk(vector<int> graph) {
        int begin=0;
        vector<pair<int,int> > vertices;
        for (int i=0; i<=(int)graph.size(); i++) { // initialize nodes
            int weight=INF;
            if (i==begin) weight=0;
            pair<int,int> p(i,weight);
            vertices.push_back(p);
        }
        while(!vertices.empty()) {
            sort(vertices.begin(),vertices.end(),weightAscend);
            pair<int,int> p=*vertices.begin();
            nds.push_back(p);
            vertices.erase(remove(vertices.begin(),vertices.end(),p),vertices.end());
            vector<pair<pair<int,int>*, int> > neighbors;
            for(int i=0; i<(int)graph.size(); i++) // prepare neighbors
                if (graph[i]==p.first) {
                    pair<int,int>* p_ptr = &*find_if(vertices.begin(),vertices.end(),findNode(i+1));
                    pair<pair<int,int>*,int> pp(p_ptr,1);
                    neighbors.push_back(pp);
                }
            for(int i=0;i<(int)neighbors.size();i++) // update costs
                if(neighbors[i].first->second > p.second+neighbors[i].second)
                    neighbors[i].first->second = p.second+neighbors[i].second;
        }
    }

    int getCost(int n) {
        int res;
        for(int i=0; i<(int)nns.size(); i++)
            if (n==nns[i].first) {
                if (nns[i].second.empty())
                    return 0;
                else
                    for(int j=0; j<(int)nns[i].second.size(); j++)
                        return getCost(nns[i].second[j]);
            }
            
        return res;
    }
    
    int getNumber(vector <int> parent) {
        dijk(parent); // node, distance
        for (int i=0; i<=(int)parent.size(); i++) {
            vector<int> n;
            pair<int,vector<int> > nn(i, n);
            nns.push_back(nn);
        }
        for (int i=0; i<(int)nns.size(); i++) {
            int n=nns[i].first;
            for (int j=0; j<(int)parent.size(); j++)
                if (n==parent[j])
                    nns[i].second.push_back(j+1);
        }
        vector<pair<int,int> > costs;
            
        return 1;
    }
};

int main() {
    vector<int> src={0,1,2,3,1};//1,2,3,4,5
    TheKingsTree t;
    int i=t.getNumber(src);
    return i;
}
