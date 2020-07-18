# 課題4 レポート

bb35319023 近藤さき

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.5: 構造体を定義する

l.21: Input the file name of sample height : を出力

l.22: データファイル名を入力させ，fname1に格納

l.23: fname1の文字列の最後をヌル文字'\0'に置換

l.25: fname1で指定したファイルの先頭アドレスをファイルポインタfp1に読み込む

l.26: もしfp1がNULLだったときは，File open errorを出力して，即座にプログラム終了

l.31: Input the file name of sample ID : を出力

l.32: データファイル名を入力させ，fname2に格納

l.33: fname2の文字列の最後をヌル文字'\0'に置換

l.35: fname2で指定したファイルの先頭アドレスをファイルポインタfp2に読み込む

l.36: もしfp2がNULLだったときは，File open errorを出力して，即座にプログラム終了

l.41: Which ID's data do you want? : を出力

l.42: 学籍番号を入力

l.44: ---を出力

l.46: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.47: fp1を読み込んでdata[i].genderとdata[i].heightに格納

l.48: fp2を読み込んでdata[i].idに格納

l.50: もし入力した学籍番号がリストにあれば，以下を行う

l.51: 学籍番号を出力

l.52: もしgenderが1ならMaleを出力．違うならFemaleを出力

l.58: 身長を出力

l.61: 学籍番号がリストになくてiが13なら，No dataを出力

l.65: iに1を足す

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

