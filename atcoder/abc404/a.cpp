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

	int a = 0;
	string s; cin >> s;
	for (char c : s) a |= 1 << (c - 'a');

	for (int i = 0; i < 26; i++) {
		if (!(a & (1 << i))) return cout << char('a' + i) << endl, 0;
	}
	assert(0);
    
    return(0);
}
