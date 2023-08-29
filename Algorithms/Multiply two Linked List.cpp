Class Solution{
  public:
    /*You are required to complete below function */
    
    void trim(string &s1, bool &sign) {
        int n = s1.length();
        if(s1[0] == '-') {
            sign = 1;
            // s1.erase(0, 1);
            int i = 1; 
            for(i = 1; i<n; i++) {
                if(s1[i] != '0') {
                    break;
                }
            }
            s1.erase(0, i);
        }
        else if(s1[0] == '0') {
            int i = 0;
            for(i = 0; i<n; i++) {
                if(s1[i] != '0') break;
            }
            s1.erase(0, i);
        }
    }
    
    string multiplyStrings(string s1, string s2) {
       //Your code here
       if(s1 == "0" || s2 == "0") return "0";
       if(s1 == "1") return s2;
       if(s2 == "1") return s1;
       
       bool sign1 = 0, sign2 = 0;
       
       trim(s1, sign1);
       trim(s2, sign2);
       
    //   cout << s1 << " " << s2 << endl;
       
       vector <int> temp(s1.size() + s2.size(), 0);
       
       for(int i = s1.length() - 1; i>=0; i--) {
           for(int j = s2.length() - 1; j>=0; j--) {
               temp[i + j + 1] +=  (s1[i] - '0') * (s2[j] - '0');
               temp[i+j] += temp[i+j+1]/10;
               temp[i+j+1] %= 10;
           }
       }
       int i = 0;
       for(i; i<temp.size(); i++) {
           if(temp[i] != 0) break;
       }
       
       string res = "";
       for(i; i<temp.size(); i++) {
           res.push_back(temp[i] + '0');
       }
       
       if((sign1 == 1 && sign2 == 0) || (sign1 == 0 && sign2 == 1)) {
           return "-"+res;
       }
       
       return res;
       
    }

};
