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
	string s; cin >> s;

	vector<int> res(n, 0), pior(26, -INF);
	pior[s[0]-'a'] = 1;
	res[0] = 1;
	for (int i = 1; i < n; i++) {
		int agr = -INF;
		for (int j = s[i] - 'a' + 1; j < 26; j++) {
			agr = max(agr, pior[j]);
		}
		res[i] = pior[s[i]-'a'] = (agr == -INF ? 1 : agr+1);
	}
	cout << *max_element(res.begin(), res.end()) << endl;
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
