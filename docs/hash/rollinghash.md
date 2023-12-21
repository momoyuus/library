## Rolling Hash

#### 概要
ローリングハッシュ。ハッシュは`rolling_hash<hashint,T>::hash`という型で返される。以降、この型を`hash`と省略する。


#### 使い方
##### コンストラクタ
`rolling_hash<hashint,T> rh(T S)`<br>
- hashint：ハッシュの演算。`+, - ,*` 等の演算と、`.val()` で値の参照ができる構造体を乗せることができる。
- T：乗せる列のデータ型。基本は`string`か`vector<hoge>`だと思う。
###### 計算量
$O(|S|)$

##### ハッシュの取得
`hash rh.get(l,r)`<br>
部分列 $S[l,r)$ のハッシュを返す。
###### 計算量
$O(1)$

#### hash 型について
##### 文字列の結合
`hash + hash` <br>
`hash += hash`<br>
これらの演算は文字列の結合に対応する演算である。
###### 計算量
$O(1)$
 
##### その他
`.val()` 値を返す。
`hash < hash` 値の大小比較
