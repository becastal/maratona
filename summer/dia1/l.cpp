#include <bits/stdc++.h>
#define f first
#define s secont
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {
	_;

	int n; cin >> n;
	vector<int> v(n), a(n, -1), b(n, -1), res(n);	
	
	for (int& i : v) cin >> i;	

	for (int i = 0, agr = INF; i < n; i++) {
		if (!v[i]) agr = i;
		a[i] = agr;	
	}

	for (int i = n-1, agr = INF; i >= 0; i--) {
		if (!v[i]) agr = i;
		b[i] = agr;	
	}

	for (int i = 0; i < n; i++) {
		res[i] = min(abs(i - a[i]), abs(i - b[i]));
	}
	for (int i : res) cout << i << ' '; cout << endl;

	return 0;
}
