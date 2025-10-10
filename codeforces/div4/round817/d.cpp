#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	priority_queue<int> pq;

	ll agr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			agr += i;
			pq.emplace(max(0, (n-i-1) - i));
		} else {
			agr += n-i-1;
			pq.emplace(max(0, i - (n-i-1)));
		}
	}

	while (pq.size()) {
		agr += pq.top(); pq.pop();
		cout << agr << ' ';
	}
	cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
