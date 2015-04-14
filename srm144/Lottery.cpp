#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

bool sortByChance(std::pair<std::string, unsigned long long> r1, std::pair<std::string, unsigned long long> r2) {
    return (r1.second <= r2.second);
}

class Lottery {

  private:
    void parseString(std::string rule, std::string* name, int* choices, int* blanks, bool* sorted, bool* unique) {
        std::size_t start;
        std::size_t end;
        start = 0;
        end = rule.find(":");
        *name = rule.substr(start, end-start);
        start = rule.find(": ") + 2;
        end = rule.find(" ", start);
        *choices = atoi(rule.substr(start, end-start).c_str());
        start = rule.find(" ", end) + 1;
        end = rule.find (" ", start);
        *blanks = atoi(rule.substr(start, end-start).c_str());
        start = rule.find(" ", end) + 1;
        end = rule.find(" ", start);
        std::string sortedStr = rule.substr(start, end-start);
        if (sortedStr.compare("T")==0)
            *sorted = true;
        else if (sortedStr.compare("F")==0)
            *sorted = false;
        start = rule.find(" ", end) + 1;
        end = rule.length();
        std::string uniqueStr = rule.substr(start, end-start);
        if (uniqueStr.compare("T")==0)
            *unique = true;
        else if (uniqueStr.compare("F")==0)
            *unique = false;
    }
  
    unsigned long long permutation(int n, int r) {
        unsigned long long ret = 1;

        for (int i=0; i<r; i++)
            ret *= n-i;
        return ret;
    }

    unsigned long long combination(int n, int r) {
        unsigned long long ret = 1;
        ret *= permutation(n, r);
        for (int i=0; i<r && r-i>0; i++)
            ret /= r-i;
        return ret;
    }
  
    unsigned long long numValidTickets(std::string rule) {
        std::string name;
        int choices;
        int blanks;
        bool sorted = false;
        bool unique = false;

        parseString(rule, &name, &choices, &blanks, &sorted, &unique);

        unsigned long long totalTickets = 0;
        if (!sorted && !unique) totalTickets = pow(choices, blanks);
        else if (sorted && !unique) totalTickets = combination(choices + blanks - 1, blanks);
        else if (!sorted && unique) totalTickets = permutation(choices, blanks);
        else totalTickets = combination(choices, blanks);
        return totalTickets;
    }

  public:
    std::vector<std::string> sortByOdds(std::vector<std::string> rules) {

        std::vector<std::string> names;
        std::vector<std::string>::iterator siter;
        std::vector< std::pair<std::string, unsigned long long> > rulesXChance;

        std::string name;
        int choices;
        int blanks;
        bool sorted;
        bool unique;

        for (siter = rules.begin(); siter != rules.end(); siter++) {
            parseString(*siter, &name, &choices, &blanks, &sorted, &unique);
            std::pair<std::string, unsigned long long> ruleXChance(name, numValidTickets(*siter));
            rulesXChance.push_back(ruleXChance);
        }

        std::sort(rulesXChance.begin(), rulesXChance.end(), sortByChance);
        std::vector< std::pair<std::string, unsigned long long> >::iterator riter;

        for (riter = rulesXChance.begin(); riter != rulesXChance.end(); riter++)
            names.push_back(riter->first);
    
        return names;
    }
};
