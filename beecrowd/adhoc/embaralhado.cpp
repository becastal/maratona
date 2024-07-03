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

	vector<ll> fat(18, 1);
	for (int i = 2; i < 18; i++)
		fat[i] = fat[i - 1] * i;

	string s;
	while (cin >> s and s != "0")
	{
		vector<int> abc(26, 0);
		for (char c : s)
			abc[c - 'a']++;

		ll den = 1;
		for (int i : abc)
			if (i > 1) den *= fat[i];

		cout << fat[s.size()] / den << endl;
	}
    
    return(0);
}
