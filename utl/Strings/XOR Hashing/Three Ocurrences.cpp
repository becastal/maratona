#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAXA = 1e18;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve() {
	int n; cin >> n;

	vector<int> A(n), P(n + 1), F(n + 1), H1(n + 1), H2(n + 1), mod3(n + 1);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 1; i <= n; i++) {
		H1[i] = uniform(1, MAXA);
		H2[i] = uniform(1, MAXA);
	}

	map<int, int> C;
	int res = 0;
	C[0] = 1;
	for (int i = 0, l = 0, p = 0; i < n; i++) {

		if (mod3[A[i]] == 0) {
			p ^= H1[A[i]];			
		} else if (mod3[A[i]] == 1) {
			p ^= H1[A[i]] ^ H2[A[i]];			
		} else if (mod3[A[i]] == 2) {
			p ^= H2[A[i]];	
		}
		mod3[A[i]] = (mod3[A[i]] + 1) % 3;
		F[A[i]]++;
		P[i + 1] = p;


		while (F[A[i]] > 3) {
			F[A[l]]--;
			C[P[l++]]--;
		}

		res += C[p]++;
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
