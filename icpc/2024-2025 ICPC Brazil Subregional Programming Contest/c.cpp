#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

// Suffix Array - O(n log n)
//
// kasai recebe o suffix array e calcula lcp[i],
// o lcp entre s[sa[i],...,n-1] e s[sa[i+1],..,n-1]
//
// Complexidades:
// suffix_array - O(n log(n))

vector<int> suffix_array(const vector<int>& s) {
    int n = s.size();
    vector<int> sa(n), ranks(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        ranks[i] = s[i];
    }
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (ranks[a] != ranks[b]) return ranks[a] < ranks[b];
            int ra = (a + k < n ? ranks[a + k] : -1);
            int rb = (b + k < n ? ranks[b + k] : -1);
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        ranks = tmp;
        if (ranks[sa[n-1]] == n-1) break;
    }
    return sa;
}

vector<int> kasai(vector<int> s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> lcp_array = kasai(A, suffix_array(A));

	stack<int> S;
	int m = n-1;
	vector<int> L(m), R(m);
	for (int i = 0; i < m; i++) {
		while (S.size() and lcp_array[S.top()] >= lcp_array[i]) S.pop();
		L[i] = (S.size() ? S.top() : -1);
		S.push(i);
	}

	while (S.size()) S.pop();
	for (int i = m-1; i >= 0; i--) {
		while (S.size() and lcp_array[S.top()] > lcp_array[i]) S.pop();
		R[i] = (S.size() ? S.top() : m);
		S.push(i);
	}

	ll s = 0;
	for (int i = 0; i < m; i++) {
		s += ll(lcp_array[i]) * ll(R[i] - i) * ll(i - L[i]);
	}

	ll num = 2 * s + n * (n + 1) / 2, den = ll(n) * n;
	ll g = gcd(num, den);
	cout << num / g << '/' << den / g << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
