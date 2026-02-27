F1(v, n)
  build_heap(v, n)
  para (i = n decrementando ate 0)
    troca(v, 0, i)
    n = n - 1;
    Heapify(v, n, 0)

troca(v, i, maior)
  temp = v[maior]
  v[maior] = v[i]
  v[i] = temp

Heapify(v, n, i){
  l = 2*i+1
  r = 2*i+2

  se l < n && v[l] > v[i]
    maior = l
  senao
    maior = i
  se r < n && v[r] > v[maior]
    maior = r
  se maior != i
    troca(v, i, maior) // troca menor pelo maior
    Heapify(v,n, maior) // heapify novamente

build_heap(v, n)
  inicio = (n/2) - 1
  para(i = inicio decrementando ate 0)
    Heapify(v,n, i)
