void floyd_warshall(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i = 0; i<n; i++) {
          // i is referce to the node which is used to go through the way of j to k
	        for(int j = 0; j<n; j++) {
	            for(int k = 0; k<n; k++) {
	                if(j == i || k == i) {
	                    continue;
	                }
                    if(matrix[j][i] != -1 && matrix[i][k] != -1) {
                        if(matrix[j][k] == -1) {
                            // -1 is infinite distance
                            // j to k through i
                            matrix[j][k] = matrix[j][i] + matrix[i][k];
                            continue;
                        }
                        if(matrix[j][k] > matrix[j][i] + matrix[i][k]) {
                            // if distance is less than the prev one then update it
                            matrix[j][k] = matrix[j][i] + matrix[i][k];
                        }
                    }
	            }
	        }
	    }
	}
