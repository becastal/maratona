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
	vector<int> v(n), cont(21, 0);
	for (int& i : v) {
		cin >> i;
		for (int j = 0; j < 20; j++) {
			cont[j] += i >> j & 1;
		}
	}

	vector<int> v_(n);
	for (int& i : v_) {
		for (int j = 0; j < 20; j++) {
			if (cont[j]) {
				i |= (1 << j);	
				cont[j]--;
			}
		}
	}

	ll res = 0;
	for (int i : v_) res += (ll)i * i;
	cout << res << endl;
    
    return(0);
}
