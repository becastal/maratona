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

int solve() {
	int n, k; cin >> n >> k;

	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		a.push_back(a[i]);
	}

	//for (int i = 0; i < 2 * n; i++) {
	//	a[i] += (ll)i * k;
	//}

	vector<ll> b(2*n);
	for(int i = 0; i < 2*n; i++){
		b[i] = a[i % n] - (ll)i * k;
	}

	vector<int> res(n);
	stack<int> s; 
	for(int i = 2*n-1; i >= 0; i--){
		while(!s.empty() and b[s.top()] >= b[i]) {
			s.pop();
		}

		if(i < n){
			int j = s.empty() or s.top() > i + n ? i + n : s.top();
			res[i] = (j % n) + 1;
		}
		s.push(i);
	}

	for(int i = 0; i < n; i++){
		cout << res[i] << " \n"[i==n-1];
	}

	return 0;
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
