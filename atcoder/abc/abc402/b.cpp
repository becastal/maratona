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

	int q; cin >> q;
	queue<int> s;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x; cin >> x;
			s.push(x);
		} else {
			cout << s.front() << endl;
			s.pop();
		}
	}
    
    return(0);
}
