## SWAG

#### 概要

モノイドの演算結果を保持した deque。

#### 使い方
##### コンストラクタ
`swag<T,op,e> s`<br>
- T：データの型
- T op(T x,T y)：二項演算
- T e()：単位元

以下、二項演算の計算量を $O(f(x))$ とする。

##### 要素の追加
`void s.push_front(T x)`<br>
`void s.push_back(T x)`<br>
先頭(末尾) に要素を追加する。
###### 計算量
$O(f(x))$

##### 要素の削除
`void s.pop_front()`<br>
`void s.pop_back()`<br>
先頭(末尾)の要素を削除する。
###### 計算量
ならし$O(Nf(x))$ ($N$ は全体で要素を追加する回数)

##### 演算結果
`T s.all_prod()`<br>
列にある要素を $a_1,\ldots ,a_n$ として、 $op(a_1,\ldots ,a_n)$ を返す。列が空の場合は $e$ が返される。
###### 計算量
$O(f(x))$

##### その他
`int t.size()`：列の現在の要素数を返す。
