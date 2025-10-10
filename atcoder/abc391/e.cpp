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

	// eh so uma recursao pra cada altura, e memo talvez.
	// se o objetivo for fazer 0 virar 1
	// entao quando s[i] = "000", eu somo os dois menores flips na recursao
	// qualquer outro s[i] eu somo so o menor flip na recursao

	int n; cin >> n;
	int N = (int)pow(3, n);
    
	string s, si; cin >> s;
	vector<string> v = {s};

	for (int i = 0; i < n; i++) {
		string si = v.back(), sii = "";

		for (int j = 0; j < si.size(); j += 3) {
			int s = si[j]-'0'+ si[j+1]-'0'+si[j+2]-'0';

			if (s >= 2) sii.push_back('1');
			else sii.push_back('0');
		}

		v.push_back(sii);
	}

	for (string si : v) cout << si << endl;

    return(0);
}
