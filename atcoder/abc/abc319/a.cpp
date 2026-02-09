#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

map<string, int> M = {
	{"tourist", 3858},
	{"ksun48", 3679},
	{"Benq", 3658},
	{"Um_nik", 3648},
	{"apiad", 3638},
	{"Stonefeang", 3630},
	{"ecnerwala", 3613},
	{"mnbvmar", 3555},
	{"newbiedmy", 3516},
	{"semiexp", 3481},
};

int solve() {
	string S; cin >> S;
	cout << M[S] << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

