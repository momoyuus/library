## Lagrange_arithmetic_point

#### 概要

評価点が等差数列であり，一点取得をするラグランジュ補間．主にACLのmodintでの使用を想定．

#### 使い方
`T Lagrange_arithmetic_point(vector<T>a,vector<T>b,long long k)`：$f(a[\mathrm{i}])=b[\mathrm{i}]$ を満たす $(|a|-1)$ 次多項式 $f(x)$ における $f(k)$ の値を返す．計算量は $O(|a|f(p))\ (\text{ただし }f(p)\text{ は逆元を求める計算量})$ ．配列 $a$ の値は等差数列であることを仮定している．