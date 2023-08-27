int thirdLengthElement(vector <int> &arr, int n) {
    
    int ele1 = -1, ele2 = -1, freq1 = 0, freq2 = 0;
    
    for(int i = 0; i<n; i++) {
        if(arr[i] == ele1) {
            freq1++;
        } else if(arr[i] == ele2) {
            freq2++;
        } else if(freq1 == 0) {
            ele1 = arr[i];
            freq1 = 1;
        } else if(freq2 == 0) {
            ele2 = arr[i];
            freq2 = 1;
        } else {
            freq1--;
            freq2--;
        }
    }
    
    freq1 = 0, freq2 = 0;
    
    for(int i = 0; i<n; i++) {
        if(arr[i] == ele1) {
            freq1++;
        } else if(arr[i] == ele2) {
            freq2++;
        }
    }
    
    if(freq1 > n/3) {
        return ele1;
    } else if(freq2 > n/3) {
        return ele2;
    } else {
        return -1;
    }
    
}
