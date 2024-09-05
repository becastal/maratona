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

	int t; cin >> t;
	while (t--) {
		vector<int> v(3);
		int soma = 0, tri = 1;
		for (int& i : v) cin >> i, soma += i;

		for (int i = 0; i < 3 and tri; i++) {
			tri &= (v[i] < soma - v[i]);
		}

		cout << (tri ? "OK" : "Wrong!!") << endl;
	}
    
    return(0);
}
