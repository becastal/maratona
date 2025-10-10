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

	int n;
	while (cin >> n and n) {
		vector<int> v(2, 0), pos;
		for (int i = 0; i < 31; i++) {
			if (n & (1 << i)) pos.push_back(i);
		}

		for (int i = 0; i < (int)pos.size(); i++) {
			v[i&1] |= (1 << pos[i]);
		}
		cout << v[0] << ' ' << v[1] << endl;
	}
    
    return(0);
}
