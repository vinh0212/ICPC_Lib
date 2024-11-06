// CPP program to print prime numbers from 1 to N
// using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
 
void sieve_of_eratosthenes(int n)
{
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }
}
 
int main()
{
    sieve_of_eratosthenes(100);
    return 0;
}
 
// This code is contributed by Susobhan Akhuli