import java.util.Arrays;
public class QuickSort{

  public static void main(String[] args){
    int v[] = new int[]{16,4,10,14,7,9,3,2,8,1};
    System.out.println("inicio:"+ Arrays.toString(v));
    new QuickSort().Sort(v,0,v.length-1);
    System.out.println("fim:"+ Arrays.toString(v));
  }

  public void Sort(int v[], int p, int r){
    if(p<r){
      int q = particiona(v,p,r);
      Sort(v, p, q-1);
      Sort(v, q+1, r);
    }
  }

  public void troca(int v[], int i, int maior){
    int temp = v[maior];
    v[maior] = v[i];
    v[i] = temp;
  }

  public int particiona(int v[], int p, int r){
    int x = v[r];// pivot
    int i = p-1;
    for(int j = p; j < r; j++){
      if(v[j] <= x){
        i = i + 1;
        troca(v,i,j);
      }
    }
    troca(v,i+1,r);
    return i+1;
  }
}
