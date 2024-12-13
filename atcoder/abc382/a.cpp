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

	int n, d; cin >> n >> d;
	string s; cin >> s;

	int a = 0, p = 0;
	for (int i = 0; i < n; i++) {
		a += (s[i] == '@');
		p += (s[i] == '.');
	}

	p += min(d, a);
	cout << p << endl; 
    
    return(0);
}
