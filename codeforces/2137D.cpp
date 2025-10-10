#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> B(n);

	map<int, int> F;
	map<int, vector<int>> pos;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		F[B[i]]++;
		pos[B[i]].push_back(i);
	}

	for (auto [a, b] : F) if (b % a) return cout << -1 << endl, 0;

	vector<int> A(n);
	int agr = 1;
	for (auto [a, V] : pos) {
		int cont = 0;
		for (int i : V) {
			A[i] = agr;
			if (++cont == a) {
				agr++;
				cont = 0;
			}
		}
	}

	for (int i : A) cout << i << ' '; cout << endl;
	
	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

