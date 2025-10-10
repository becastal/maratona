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

int main()
{
    _;

	int n, mx = 0; cin >> n;
	vector<int> v(n), b(n, -1);
	for (int& i : v) cin >> i, mx = max(mx, i);

	set<int> preciso;
	for (int i = 0; i <= mx-1; i++) {
		preciso.insert(i);
	}

	if (v[0] == 1) {
		b[0] = 0;
		preciso.erase(0);
	}

	for (int i = 1; i < n; i++) {
		if (v[i] != v[i-1]) {
			b[i] = v[i-1];
			preciso.erase(v[i-1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (b[i] != -1) continue;

		if (preciso.empty()) {
			b[i] = mx+1;
		} else {
			b[i] = *preciso.begin();
			preciso.erase(preciso.begin());
		}
	}

	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
    
    return(0);
}

