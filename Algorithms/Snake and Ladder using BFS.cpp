class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
        vector <int> moves(31, -1);
        for(int i = 0; i<n*2; i+=2) {
            moves[arr[i]] = arr[i+1];
        }
        
        int lvl = 1;
        queue <int> q;
        q.push(1);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int front = q.front();
                q.pop();
                
                for(int i = front+1; i<=front+6 && i<=30; i++) {
                    if(moves[i] != -1) {
                        if(moves[i] == 30) {
                            return lvl;
                        }
                        q.push(moves[i]);
                    } else {
                        if(i == 30) {
                            return lvl;
                        }
                        q.push(i);
                    }
                }
            }
            lvl++;
        }
        
        return lvl;
        
    }
};
