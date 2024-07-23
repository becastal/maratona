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
// bem absurdo. era um problema de nim (teoria dos jogos). tu tinha que achar um tal de grunge number de cada posicao de cada tabuleiro e jogar eles num vetor de frequencia. dai, com esses vetores computados pra cada tabuleiro, tu fazia a convolucao deles com uma variacao bizarra de xor com fft e achava o resultado. sei la.
// pra ter ideia, eles chamaram a parte da fft (inclusive a de achar o polinomio e tal) como a parte simples e tranquila do problema. a dificuldade real era achar esses grunge number de um jeito esperto ja que n*m podia ser 1e5.pra isso, eles usaram uma tal de sqrt decompositoin pra conseguir fazer: add/rem em o(1) e max em o(sqrt(n*m)).

int main()
{
    _;
    
    return(0);
}
