#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 200010;
vector<int> primes;
int divi[MAX];

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

void fact(map<int, int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v[divi[n]]++;
}
 
int main() {
	_;

	crivo(MAX-1);
	int n; cin >> n;

	vector<int> v(n);
	for (int& i : v) cin >> i;
	
	map<int, multiset<int>> M;
	for (int i : v) {
		map<int, int> mi;
		fact(mi, i);
		for (auto [pi, cont] : mi) {
			M[pi].insert(cont);
		}
	}

	ll res = 1;
	for (int i : primes) {
		if (M[i].empty()) continue;
		//cout << i << ": ";
		//for (int j : M[i]) cout << j << ' ';
		//cout << endl;

		if (M[i].size() == n) {
			res *= (ll)pow(i, max(*M[i].begin(), *next(M[i].begin(), 1)));
		} else if (M[i].size() == n-1) {
			res *= (ll)pow(i, *M[i].begin());
		}
	}
	cout << res << endl;
 
 	return 0;
}
