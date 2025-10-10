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

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	vector<pair<int, int>> C(n);
	for (int i = 0; i < n; i++) {
		C[i] = {A[i], B[i]};
	}
	sort(all(C));

	priority_queue<int> pq;
	ll soma = 0, res = LINF;
	for (int i = 0; i < n; i++) {
		auto [a, b] = C[i];
		if (pq.size() < k) {
			pq.emplace(b); soma += b;
		} else if (b < pq.top()) {
			pq.emplace(b); soma += b;
			soma -= pq.top(); pq.pop();
		}

		if (pq.size() == k) res = min(res, a * soma);
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
