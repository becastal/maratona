#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

	talvez greedy funcione: ve qual o maior 2^i que presta e usa ele.
	mas talvez: bfs nesse grafo.
	
*/

int solve() {
	int l, r; cin >> l >> r;

	vector<array<int, 2>> Res;
	for (int a = l; a < r; ) {
		int p = 0, a_ = a;	
		while (a_ & 1 ^ 1) {
			a_ >>= 1;
			p = 0;
		}

		int ok = 0;
		for (int i = p; i >= 0 and !ok; i--) if () {

			ok = 1;
		}
		assert(ok);
	}

	cout << (int)Res.size() << endl;
	for (auto [a, b] : Res) {
		cout << a << ' ' << b << endl;
	}

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

