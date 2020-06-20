# 課題2 レポート

bb35319023 近藤さき

## 課題

住んでるA県で生まれた（ジモティー）20代の男性の平均と分散が<img src="/k02/tex/505f14fecb9a1a896d66ff55d4830d14.svg?invert_in_darkmode&sanitize=true" align=middle width=37.964262599999984pt height=14.15524440000002pt/>,<img src="/k02/tex/61d0881cbd9597f2afc5ee6147e6da11.svg?invert_in_darkmode&sanitize=true" align=middle width=37.45244579999999pt height=26.76175259999998pt/>と公式発表された．また，隣のB県生まれの男性は，平均と分散が<img src="/k02/tex/8e823eaddf9d4738b30c3121f913b75b.svg?invert_in_darkmode&sanitize=true" align=middle width=38.57096924999999pt height=14.15524440000002pt/>,<img src="/k02/tex/20581e810ba3c6dc9f33f9713b7593e5.svg?invert_in_darkmode&sanitize=true" align=middle width=38.059152449999985pt height=26.76175259999998pt/>と公式発表されている．このとき，手元の標本の尤もらしさ（尤度）をA県生まれとB県生まれについて求めよ．実際にはもちろんA県・B県以外の県で生まれる人もいるし，標本の全員が同じ県生まれということはないので，この結果の大小からは何も言えない．
   
`double p_stdnorm(double z)`は，平均0，分散1の正規分布（標準正規分布;<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>）における値zの出現確率を出力する関数である．平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>，分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>の正規分布（<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>）の確率密度曲線は標準正規分布<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>の確率密度曲線と相似である．相似において，<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>における<img src="/k02/tex/f93ce33e511096ed626b4719d50f17d2.svg?invert_in_darkmode&sanitize=true" align=middle width=8.367621899999993pt height=14.15524440000002pt/>が，<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>における<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>に対応しているとすると，<img src="/k02/tex/f93ce33e511096ed626b4719d50f17d2.svg?invert_in_darkmode&sanitize=true" align=middle width=8.367621899999993pt height=14.15524440000002pt/>は<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>を使って，<img src="/k02/tex/1d1740bcb6e27e24710980e02d52a3c1.svg?invert_in_darkmode&sanitize=true" align=middle width=71.64894989999998pt height=41.4194451pt/>と書ける．この操作をxの「標準化」といい，zを「Z統計量」という．つまり，どんな正規分布上の変数もZ統計量を求めるとそれは標準正規分布に従う．

尤度とは，標本と仮定分布の類似度をあらわす．仮定分布のもとで標本中のデータのそれぞれが同時に出現する同時確率である．尤度<img src="/k02/tex/ddcb483302ed36a59286424aa5e0be17.svg?invert_in_darkmode&sanitize=true" align=middle width=11.18724254999999pt height=22.465723500000017pt/>は
<p align="center"><img src="/k02/tex/b0546b665f9803a72be90a9a55348d3d.svg?invert_in_darkmode&sanitize=true" align=middle width=382.1801676pt height=47.806078649999996pt/></p>
と計算できる．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>は仮定した確率密度関数で，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>はその母数．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>が正規分布なら，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>は，平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>と分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>である．

## ソースコードの説明
l.18: input the filename of sample:を出力

l.19: データファイル名を入力させ、fnameに格納

l.20: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.21: fnameを出力

l.23: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.24: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.29: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.30: bufからsscanfで数値文字列を実数としてvalに読み込む

l.31: z1に(val-mu1)/sigma1を代入

l.32: z2に(val-mu2)/sigma2を代入

l.33: L1にL1*p_stdnorm(z1)を代入

l.34: L2にL2*p_stdnorm(z2)を代入

l.38: ファイルを閉じる．閉じれないときは，即座にプログラム終了

l.43: A県生まれについての尤度L1の値を出力

l.44: B県生まれについての尤度L2の値を出力

l.51: 標準正規分布におけるzの出現確率を出力する関数を作る

## 入出力結果

```
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv
L_A: 0.000006
L_B: 0.000002
```

## 修正履歴
[comment #20200618]
- ソースコードはOKです. 
- 出力結果を貼り付けてください. 

[comment #20200620]
- OKです. 