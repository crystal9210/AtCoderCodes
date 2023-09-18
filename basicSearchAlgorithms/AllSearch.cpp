// N個のカードが1列に並んでいて、左からi番目のカードに書かれた数はA[i]とする。このとき、Nから3枚のカードを選び、和をKにするような方法は何通りあるか？制約：1<=N<=50,1<=A[i],K<=10^8

// 解法：全探索
#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,x) for(int i=l;i<(x);i++)

int main(){
  int N,K;
  int count=0;  //求めたい場合の数
  cin>>N>>K;
  // cout<<K<<endl;
  vector<int> A(N,0); //動的に配列を確保する際、柔軟性等の観点から動的配列を使う
  
  rep(i,0,N)cin>>A[i];  //空白を挟んで1列で入力してok
  
  rep(i,0,N-2)rep(j,i+1,N-1)rep(k,j+1,N){
    // cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
    if(A[i]+A[j]+A[k]==K)count+=1;
    // cout<<count<<endl;
  }

  cout<<count<<endl;

  return 0;


}