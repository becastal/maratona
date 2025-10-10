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

	set<char> co;
	for (char c : s) co.insert(c);
	int tot = (int) co.size();	

	vector<int> cont(128, 0);
	int l = 0, atual = 0, res = INF;
	for (int r = 0; r < n; r++)
	{
		if (!cont[s[r]]) atual++;
		cont[s[r]]++;

		while (l < n and cont[s[l]] > 1)
			cont[s[l++]]--;

		if (atual == tot)
			res = min(res, r - l + 1);
	}

	cout << res << endl;
    
    return(0);
}
