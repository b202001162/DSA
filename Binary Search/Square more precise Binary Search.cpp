// Return more precise double ans for given digit

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) // return possible near integer answer
{ // binary search
    // Write your code here.
    int l = 0, r = n;
    long long ans= -1;
    while(l <= r) {
        long long mid = l + (r - l)/2;
        long long temp = mid*mid;  // it may be exceed integer length so I use long long here.
        if(temp > n) {
            r = mid - 1;
        }
        else if(temp < n){
            ans = mid;
            l = mid+1;
        }
        else {
            return (int)mid;
        }
    }
    return (int)ans;
}

double morePrecision(int n, int tempSol, int pre)
{  // linear search for 0.1 to 0.9
  double ans = tempSol;
  double factor = 1;
  for(int i = 0; i<pre; i++) {
    factor = factor/10;
    for(double j = ans; j*j<n; j+=factor) {  // linear search
      ans = j;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  ans = floorSqrt(n);
  cout << morePrecision(n, ans, 8);
  return 0;
}
