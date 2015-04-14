#include <string>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort, find, min, max
#include <cmath> // abs, 
#include <cassert>
#include <iostream>

using namespace std;

class CircleGame {
  public:
    int getCost(char card) {
        if (card=='A')
            return 1;
        else if (card=='2')
            return 2;
        else if (card=='3')
            return 3;
        else if (card=='4')
            return 4;
        else if (card=='5')
            return 5;
        else if (card=='6')
            return 6;
        else if (card=='7')
            return 7;
        else if (card=='8')
            return 8;
        else if (card=='9')
            return 9;
        else if (card=='T')
            return 10;
        else if (card=='J')
            return 11;
        else if (card=='Q')
            return 12;
        else if (card=='K')
            return 13;
        else if (card==' ')
            return -1;
        else {
            assert(false);
            return -1;
        }
    }

    char getCard(int& i, string deck) {
        int counter=0;
        while (deck[i]==' ') {
            i=(i+1)%deck.size();
            counter++;
            if (counter==(int)deck.size())
                break;
        }
        return deck[i];
    }

    int cardsLeft(string deck) {
        int removed=0;
        int sz = deck.size();
        bool inprogress=true;
        while(inprogress) {
            inprogress=false;
            for(int i=0; i<2*sz; i++) {
                int ii=i%sz;
                char c1=getCard(ii,deck);
                int j=(ii+1)%sz;
                char c2=getCard(j,deck);
                if (c1==' ')
                    break;
                if (getCost(c1)==13) {
                    deck[ii]=' ';
                    removed++;
                    inprogress=true;
                }
                else if (getCost(c1)+getCost(c2)==13) {
                    deck[ii]=' ';
                    deck[j]=' ';
                    removed+=2;
                    i++;
                    inprogress=true;
                }
            }
        }
        int ret=sz-removed;
        return ret;
    }
};


int main() {
    CircleGame cn;
    string deck("KKKKKKKKKK");
    int rc = cn.cardsLeft(deck);

    cout<<rc<<endl;

    return rc;
}
