#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	string S; cin >> S;
	
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> B(A);
	B.push_back(0);
	sort(all(B));
	B.erase(unique(all(B)), B.end());

	cout << *ranges::partition_point(B, [&](int a) {
		int preciso = 0;

		for (int i = 0, aberto = 0; i < n; i++) {
			if (A[i] > a) {
				if (S[i] == 'B') {
					preciso += !aberto;	
					aberto = 1;
				} else {
					aberto = 0;
				}
			}
		}

		return !(preciso <= k);
	}) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

