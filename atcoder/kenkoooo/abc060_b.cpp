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

	int a, b, c; cin >> a >> b >> c;

	int s = 0, ok = 0;
	set<int> S;
	while (!ok) {
		s = (s + a) % b;		
		
		if (S.count(s)) break;	
		S.insert(s);
	}

	cout << (S.count(c) or s == c ? "YES" : "NO") << endl;
    
    return(0);
}
