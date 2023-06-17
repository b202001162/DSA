// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

long long POWER(int base, int power) { 
    // log2(N) iterations
    // BASE CASE
    if(base == 0 || base == 1) return base;
    if(power == 0) return 1;
    if(power%2 == 0) return 1LL * POWER(base, power/2) * POWER(base, power/2);
    else return 1LL * base * POWER(base, power/2) * POWER(base, power/2);
}

int main() {
    int base, power;
    cin >> base >> power;
    cout << POWER(base, power) << endl;
    return 0;
}
