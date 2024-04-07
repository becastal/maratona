// https://br.spoj.com/problems/PRIMO/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int main()
{ _
	int n; cin >> n;

    string resposta = "sim";
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) 
        {
            resposta = "nao";
            break;
        }
    }
    cout << resposta << endl;
}