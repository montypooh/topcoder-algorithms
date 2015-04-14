#line 5 "Time.cpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib> // itoa
class Time {
public:
  std::string whatTime(int seconds) {
    int hrs;
    int mins;
    int secs;

    hrs = seconds/3600;
    mins = (seconds - hrs*3600) / 60;
    secs = seconds - hrs*3600 - mins*60;

    std::stringstream ss;
    ss << hrs << ":" << mins << ":" << secs;
    std::string ret;
    ret = ss.str();

    return ret;
  }
};

/*
int main(int argc, char* argv[]) {
  Time time;
  std::string t1;
  t1 = time.whatTime(1000);
  std::cout << t1 << std::endl;
  return 1;
}
*/


// Powered by FileEdit
