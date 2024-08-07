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
typedef bitset<256> bs;

int main()
{
    _;

	int n; cin >> n;
	vector<bs> v(n);
	
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int mi; cin >> mi;
			v[i][mi].flip();
		}
	}

	sort(v.rbegin(), v.rend(), [] (const bs& a, const bs& b) { return a.to_string() < b.to_string(); });

	mao = v[0];
	for (int i = 0; i < n; i++)
		// agora eu tenho a minha mao e tenho que, a cada mao, achar o maior xor possivel.
		// da pra fazer com true;
    
    return(0);
}
