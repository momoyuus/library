## Nimber

#### 概要

和が bitwise xor の有限体。位数は $2^{64}$。積は Nim Product。使い方は基本的に ACL の modint と同じ。  

参考  
https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850  
https://natsugiri.hatenablog.com/entry/2020/03/29/073605  

#### 使い方
##### コンストラクタ
`Nimber()`：0が格納される。  
`Nimber(uint64 x)`：xが格納される。  

##### 演算
`- Nimber`
`Nimber + Nimber`<br>
`Nimber - Nimber`<br>
`Nimber * Nimber`  
`Nimber / Nimber`  
`Nimber += Nimber`  
`Nimber -= Nimber`  
`Nimber *= Nimber`  
`Nimber /= Nimber`
`Nimber == Nimber`
が可能。  

##### メソッド
`uint64 x.val()`：値を返す。  
`Nimber x.inv()`：$x\otimes y=1$ となる $y$ を返す。  
`Nimber x.sqrt()`：$y \otimes y = x$ となる $y$ を返す。  
`vector<Nimber> Nimber::solve(Nimber b,Nimber c)`：$x\otimes x \oplus b \otimes x \oplus c = 0$ となる $x$ をすべて返す。  

計算量はどれも、 $w=64$ として、 $O(w^{\log 3}\log w)$ とか。  


