long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = 0, mx = INT_MIN;
        for(int i = 0; i<n; i++) {
          // sum in every iteration
            sum += arr[i];
          // take maximum
            mx = max(mx, sum);
          // when sum will be lesser than 0 then make it 0.
            if(sum < 0) sum = 0;
        }
        return mx;
    }
