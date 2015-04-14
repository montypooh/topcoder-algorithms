#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

#define LIMIT 1000001

using namespace std;

typedef unsigned int uint;

class TheKingsFactorization {
    vector<long long> sievs;
    bitset<LIMIT> bits;
public:
    // get prime numbers up to a range
    void siev() {
        bits.set();
        for(long long i=2; i<LIMIT; i++)
            if (bits[i]) {
                sievs.push_back(i);
                for(long long j=i*i; j<LIMIT; j+=i)
                    bits[j]=0;
            }
    }

    vector<long long> getVector(long long N, vector<long long> primes) {
        vector<long long> res;
        siev();
        // take care of given factors first
        for(unsigned long long i=0; i<primes.size(); i++)
            while(N%primes[i]==0) {
                N/=primes[i];
                res.push_back(primes[i]);
            }
        // take care of rest
        for(int i=0; i<sievs.size(); i++) {
            if (res.end()==find(res.begin(), res.end(), sievs[i]))
                if (N%sievs[i]==0) {
                    N/=sievs[i];
                    res.push_back(sievs[i]);
                }
            if (sievs[i]>sqrt(N))
                break;
        }

        if (N>2)
            res.push_back(N);
        sort(res.begin(), res.end());
        return res;
    }
};
/*
int main() {
    TheKingsFactorization t;
    long long n = 210;
    vector<long long> v = {2,5};
    v=t.getVector(n,v);
    return 1;
}
*/


// Powered by FileEdit
