#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e6+10;
vector<int> divs(int x) {
	vector<int> res;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (x / i != i) res.push_back(x / i);
		}
	}
	return res;
}

int main()
{
    _;

	int n, k; cin >> n >> k;
	vector<int> v(n);
	int mx = 0;
	for (int& i : v) cin >> i, mx = max(mx, i);

	vector<vector<int>> subs(mx+1);

	for (int i : v) {
		if (i == 1 or !subs[i].empty()) continue;
		subs[i] = divs(i);
	}

	int M[MAX], ja[MAX];
	for (int i = 0; i < MAX; i++) {
		M[i] = 0, ja[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == 1) continue;

		for (int acum : subs[v[i]]) {
			if (ja[acum] == i) continue;
			M[acum]++;
			ja[acum] = i;
		}
	}

	vector<int> res(n, 1);
	for (int i = 0; i < n; i++) {
		if (v[i] == 1) continue;

		for (int acum : subs[v[i]]) {
			if (M[acum] >= k) {
				res[i] = max(res[i], acum);
			}
		}
	}

	for (int i : res) cout << i << endl;
    
    return(0);
}

