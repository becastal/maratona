#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int val(string s) {
	if (s == "4P") return 100000;	
	if (s == "7C") return 10000;	
	if (s == "AE") return 1000;	
	if (s == "7O") return 100;	
	if (s[0] == '3') return 15;
	if (s[0] == '2') return 14;
	if (s[0] == 'A') return 13;
	if (s[0] == 'K') return 12;
	if (s[0] == 'J') return 11;
	if (s[0] == 'Q') return 10;
	return s[0] - '0';
}

struct carta {
	string c;
	carta(string s_) : c(s_) {};
	friend bool operator ==(const carta& a, const carta& b) { 
		return val(a.c) == val(b.c); 
	}
	friend bool operator >(const carta& a, const carta& b) { 
		return val(a.c) > val(b.c); 
	}
	friend bool operator <(const carta& a, const carta& b) { 
		return val(a.c) < val(b.c); 
	}
};

int solve() {
	vector<set<carta>> V(4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			string s; cin >> s;	
			V[i].insert(carta(s));
		}
	}

	for (int t = 0; t < 3; t++) {
		set<carta> mA, mB;

		for (int j = 0; j < 4; j++) {

			if (j % 2 == 0) {
				if (mA.empty() or (*mB.rbegin() > *mA.rbegin() and *V[j].rbegin() > *mB.rbegin())) {
					mA.insert(*V[j].rbegin());
					V[j].erase(*V[j].rbegin());
				} else {
					mA.insert(*V[j].begin());
					V[j].erase(*V[j].begin());
				}
			} else {
				if (mB.empty() or (*mA.rbegin() > *mB.rbegin() and *V[j].rbegin() > *mA.rbegin())) {
					mB.insert(*V[j].rbegin());
					V[j].erase(*V[j].rbegin());
				} else {
					mB.insert(*V[j].begin());
					V[j].erase(*V[j].begin());
				}
			}

		}

		printf("%d\n", t);
		if (*mB.rbegin() == *mA.rbegin()) cout << 0 << ' ';
		else cout << 1 + (*mB.rbegin() > *mA.rbegin()) << ' ';
	}
	cout << endl;

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

