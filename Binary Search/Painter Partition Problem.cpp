// Minimize boards to K painter (Countinuos painting)
bool isPossible (vector <int> v, int n, int mid, int k) {
    int painterCount = 1;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        if(sum + v[i] <= mid) {
            sum += v[i];
        }
        else {
            painterCount++;
            if(v[i] > mid || painterCount > k) {
                return 0;
            }
            sum = v[i];
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &board, int k)
{
    //    Write your code here.
    int ans = 0;
    int l = 0, sum = 0;
    vector <int> v = board;
    for(int i = 0; i<v.size(); i++) {
        sum += v[i];
    }
    int r = sum;
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(isPossible(v, v.size(), mid, k)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
