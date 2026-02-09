#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 8e5+10;
int ruim[MAX];

int solve() {
	stack<char> A;
	int a = 0, negs = 0;

	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			char c; cin >> c;
			A.push(c);
			a += (c == '(' ? +1 : -1);
			if (a < 0) ruim[A.size()] = 1, negs++;
		} else {
			char c = A.top(); 
			a -= (c == '(' ? +1 : -1);
			if (ruim[A.size()]) ruim[A.size()] = 0, negs--;
			A.pop();
		}
		cout << (!a and !negs ? "Yes" : "No") << endl;
	}

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

