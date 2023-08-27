int majorityVotingAlgo(vector <int> arr, int n) {
  int m = -1, num = 0;
  for(int i = 0; i<n; i++) {
    if(i == 0) {
      m = arr[i];
      num = 1;
    } else if(arr[i] == m) {
      num++;
    } else  {
      num--;
    }
  }
  num = 0;
  for(int i = 0; i<n; i++) {
    if(arr[i] == m) num++;
  }
  if(num > n/2) return m;
  else return -1;
}
