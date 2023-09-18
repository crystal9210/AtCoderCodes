#include <vector> //動的配列のインクルード
#include <list> //連結リスト
#include <utility>  //ペア(pair):2つの要素をグループ化、一緒に保存し、必要に応じてアクセスできるようにするためのシンプルなデータ構造。firstメンバとsecondメンバを持つ。それぞれ、pair名.first,pair名.secondにより参照可能
#include <bits/stdc++.h>

using namespace std;

template <typename K,typename V>
class HashTable{
  private:
    static const int SIZE=256;  //ハッシュテーブルのサイズ。例えば、あるkeyのハッシュ値が500だった場合、500%256より実際にはtableのインデックス244にアクセスする
    vector<list<pair<K,V>>> table;
    //vector:動的配列としての属性を付与、list:連結リスト
    // 例：HashTable<int, string> table1;→table1はint型のキーとstring型の値を持つハッシュテーブルとして動作する
  
  public:
  // HashTableクラスのコンストラクタ。tableメンバ変数の初期化となり、tableメンバはこれによりSIZE個の空のリストを保持する
    HashTable():table(SIZE){}

    int hashCode(const K&key) const {
      return hash<K>{}(key)%SIZE; //{}:hash関数のオブジェクトを作成するためのデフォルトコンストラクタを呼び出し、(key)でkeyを引数として、それに対応するハッシュ値を生成する。つまり、hash<K>{}(key)が関数呼び出し部分。
    }

    //
    void put(const K& key, const V& value){
      int hashValue=hashCode(key);  //keyに対するハッシュ値(テーブルのインデックス)の生成、以後指定されたインデックスの連結リストに対して処理を行う
      for(auto& pair :table[hashValue]){
        // 連結リスト内にkeyの値が一致するものがあれば、そのペアの値を上書きする
        if(pair.first==key){
          pair.second=value;
          return; //同じペアが存在する場合は、値を更新し、ここで関数の処理を終了
        }
      }
      table[hashValue].emplace_back(key, value);  //新しい要素をコンテナ(ここでは連結リスト)の末尾に追加するための関数
    }

  //関数名とその実装の{}部分との間にあるconst:メンバ関数がクラスのデータメンバを変更しないことを指示→違反するとコンパイルエラー
  bool get(const K&key, V&value) const {
    int hashValue=hashCode(key);
    for(const auto& pair : table[hashValue]){
      if(pair.first==key){
        value=pair.second;  //ここでkey,valueはいずれも参照なので、valueにpair.secondを代入することでユーザはkeyに一致するvalueを取得できる
        return true;
      }
    }
    return false;
  }

  void remove(const K&key){
    int hashValue=hashCode(key);
    table[hashValue].remove_if([key](const pair <K,V>&pair){
      return pair.first==key;
    }); //const pair <K,V>&pairとあるが、これはremove_if関数がリストに対して呼ばれているので、そのリスト内の要素を自動で走査するためこの記法でok
  }
};



int main(){
   HashTable<int, string> hashTable;

    // putメソッドの使用例
    hashTable.put(1, "one");
    hashTable.put(2, "two");
    hashTable.put(300, "three hundreds");

    // getメソッドの使用例
    string value;
    if(hashTable.get(1, value)) {
        cout << "Key 1 has value: " << value << endl;
    } else {
        cout << "Key 1 not found." << endl;
    }

    if(hashTable.get(300, value)) {
        cout << "Key 300 has value: " << value << endl;
    } else {
        cout << "Key 300 not found." << endl;
    }

    if(hashTable.get(4, value)) {
        cout << "Key 4 has value: " << value << endl;
    } else {
        cout << "Key 4 not found." << endl;
    }

    // removeメソッドの使用例
    hashTable.remove(2);

    if(hashTable.get(2, value)) {
        cout << "Key 2 has value: " << value << endl;
    } else {
        cout << "Key 2 not found." << endl;
    }

    return 0;
}

