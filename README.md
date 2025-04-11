<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/3.2.2/es5/tex-mml-chtml.min.js">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>


# README
## 課題内容
有限差分法を用いて，２次元ポアソン方程式を解く\
$$1+1=2$$

## 提出期限
5月15日まで

## 課題詳細
・現在はshellscript，cmakeを使って"Hello World"を出力するプロジェクトになっています．\
・適当なファイルや関数を追加して，ポアソン方程式を解くように変更してください

## 計算条件
・形状データは，"Input"ディレクトリ内のものを使う．\
・ディリクレ境界境界条件では，下底で0，上底で1．\
・ノイマン境界条件は，境界で0

## その他
・ファイル名や実行ファイル名，関数名は適宜わかりやすいものに変えてください．\
・変数の宣言は極力class内で行い，引数が少なくなるようにしてください．\

## 最初の実行方法
$ sh run.sh\
$ cd build \
$ ./HelloWorld\ 