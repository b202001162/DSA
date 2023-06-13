// find square of given integer using binary search O(log(n))
// here the function will return only near integer but not precise answer


int floorSqrt(int n)
{
    // Write your code here.
    int l = 0, r = n;
    long long ans= -1;
    while(l <= r) {
        long long mid = l + (r - l)/2;
        long long temp = mid*mid;
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
