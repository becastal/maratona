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

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	ll t = 0;

	for (int i = 0; i < n; i++) {
		int x = v[i] / 5; 
		t += x * 3;
		v[i] -= x * 5;

		while (v[i] > 0) {
			t++;
			v[i] -= (t % 3 ? 1 : 3);
		}
	}
	cout << t << endl;
    
    return(0);
}
