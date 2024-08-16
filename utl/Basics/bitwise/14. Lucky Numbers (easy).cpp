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

	string s, r; cin >> s;
	bool ja = 0;
	for (int i = 0; i < (int) s.size(); i++)
	{
		if (!ja and s[i] == '0')
			ja = true;
		else
			r.push_back(s[i]);
	}

	if (!ja) r.pop_back();
	cout << r << endl;
    
    return(0);
}
