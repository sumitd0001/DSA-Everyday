#include <bits/stdc++.h>
using namespace std;

//Recursion
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

//Dynamic Programming
int fib_dp(int n) {
    if (n==0) return 0;
    int a{0};
    int b{1};
    int c{0};
     for(int i = 2; i<=n; ++i) {
        c = a+b;
        a = b;
        b = c;
     }
     return b;
}

//Memoization
// Initialize a memo array with all the elements as -1, and as you reach the base case,
//we will make memo[0] = 0, and memo[1] = 1, so they will be used and not calculated again with memo[n] == -1 check.
/*
So instead of this, for n = 5
                        fib(5)
            fib(4)                  fib(3)
        fib(3)       fib(2)        fib(2)   fib(1)
    fib(2)  fib(1) fib(1) fib(0)  fib(1)  fib(0)
fib(1)  fib(0)

we will have this,
                        fib(5)
                fib(4)          fib(3)
          fib(3)       fib(2)
    fib(2)     fib(1)
fib(1)  fib(0)
*/
int fib_memo(const int& n, vector<int>& memo) {
    if (memo[n] == -1) {
        int res;
        if (n == 0 || n == 1) { //Base Case
            res = n;
        }
        else {
            res = fib_memo(n-1, memo) + fib_memo(n-2, memo);
        }
        memo[n] = res;
    }
    return memo[n];
}

//Tabulation
int fib_tab (const int& n) {
    vector<int> tab(n+1, -1);
    tab[0] = 0, tab[1] = 1;
    for (int i = 2; i<=n; i++) {
        tab[i] = tab[i-1] + tab[i-2];
    }
    return tab[n];
}

int main () {
    int n{0};
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Fibonaaci Recursion (" << n << ") : " << fib(n)<<"\n";
    cout<<"Fibonaaci DP (" << n << ") : " << fib_dp(n)<<"\n";
    cout<<"Initialized vector in Memoization : \n";
    vector<int> memo(n+1,-1);
    for (auto& x : memo) {
        cout<<x<<"\n";
    }
    cout<<"Fibonaaci Memo : "<< n << " : " << fib_memo(n, memo) <<"\n";

    cout<<"Fibonaaci Tabulation : "<< n << " : " << fib_tab(n) <<"\n";

    return 0;
}