## Two-Edge-Connected Components

#### 概要

グラフを二辺連結成分分解するライブラリ。

#### 使い方
##### コンストラクタ
`two_edge_connected_components_graph g(n)`<br>
$n$ 頂点のグラフを作成する。

##### 辺の追加
`void g.add_edge(u,v)`<br>
$uv$ 間に辺を貼る。

###### 計算量
$O(1)$

##### 構築
`void g.build()`<br>
二辺連結成分分解を行う。これ以降のメソッドは build が呼ばれた後に呼ばれることが想定されている。
###### 計算量
$O(n + m)$ ($m =$ 追加した辺の数)

##### 成分の列挙
`vector<vector<int>> g.groups()`<br>
二辺連結成分ごとに頂点を分割した vector を返す。
###### 計算量
$O(n)$

##### 成分を縮約したグラフ
`vector<vector<int>> g.graph()`<br>
二辺連結成分を縮約したグラフを返す。
###### 計算量
$O(1)$

##### 辺素なパスの構築
`pair<vector<int>,vector<int>> g.two_way(int u,int v)`<br>
頂点 u から頂点 v への辺素なパスを 2 つ返す。ただし、頂点 u と頂点 v が同じ成分内に含まれないときは -1 が格納された vector を 2 つ返す。パスは辺の番号の列で表され、始点が u 、終点が v となっている。辺の番号は辺を追加した順に 0,1,...,m となる。<br>
[https://codeforces.com/gym/104871/problem/K](https://codeforces.com/gym/104871/problem/K)

###### 計算量
$O(n+m)$

##### その他
`int g[u]`：頂点 u の縮約後の頂点番号を返す。<br>

