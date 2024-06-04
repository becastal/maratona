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

	vector<int> v(9, 0);
	for (int i = 0; i < 10; i++)
		for (int j = 5; j >= 0; j--)
			v[i] += 2 * (i * pow(10, j));

	for (auto vi : v)
		cout << vi << endl;

	map<int, vector<int>> somas;
	vector<bool> selecao(10, false);
	fill(selecao.begin(), selecao.begin() + 5, true);
	do
	{
		int soma = 0;
		vector<int> is;
		for (int i = 0; i < 10; i++)
		{
			if (selecao[i])
			{
				soma += v[i];
				is.push_back(i);
			}
		}
		somas.insert({soma, is});
	} while (prev_permutation(selecao.begin(), selecao.end()));

	for (auto [a, b] : somas)
	{
		cout << a << ": ";
		for (auto bi : b)
			cout << bi << ',';
		cout << endl;
	}

	int t; cin >> t;
	while (t--)
	{
		int k; cin >> k;
		if (somas.find(k) != somas.end())
		{
			vector<int> nums = somas[k];
			cout << '{' << nums[0];
			for (int i = 1; i < nums.size(); i++)
				cout << nums[i] << ',';
			cout << '}' << endl;
		}
		else
			cout << "impossivel" << endl;

	}
    
    return(0);
}
