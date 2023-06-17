// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
string ans;
void reverse(string s) {
    // ans += 
    if(s.size() == 0) return;
     ans += s[s.size() - 1];
    reverse(s.substr(0,s.size()-1));
   
}

bool checkPallindrome(string s, int i, int j) {
    if(j < i) {
        return 1;
    }
    if(s[i] != s[j]) return 0;
    
    return checkPallindrome(s, i+1, j-1);
}

long long power(int x, int n) {
    if(x == 0 || x == 1) return 1;
    if(n == 0) return 1;
    if(n == 1) return x;
    return 1LL*x * power(x, n-1);
}

int main() {
    // Write C++ code here
    ans = "";
    // string s;
    // cin >> s;
    // cout << checkPallindrome(s, 0, s.size()-1) << endl;
    // cout << ans << endl;
    int base, raise;
    cin >> base >> raise;
    cout << power(base, raise) << endl;
    return 0;
}
