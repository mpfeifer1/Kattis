#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll k, n;
vector<ll> dp;
vector<ll> primes;


// Utility function to do modular exponentiation.
// It returns (x^y) % p
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(ll d, ll n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);

    // Compute a^d % n
    ll x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(ll n, ll k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given nber of 'k' times
    for (ll i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;

    return true;
}

const int ITER = 50;

ll getprime(ll n) {
    int ct = 0;
    ll temp = n;
    ll fac;
    for(ll i : primes) {
        if(i*i*i > n) break;
        while(n % i == 0) {
            fac = i;
            n /= i;
            ct++;
        }
        if(ct > 2) return ct;
    }
    if(ct == 0) {
        if(isPrime(n, ITER)) return 1;
        else return 2;
    }
    if(ct == 1) {
        if(isPrime(temp/fac, ITER)) return 2;
        return 3;
    }
    if(ct == 2) {
        if(n == 1) return 2;
        return 3;
    }
    return ct;
}

const int M = 23000000;
bool prime[M];

int main() {
    for(int i = 2; i < M; ++i) prime[i] = true;
    for(int i = 2; i*i < M; ++i) {
        if(prime[i]) {
            for(int j = i*i; j < M; j += i) {
                prime[j] = false;
            }
        }
    }
    primes.reserve(1000000);
    for(int i = 2; i < M; ++i) {
        if(prime[i]) primes.push_back(i);
    }
    cin >> k >> n;
    dp.resize(n+1,-1);

    dp[1] = 42;
    dp[2] = 11 * k + 77;

    for(int t = 3; t <= n; t++) {
        dp[t] = 2*dp[t-1] - dp[t-2] + 10*k;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        //cout << i << ' ' << dp[i] << '\n';;
        if(getprime(dp[i]) == 2) ans++;//, cout << i << ' ';;
    }

    cout << ans << endl;
}
