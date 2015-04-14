#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class ImageDithering {
  public:
    int count(string dithered, vector <string> screen) {
        int ret=0;
        string cont("");
        for(int i=0; i<(int)screen.size(); i++) {
            cont.append(screen[i]);
        }
        sort(cont.begin(), cont.end());
        for(int i=0; i<(int)cont.size(); i++) {
            for(int j=0; j<(int)dithered.size(); j++) {
                if(cont[i]==dithered[j])
                    ret++;
            }
        }
        return ret;
    }
};

int main() {
    ImageDithering id;
    string dithered;
    vector<string> screen;
    dithered = "BW";
    screen = {"BBBBBBBB",
              "BBWBWBWB",
              "BWBWBWBB",
              "BBWBWBWB",
              "BWBWBWBB",
              "BBBBBBBB"};
    int pixels = id.count(dithered,screen);
    cout<<pixels<<endl;
    return pixels;
}
