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

// Estrutura para armazenar informa��es de um sufixo
struct suffix
{
    int index; // Para armazenar o �ndice original
    int rank[2]; // Para armazenar os ranks e o par do pr�ximo rank
};

// Fun��o de compara��o usada pelo sort() para comparar dois sufixos
// Compara dois pares, retorna 1 se o primeiro par for menor
int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
                                      (a.rank[0] < b.rank[0] ? 1 : 0);
}

// Fun��o principal que recebe uma string 'txt' de tamanho n como argumento,
// constr�i e retorna o array de sufixos para a string dada
vector<int> buildSuffixArray(string txt, int n)
{
    // Estrutura para armazenar sufixos e seus �ndices
    struct suffix suffixes[n];

    // Armazena sufixos e seus �ndices em um array de estruturas.
    // A estrutura � necess�ria para ordenar os sufixos alfabeticamente
    // e manter seus �ndices antigos durante a ordena��o
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
    }

    // Ordena os sufixos usando a fun��o de compara��o definida acima
    sort(suffixes, suffixes + n, cmp);

    // Neste ponto, todos os sufixos est�o ordenados de acordo com os primeiros
    // 2 caracteres. Agora vamos ordenar os sufixos de acordo com os primeiros
    // 4 caracteres, depois 8 e assim por diante
    int ind[n]; // Este array � necess�rio para obter o �ndice em suffixes[]
    // a partir do �ndice original. Esse mapeamento � necess�rio para obter
    // o pr�ximo sufixo.
    for (int k = 4; k < 2 * n; k = k * 2)
    {
        // Atribuindo valores de rank e �ndice ao primeiro sufixo
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        // Atribuindo rank aos sufixos
        for (int i = 1; i < n; i++)
        {
            // Se o primeiro rank e o pr�ximo rank forem iguais aos do sufixo
            // anterior no array, atribua o mesmo novo rank a este sufixo
            if (suffixes[i].rank[0] == prev_rank &&
                suffixes[i].rank[1] == suffixes[i - 1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else // Caso contr�rio, incremente o rank e atribua
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        // Atribuir o pr�ximo rank a cada sufixo
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextindex < n) ?
                                  suffixes[ind[nextindex]].rank[0] : -1;
        }

        // Ordenar os sufixos de acordo com os primeiros k caracteres
        sort(suffixes, suffixes + n, cmp);
    }

    // Armazena os �ndices de todos os sufixos ordenados no array de sufixos
    vector<int> suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);

    // Retorna o array de sufixos
    return suffixArr;
}

/* Para construir e retornar o LCP (Longest Common Prefix) */
vector<int> kasai(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();

    // Para armazenar o array LCP
    vector<int> lcp(n, 0);

    // Um array auxiliar para armazenar o inverso do array de sufixos
    // Por exemplo, se suffixArr[0] for 5, invSuff[5] armazenar� 0.
    // Isso � usado para obter a pr�xima string de sufixo do array de sufixos.
    vector<int> invSuff(n, 0);

    // Preencher os valores em invSuff[]
    for (int i = 0; i < n; i++)
        invSuff[suffixArr[i]] = i;

    // Inicializa o comprimento do LCP anterior
    int k = 0;

    // Processa todos os sufixos um por um come�ando do primeiro sufixo em txt[]
    for (int i = 0; i < n; i++)
    {
        /* Se o sufixo atual est� em n-1, ent�o n�o temos o pr�ximo
        substring para considerar. Portanto, o LCP n�o � definido
        para este substring, colocamos zero. */
        if (invSuff[i] == n - 1)
        {
            k = 0;
            continue;
        }

        /* j cont�m o �ndice do pr�ximo substring a ser considerado
        para compara��o com o substring atual, ou seja, a pr�xima
        string no array de sufixos */
        int j = suffixArr[invSuff[i] + 1];

        // Come�a a compara��o diretamente a partir do �ndice k, j� que
        // pelo menos k-1 caracteres v�o coincidir
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
            k++;

        lcp[invSuff[i]] = k; // LCP para o sufixo atual.

        // Deletar o caractere inicial da string.
        if (k > 0)
            k--;
    }

    // Retorna o array LCP constru�do
    return lcp;
}

void printArr(vector<int> arr, string txt)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " << txt.substr(arr[i]) << endl;
}

int main()
{
    _;

    string str;
    cin >> str;

    cout << str.size() << " " << endl;

    vector<int> suffixArr = buildSuffixArray(str, str.length());
    int n = suffixArr.size();

    printArr(suffixArr, str);

    return 0;
}

