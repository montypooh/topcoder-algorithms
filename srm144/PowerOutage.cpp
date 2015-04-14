#include <string>
#include <vector>
#include <utility> // pairs
#include <algorithm> // sort
#include <iostream>

#define INF 10000000

using namespace std;

struct checkNode {
    checkNode(int n):_n(n) {}
    bool operator() (const pair<int,int>& elem) const {
        return _n == elem.first;
    }
  private:
    int _n;
};

bool minWeight(const pair<int,int>& p1, const pair<int,int>& p2) {
    return p1.second < p2.second;
}

bool maxWeight(const pair<int,int>& p1, const pair<int,int>& p2) {
    return p1.second > p2.second;
}

class PowerOutage {
  public:
    int dijkstra(vector<int> fromJunction,
                 vector<int> toJunction,
                 vector<int> ductLength) {
        vector<pair<int,int> > finalDists;

        // added all nodes as unvisiteds
        vector< pair<int,int> > unvisiteds;
        for(vector<int>::iterator niter = fromJunction.begin();
            niter != fromJunction.end();
            niter++) {
            pair<int,int> p1(*niter, INF);
            pair<int,int> p2(toJunction[niter-fromJunction.begin()], INF);
            if (unvisiteds.end()==find_if(unvisiteds.begin(), unvisiteds.end(), checkNode(*niter)))
                unvisiteds.push_back(p1);
            if (unvisiteds.end()==find_if(unvisiteds.begin(), unvisiteds.end(), checkNode(toJunction[niter-fromJunction.begin()])))
                unvisiteds.push_back(p2);
        }

        // initialize beginning node to weight 0
        vector< pair<int,int> >::iterator uiter = find_if(unvisiteds.begin(), unvisiteds.end(), checkNode(0));
        uiter->second = 0;
        int currNode = uiter->first;
        int currNodeWeight = uiter->second;
        unvisiteds.erase(remove(unvisiteds.begin(), unvisiteds.end(), *uiter), unvisiteds.end());
        bool first = true;

        while(!unvisiteds.empty()) {
            // get neighbors of currNode
            // check distances to neighbors and neighbors' weights

            if (!first) {
                sort(unvisiteds.begin(), unvisiteds.end(), minWeight);
                currNode = unvisiteds.begin()->first;
                currNodeWeight = unvisiteds.begin()->second;
                pair<int,int> p(currNode,currNodeWeight);
                finalDists.push_back(p);
                unvisiteds.erase(remove(unvisiteds.begin(), unvisiteds.end(), *unvisiteds.begin()), unvisiteds.end());
            }
            first = false;

            vector<pair<pair<int,int>*,int> > neighbors;
            vector<pair<int,int> > neighborNodes;

            // prepare destination nodes and distances
            for(vector<int>::iterator niter = fromJunction.begin();
                niter != fromJunction.end();
                niter++)
                if (currNode==*niter) {
                    pair<int,int> p(toJunction[niter-fromJunction.begin()], ductLength[niter-fromJunction.begin()]);
                    neighborNodes.push_back(p);
                }

            // prepare destination, weights, distances
            for(vector<pair<int,int> >::iterator uiter = unvisiteds.begin();
                uiter != unvisiteds.end();
                uiter++) {
                vector<pair<int,int> >::iterator niter = find_if(neighborNodes.begin(),
                                                                 neighborNodes.end(),
                                                                 checkNode(uiter->first));
                if (niter != neighborNodes.end()) {
                    int dist = niter->second;
                    pair<pair<int,int>*,int> p(&(*uiter),dist);
                    neighbors.push_back(p);
                }
            }

            for(vector<pair<pair<int,int>*,int> >::iterator piter = neighbors.begin();
                piter != neighbors.end();
                piter++)
                if (piter->first->second > currNodeWeight + piter->second)
                    piter->first->second = currNodeWeight + piter->second;
        }
        sort(finalDists.begin(),finalDists.end(),maxWeight);
        return finalDists.begin()->second;
    }

    int estimateTimeOut(vector <int> fromJunction,
                        vector <int> toJunction,
                        vector <int> ductLength) {
        int sum = 0;
        for (vector<int>::iterator iiter = ductLength.begin();
             iiter != ductLength.end();
             iiter++)
            sum += *iiter*2;

        sum -= dijkstra(fromJunction, toJunction, ductLength);
        return sum;
    }
};


int main(int argc, char* argv[]) {

    vector<int> fromJunction = {0, 0, 0, 1, 4};
    vector<int> toJunction = {1, 3, 4, 2, 5};
    vector<int> ductLength = {10, 10, 100, 10, 5};

    PowerOutage po;
    int i = po.estimateTimeOut(fromJunction,
                               toJunction,
                               ductLength);
    cout<<i<<endl;
    return 1;
}

