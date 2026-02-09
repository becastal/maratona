#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	ir dando merge com um set.
	ordena por l, mas nao lembro como faz.
	dai olha cada segmento uma vez so
*/

const int INF = 1e9+10;
int solve() {
	int n, q, s = 0; cin >> n >> q;
	
	set<array<int, 2>> S;
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;

		auto it = S.lower_bound({l, -INF});

		if (it != S.begin()) {
			auto p = prev(it);
			if ((*p)[1] >= l - 1) {
				it = p;
			}
		}

		while (it != S.end() and (*it)[0] <= r + 1) {
			l = min(l, (*it)[0]);
			r = max(r, (*it)[1]);
			s -= (*it)[1] - (*it)[0] + 1;
			it = S.erase(it);
		}
		
		S.insert({l, r});
		s += r - l + 1;
		cout << n - s << endl;
	}

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

