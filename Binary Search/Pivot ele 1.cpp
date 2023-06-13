// Find pivot ele of index in rotated array 
// Array is like (7,8,1,5,6)
// here 1 is pivot element

int pivotEle(int arr[], int n) {
  int pivot = 0, l = 0, r = n-1;
  int mid = l+ (r-l)/2;
  while(l <= r) {
      mid = l + (r-l)/2;
      if(arr[mid] == k) {
          return mid;
      }
      if(arr[mid] >= arr[0]) {
          l = mid + 1;
      }
      else {   // note this, this is most important part of the code
          r = mid;
      }
  }
  return pivot;
}
