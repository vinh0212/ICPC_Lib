#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> p;

int numPF(ll N) // Number of prime factors of N
{
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)
        while (N % p[i] == 0)
        {
            N /= p[i];
            ++ans;
        }
    return ans + (N != 1);
} //Bigger N and mod -- rho_pollard -  ans is size of fact(x)

int numDiv(ll N) // Number of divisors of N
{
    int ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)
    {
        int power = 0; // count the power
        while (N % p[i] == 0)
        {
            N /= p[i];
            ++power;
        }
        ans *= power + 1;   // follow the formula
    }
    return (N != 1) ? 2 * ans : ans; // last factor = N^1
}

ll sumDiv(ll N) // Sum of divisors of N
{ 
    ll ans = 1;  // Start with 1, as we will multiply each prime's sum.
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i) {
        ll multiplier = p[i], total = 1;
        while (N % p[i] == 0) {
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }
        ans *= total;  // Multiply sum for this prime factor
    }
    if (N != 1) ans *= (N + 1);  // Handle last prime factor
    return ans;
}

ll EulerPhi(ll N)  // Euler's Totient Function
{ 
    ll ans = N;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i) {
        if (N % p[i] == 0) ans -= ans / p[i];
        while (N % p[i] == 0) N /= p[i];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}