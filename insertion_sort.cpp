//insertion sort

#include <bits/stdc++.h>
using namespace std;
 
int main(){

  int n;
  cout<<"enter the size of array:\n";
  cin>>n;
  int a[n];
  cout<<"enter the values of array:\n";
  for(int i=0;i<n;i++){
     cin>>a[i];
  }
  
  for(int i=0;i<n;i++){
    int key=a[i];
    int j=i-1;
    while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
  }
  
  for(int i=0;i<n;i++){
     cout<<a[i]<<" ";
  }

}