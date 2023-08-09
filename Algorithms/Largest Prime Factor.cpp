class Solution{
public: 
    long long int largestPrimeFactor(int n){
       int i=2;
       while(n!=1){
           // i is always a prime number
           if(n%i==0){
               n/=i;
           }
           else{
               i++;
           }
       }
        /// so the last i (which is equal to n (which is prime) (last iteration))
       return (long long int)i;
   }
};
