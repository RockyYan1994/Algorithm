/*
	http://www.geeksforgeeks.org/sieve-of-eratosthenes/
*/

//version 1(33 ms)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,false);
        int count = 0;
        for(int i=2;i<n;i++){
            if(!prime[i]){
                count++;
                for(int j=2;j*i<n;j++){
                    prime[i*j] = true;
                }
            }
        }
        return count;
    }
};

//version 2(from deck)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};