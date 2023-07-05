int Solution::removeElement(vector<int> &A, int B) {
    int index = 0, count = 0;
    for(int i = 0; i<A.size(); i++) {
        if(B == A[i]) {
            count++;
            continue;
        }
        else {
            A[index] = A[i];
            index++;
        }
    }
    return A.size() - count;
}
