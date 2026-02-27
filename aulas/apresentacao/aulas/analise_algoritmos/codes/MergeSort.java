import java.util.Arrays;
public class MergeSort{

  public static void main(String[] args){
    System.out.println("ok");
    int v[] = new int[]{23,45,1,5,4,2,8,3};
    System.out.println(Arrays.toString(v));
    new MergeSort().Sort(v, 0, v.length-1);
    System.out.println(Arrays.toString(v));
  }

  public void Sort(int v[], int left, int right){
    if (left < right){
      int mid =(int) Math.floor((left + right)/ 2);
      Sort(v, left, mid);
      Sort(v, mid + 1, right);
      Merge(v, left, mid, right);
    }
  }

  public void Merge(int v[], int p, int q, int r){
    int n_left = q - p + 1; 
    int n_right = r - q;
    int L[] = new int[n_left];
    int R[] = new int[n_right];
    for(int i = 0; i < n_left; i++){
      L[i] = v[p + i];
    }
    for(int i = 0; i < n_right; i++){
      R[i] = v[q+i+1];	
    }
    int i = 0;
    int j = 0;
    int k = p;
    while(i < n_left && j < n_right){
      if (L[i] <= R[j]){
        v[k] = L[i];
        i = i + 1;
      }else{
        v[k] = R[j];
        j = j + 1;
      }
      k = k + 1;
    }
    while(i < n_left){
      v[k] = L[i];
      i = i + 1;
      k = k + 1;
    }
    while(j < n_right){
      v[k] = R[j];
      j = j + 1;
      k = k + 1;
    }
  }
}
