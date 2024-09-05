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
		set<int> s;
		int soma = 0, xora = 0;
		for (int i = 0, x; i < 4; i++) {
			cin >> x; s.insert(x);
			soma += x;
			xora ^= x;
		}

		if (s.size() == 1) {
			cout << "square" << endl;
		} else if (s.size() == 2 and !xora) {
			cout << "rectangle" << endl;
		} else if (*s.rbegin() < soma - *s.rbegin()) {
			cout << "quadrangle" << endl;
		} else {
			cout << "banana" << endl;
		}
	}
    
    return(0);
}
