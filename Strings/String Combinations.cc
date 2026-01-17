#include <bits/stdc++.h>
using namespace std;

/*
                     "abc"
            a                       " "
    ab            a" "          b            " "
abc     ab" "  ac     a" "    bc  b" "    c       " " //All the combinatons present at leaf node

Imagine it like a tree

There are 2 cases
    Take a or do not take a (a      " ")
    Now for each of those case, take the next i.e., b, or do not take b (ab a" " ""b " "" ")
    now for these 4 cases, take next (c) one or do not tkae next(c) one (8 cases, 2^3 cases)
*/

void combinations (string str, int i, string temp) {
    if(i == str.length()) {
        cout<<temp<<"\n";
        return;
    }

    combinations(str, i+1, temp + str[i]);
    combinations(str, i+1, temp);
}

int main () {

    string str{"abc"};
    string temp{""};

    combinations(str, 0, temp);

    return 0;
}