#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
struct timer : high_resolution_clock {
	const time_point start;
	timer(): start(now()) {}
	int operator()() {
		return duration_cast<milliseconds>(now() - start).count();
	}
};
 
const int N = 100000000; // maximum number
// Only odd numbers are stored: numbers 3, 5, 7, ... up to N.
// The number of odd candidates is:
const int half = (N + 1) / 2;  
// Each unsigned int holds 32 bits.
vector<unsigned int> sieve((half + 31) / 32, ~0u);
 
// Mark index idx (corresponding to the odd number 2*idx+1) as composite.
inline void markComposite(int idx) {
    sieve[idx >> 5] &= ~(1u << (idx & 31));
}
 
// Check if the odd number corresponding to index idx is still prime.
inline bool isPrimeBit(int idx) {
    return sieve[idx >> 5] & (1u << (idx & 31));
}
 
// Run the sieve (only for odds). 1 is not prime.
void runSieve() {
    // 1 corresponds to index 0 (i.e. number 1) so mark it composite.
    markComposite(0);
    int limit = (int)(sqrt(N)) / 2;
    for (int i = 1; i <= limit; i++) {
        if (isPrimeBit(i)) {
            int p = 2 * i + 1;
            // We start crossing out at p*p; index for p*p is (p*p)/2.
            int start = (p * p) / 2;
            for (int j = start; j < half; j += p) {
                markComposite(j);
            }
        }
    }
}
 
// Given prime rank r (1-indexed), compute triangle row and column in O(1).
// The triangle has 1 prime in row 1, 2 in row 2, 3 in row 3, etc.
// So total primes up to row i: T(i) = i*(i+1)/2.
inline pair<int, int> getPosition(int r) {
    // Solve i*(i+1)/2 >= r using the quadratic formula:
    // i = ceil((-1 + sqrt(1 + 8*r)) / 2)
    int row = int(ceil((-1 + sqrt(1 + 8.0 * r)) / 2));
    int prev = row * (row - 1) / 2; // primes in all previous rows
    int col = r - prev;
    return {row, col};
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	timer T;
    runSieve();
    
    // Build a vector of primes.
    // First, add 2 separately.
    vector<int> primes;
    primes.push_back(2);
    for (int i = 1; i < half; i++) {
        if (isPrimeBit(i)) {
            primes.push_back(2 * i + 1);
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ok = false;
        if(n == 2)
            ok = true;
        else if(n % 2 == 0)
            ok = false;
        else {
            // For odd n, index = (n-1)/2.
            ok = isPrimeBit((n - 1) / 2);
        }
        if(!ok) {
            cout << -1 << "\n";
        } else {
            // Get the rank (1-indexed) via binary search.
            int r = int(lower_bound(primes.begin(), primes.end(), n) - primes.begin()) + 1;
            auto [row, col] = getPosition(r);
            cout << row << " " << col << "\n";
        }
    }

	cout << T() << endl;

    return 0;
}
