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

bool somaDivisoes(vector<double>& nums, double d, int k)
{
    int soma = 0;
    for (auto& ai : nums)
        soma += floor(ai / d);

    return (soma >= k);
}

int main()
{
    _;

    int n, k; cin >> n >> k;

    vector<double> nums(n);
    for (auto& ai : nums)
        cin >> ai;

    double l = 1, r = 1e8;
    for (int i = 0; i < 1e2; i++)
    {
        double m = (r + l) / 2;
        
        if (somaDivisoes(nums, m, k))
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(8) << l << endl;

    return(0);
}
