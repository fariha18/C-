void output(int a*, int size){
for(int i=0;i<size; i++){
cout << *(a+1) << " " ;
  }
  cout << endl;
}

int *merge(int *a, int *b, int s1, int s2){
  int *temp = new int[s1+s2];
  int c1=0, c2=0;
  for(int i = 0; i<s1+s2; i++){
    if(c1<s1 && c2<s2){
      if(i%2==0){
        *(temp+1) = *(a+c1);
        c1++;
      }
      else {
        *(temp + 1) = *(b+c2);
        c2++;
      } else if(c1>=s1){
        *(temp+1) = *(b+c2);
        c2++;
      } else if(c2>=s2){
        *(temp+1) = *(a+c1);
        c1++;
      }
    }
    return temp;
  }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int pos)
{
    for (int i = 0; i < pos-1; i++)       
    for (int j = 0; j < pos-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
