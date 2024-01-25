//2023 Alred Roos



double total(double arr[], int n){
  double tot = 0;
  for(int i = 0; i < n; i ++){
    tot+=arr[i];
  }
  return tot;
}

double average(double arr[], int n){
  return total(arr,n)/n;
}
