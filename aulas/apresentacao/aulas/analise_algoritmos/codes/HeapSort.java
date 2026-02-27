import java.util.Arrays;
public class HeapSort{

  public static void main(String[] args){
    int v[] = new int[]{16,4,10,14,7,9,3,2,8,1};
    System.out.println("inicio:"+ Arrays.toString(v));
    new HeapSort().Sort(v,v.length-1);
    System.out.println("fim:"+ Arrays.toString(v));
  }

  public void Sort(int[] v,int n){
    build_heap(v, n);
    for(int i = n; i >= 1; i--){
      troca(v, 0, i);
      n = n - 1;
      Heapify(v, n, 0);
    }
  }


  public void troca(int v[], int i, int maior){
    int temp = v[maior];
    v[maior] = v[i];
    v[i] = temp;
  }

  public void Heapify(int v[], int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int maior;
    if (l < n && v[l] > v[i])
      maior = l;
    else
      maior = i;
    if (r < n && v[r] > v[maior])
      maior = r;
    if(maior != i){
      troca(v, i, maior);
      Heapify(v,n, maior);
    }
  }

  public void build_heap(int v[], int n){
    int inicio = (n/2) - 1;
    for(int i = inicio; i >= 0 ; i--){
      Heapify(v,n, i);
    }
  }

}
