#include <bits/stdc++.h>
using namespace std;

// コンパイルコマンド
// g++ TemplateTest.cpp -o out
// ./out

// 関数テンプレートを使った実装→xの型によらず、同一の処理を同じ関数で定義できる
template <typename T>
T square(T x) {
  return x * x;
}


int main(){
  int a=3;
  double b=1.2;

  cout<<square(a)<<endl;  //cout << square<int>(a) << endl;と書かなくても、C++のテンプレート引数の推論により、関数呼び出しの際に引数の型からテンプレートの型引数を推論できる
  cout<<square(b)<<endl;
}

// テンプレートはコンパイル時の機能。

