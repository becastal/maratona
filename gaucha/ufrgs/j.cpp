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

char minuscula(char c) {
	if (c >= 'A' and c <= 'Z') {
		return c + ('a' - 'A');
	}
	return c;	
}

bool similar(string a, string b) {
	if (a.size() != b.size()) {
		return 0;
	}

	for (char& c : a) {
		c = minuscula(c);
		if (c == 'o') c = '0';
		if (c == 'i' or c == 'l') c = '1';
	}
	for (char& c : b) {
		c = minuscula(c);
		if (c == 'o') c = '0';
		if (c == 'i' or c == 'l') c = '1';
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == b[i]) continue;
		return 0;
	}

	return 1;
}

int main()
{
    _;

	string novo; cin >> novo;
	
	int n; cin >> n;
	bool da = 1;
	for (int i = 0; i < n; i++) {
		string si; cin >> si;

		da &= !similar(novo, si);
	}

	cout << (da ? "Yes" : "No") << endl;
    
    return(0);
}
