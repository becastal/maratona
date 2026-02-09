#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);

	ll agr = 0;
	priority_queue<int> pq;
	for (auto& [a, b] : A) {
		cin >> a >> b;
		pq.push(-(a + b));
		agr += b;
	}

	int res = 0;
	while (pq.size()) {
		if (agr + pq.top() >= 0) {
			agr += pq.top(); pq.pop();
			res++;
		} else break;
	}
	cout << res << endl;

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

