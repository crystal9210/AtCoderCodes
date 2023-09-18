// listが双方向リストであることの確認コード
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList;

    // 1, 2, 3, 4, 5 をリストに追加
    for (int i = 1; i <= 5; i++) {
        myList.push_back(i);
    }

    // 末尾に6を追加
    myList.push_back(6);

    // 先頭に0を追加
    myList.push_front(0);

    cout << "List after adding elements: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // 末尾の要素を削除
    myList.pop_back();

    // 先頭の要素を削除
    myList.pop_front();

    cout << "List after removing elements: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // リストの要素を後方から反復処理
    cout << "List in reverse: ";
    for (auto it = myList.rbegin(); it != myList.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 3をリストの中間に追加
    auto it = myList.begin();
    advance(it, 2);  // イテレータを2つ前に進める
    myList.insert(it, 3);

    cout << "List after inserting 3: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // 3をリストから削除
    it = myList.begin();
    advance(it, 2);
    myList.erase(it);

    cout << "List after erasing 3: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
