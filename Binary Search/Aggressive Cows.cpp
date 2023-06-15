// Problem Statement:
// You are given an array 'arr' consisting of 'n'integers
// which denote the position of a stall.
// You are also given an integer 'k' which denotes the
// number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows
// such that the minimum distance between any two of
// them is the maximum possible.

// Sample Input 1 :
// 6 4
// 0 3 4 7 10 9
// Sample Output 1 :
// Explanation To Sample Input 1 :
// The maximum possible minimum distance
// between any two cows will be 3 when 4 cows
// are placed at positions {0, 3, 7, 10}. Here
// distance between cows are 3, 4 and 3
// respectively.


// we have to find maximum distance between aggresive cows

bool isPossible (vector <int> &arr, int mid, int n, int k) { // Check all valid distences
    int cowCount = 1;
    int last = arr[0];
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] - last >= mid) {  // distence is mid or more then is valid
            last = arr[i];
            cowCount++;
            if(cowCount >= k) return 1;
        }
    }
    return 0;
}

int aggressiveCows(vector<int> &arr, int k)
{
    //    Write your code here.
    sort(arr.begin(), arr.end());  // position not always sorted order, so we have to sort em.
    int ans = 0, maxi = -1, n = arr.size();
    for(int i = 0; i<n; i++) {
        maxi = max(maxi, arr[i]);
        // min = min(min, arr[i]);
    }
    int l = 0, r = maxi; // so the minimum distence would be 0 and max would be max of arr OR (max - min);
    int mid;
    while(l <= r) {
        mid = l + (r - l)/2;
        if(isPossible(arr, mid, n, k)) { // check if possible for the higher values
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
