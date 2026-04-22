#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260LL);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> C(26, 0);
	for (char c : S) {
		C[c - 'a']++;		
	}

	auto cont = [&](int i) {
		int res = 0;
		for (int j = 0; j < (S[i] - 'a'); j++) {
			res += C[j];
		}
		return res;
	};

	int p = 0;
	for (;p < n and !cont(p); p++) {
		C[S[p] - 'a']--;	
	};

	if (p == n) {
		return cout << S << endl, 0;
	}

	string T = S.substr(p);
	auto V = suffix_array(T);

	cout << "p: " << p << endl;
	cout << "V: ";
	for (int i : V) {
		cout << i << ' ';
	}
	cout << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

