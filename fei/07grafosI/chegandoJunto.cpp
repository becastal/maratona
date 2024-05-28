#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define f first #define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const vector<pair<int, int>> movimentos = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
vector<vector<char>> mapa;
vector<pair<int, int>> robos;
map<vector<pair<int, int>>, int> distancia;
int n;

bool movimentosValidos(vector<pair<int, int>> posicoes, pair<int, int> movimento)
{
    for (int i = 0; i < 3; i++)
    {
        pair<int, int> pos = posicoes[i];
        pair<int, int> novaPos = { pos.f + movimento.f, pos.s + movimento.s };
        if (novaPos.f >= 0 && novaPos.f < n && novaPos.s >= 0 && novaPos.s < n && mapa[novaPos.f][novaPos.s] != '#') return(true);
    }
    return(false);
}

bool chegaramJunto(vector<pair<int, int>> posicoes)
{
    for (auto pos : posicoes)
    {
        if (mapa[pos.f][pos.s] != 'X') return(false);
    }
    return(true);
}

bool vetorUnico(vector<pair<int, int>> vetor)
{
    set<pair<int, int>> s;
    for (auto v : vetor) s.insert(v);
    return(vetor.size() == s.size());
}

vector<pair<int, int>> atualizaPosicoes(vector<pair<int, int>> posicoes, pair<int, int> movimento)
{
    vector<pair<int, int>> resposta (3);
    vector<bool> movimentar(3, false);
    map<pair<int, int>, int> contadorPosicoes;
    for (int i = 0; i < 3; i++)
    {
        pair<int, int> pos = posicoes[i];
        pair<int, int> novaPos = { pos.f + movimento.f, pos.s + movimento.s };
        movimentar[i] = (novaPos.f >= 0 && novaPos.f < n && novaPos.s >= 0 && novaPos.s < n && mapa[novaPos.f][novaPos.s] != '#');
        if (movimentar[i]) resposta[i] = novaPos; else resposta[i] = pos;
        contadorPosicoes[resposta[i]]++;
    }

    for (int i = 0; i < 3; i++)
        if (movimentar[i] && contadorPosicoes[resposta[i]] > 1) 
            resposta[i].f -= movimento.f, resposta[i].s -= movimento.s;

    return(resposta);
}

void printMapaAtual(vector<pair<int, int>> posicoes)
{
    auto mapaAtual = mapa;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (mapa[i][j] >= 'A' && mapa[i][j] <= 'C') mapaAtual[i][j] = '.'; else mapaAtual[i][j] = mapa[i][j];

    cout << endl << "posicao alcancada em [" << distancia[posicoes] << "] movimentos!"; for (int i = 0; i < 3; i++)
    {
        cout << char(i + 'A') << "{" << posicoes[i].f << ", " << posicoes[i].s << "} ";
        mapaAtual[posicoes[i].f][posicoes[i].s] = i + 'A';
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << mapaAtual[i][j];
        cout << endl;
    }

}

int bfs()
{
    distancia.clear();
    queue<vector<pair<int, int>>> q;
    q.push(robos);
    distancia[robos] = 0;

    while (!q.empty())
    {
        vector<pair<int, int>> posicoesAtuais = q.front(); q.pop();
        // printMapaAtual(posicoesAtuais);
        if (chegaramJunto(posicoesAtuais)) return(distancia[posicoesAtuais]);
        for (pair<int, int> mov : movimentos)
        {
            if (movimentosValidos(posicoesAtuais, mov))
            {
                vector<pair<int, int>> posicoesNovas = atualizaPosicoes(posicoesAtuais, mov);
                if (vetorUnico(posicoesNovas) && distancia.find(posicoesNovas) == distancia.end())
                {
                    q.push(posicoesNovas);
                    distancia[posicoesNovas] = distancia[posicoesAtuais] + 1;
                }
            }
        }
    }
    return (-1);
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        mapa = vector<vector<char>>(n, vector<char>(n));
        robos = vector<pair<int, int>>(3);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        {
            cin >> mapa[i][j];
            if (mapa[i][j] >= 'A' && mapa[i][j] <= 'C') robos[mapa[i][j] - 'A'] = { i, j };
        }

        int resposta = bfs();
        cout << "Case " << t << ": ";
        if (resposta == -1) cout << "trapped" << endl; else cout << resposta << endl;
    }
    return(0);
}
