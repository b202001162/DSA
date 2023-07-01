#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2 == 1) return -1;
    stack <char> st;
    st.push(str[0]);
    for(int i = 1; i<str.size(); i++) {
        switch (str[i]) {
            case '}':
              if (st.size() > 0 && st.top() == '{') {
                st.pop();
              }
              else {
                st.push(str[i]);
              }
              break;
            
            case '{':
                st.push('{');
                break;
        }
    }
    if(st.size() == 0) return 0;
    int odd = 0, even = 0;
    while(!st.empty()) {
      if(st.top() == '{') odd++;
      else even++;
      st.pop();
    }
    return (odd+1)/2 + (even+1)/2; 
}
