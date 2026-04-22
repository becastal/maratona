#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
	}

	sort(all(A), [&](auto& a, auto& b) {
		return a[0] + a[1] < b[0] + b[1];
	});

	priority_queue<int> pq;

	int agr = 0;
	for (auto [w, d] : A) {
		agr += w;
		pq.push(w);

		while (agr > w + d) {
			agr -= pq.top(); pq.pop();
		}
	}

	cout << pq.size() << endl;

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

