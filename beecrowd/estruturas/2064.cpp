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
    
	int k, m, n; 
	cin >> k >> m >> n; 

	vector<int> mao(26, 0), fav, trad(26);
	iota(trad.begin(), trad.end(), 0);

	string favoritas, s;
	cin >> favoritas >> s;

	for (char c : favoritas) {
		fav.push_back(c - 'a');
	}

	for (char c : s) {
		mao[c - 'a']++;
	}

	int maior = 0;
	vector<int> melhor = trad;
	for (int i : fav) {
		maior += mao[i];
	}

	for (int i = 0; i < n; i++) {
		char a, b; cin >> a >> b;
		int ai = a - 'a', bi = b - 'a';
		swap(mao[ai], mao[bi]);
		swap(trad[ai], trad[bi]);

		int agr = 0;
		for (int i : fav) {
			agr += mao[i];
		}
	
		if (agr > maior) {
			maior = agr;
			melhor =  trad;
		}
	}

	cout << maior << endl;
	for (char c : s) {
		cout << char(melhor[c - 'a'] + 'a');
	}
	cout << endl;

    return(0);
}

