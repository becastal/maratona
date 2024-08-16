/*
	wavelet tree com updates
 
	descricao:
		uma segtree mas encima de valores e nao de indices.
		basicamente a mesma coisa que a estatica, mas com um logn a
		mais nas complexidades pra lidar com os updates, por pre ter
		que ser uma segtree.

	complexidades (d = maxn - minn):
		memoria: o(nlog(d))
		count: o(log(d)log(n)), conta quantos x ocorrem em [l, r]
		kth:   o(log(d)log(n)), k-esimo menor valor em [l, r]
  
*/
