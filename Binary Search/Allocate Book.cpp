#include <bits/stdc++.h> 

bool isPossible(int n, vector <int> time, int m, long long mid) {
	int studentCount = 1;
	long long sum = 0;
	for(int i = 0; i<n; i++) {
		if(sum + time[i] <= mid) // Check if the sum not exceed the mid value
			sum += time[i];
		else { // if sum exceed the mid value
			studentCount++;
			if(studentCount > m || time[i] > mid) { // if ith element if bigger than mid OR studentCount is bigger than m (# of students)
				return false;
			}
			// sum = 0;
			sum = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long Sum = 0;
	long long ans = -1;
	// cout << m << endl;
	for(int i = 0; i<m; i++) {
		Sum += time[i];
	}
	long long l = 0, r = Sum;
	while(l <= r) {
		long long mid = l + (r-l)/2;
		if(isPossible(m, time, n, mid)) {
			ans = mid;
			r = mid-1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}
