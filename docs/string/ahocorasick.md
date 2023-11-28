## Aho-Corasick

#### 概要

文字列の prefix を木状に管理するデータ構造。頂点 0 は根を表す。遷移失敗時の動きが Trie 木と異なる。

#### 使い方
##### コンストラクタ
`aho_corasick<char_size,margin,T,e> t`<br>
- char_size：文字の種類数
- margin：0番目の文字
- T：ノードに乗せるデータ型
- e：ノードのデータの初期値を返す関数

例：`aho_corasick<26,'A',int,e> t`

##### 文字の追加
`int t.add(string s)`<br>
Trie に文字列 S を追加する。末端のノードの番号を返す。
###### 計算量
$O(|S|)$

##### 構築
`void t.build()`<br>
Aho-Corasick を構築する。
###### 計算量
$O(\sigma \sum |S|)$ ($\sigma =$ char_size)

##### 頂点の移動
`int t.move(int u,string s)`<br>
`int t.move(int u,char c)`<br>
頂点 u から、文字列 s\(c\) だけ進んだ場所にある頂点を返す。
###### 計算量
$O(|S|)$

##### その他
`int t.getpar(int u)`：頂点 u の親を返す。 u が根の場合は -1 を返す。<br>
`int t.size()`：現在の頂点数を返す。根のノードも個数に含まれる。<br>
`T t[u]`：頂点 u の現在の値を返す。代入も可。
