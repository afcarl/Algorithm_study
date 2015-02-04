Since my english is not well enough to describe the solutions, I decide to write this solution using Chinese.

The english version of official solution can be found here:

http://codeforces.com/blog/entry/16173

which is written by the author of these problem sets.

<h3> Codeforces #290 </h3>
<hr>

<h3> Problem A </h3>
弱题，毫无描述必要。
画蛇，分情况讨论一下就好。

https://github.com/Oh233/Algorithm_study/blob/master/codeforces/Round%23290/510A.cpp
<hr>

<h3> Problem B </h3>
其实也应该是一个水题，我之前确实没有独立做过这样的题，导致花了相当长的时间，后来心思乱了也没有做出来。

大意是说有一个字母矩阵，其中相同字母可以看成是一条联通的道路，然后问这个图中是否可能有环出现。开始第一反应就是dfs，但是猛然想起自己就没用过几次dfs，就有点慌。第一次写采用的方法是输入时候按1-26输入，然后遍历一遍的时候变成27-52，然后检测起始点是否变成原来的值+26了来判断对错。

这种方法还是有很大的缺陷的，用了几十分钟调最后就是越调越乱不能自拔。

后来稍稍百度了一下发现了dfs的正规写法，可惜是一维（node标记为1，2，3这样）的，但是具体思想看明白了，是一个bool返回值的dfs。然后我自己在写的时候出了问题。问题在于一维毕竟是一维，return时候就说明遍历完了。但是二维却是不能随便return的，因为可能只能遍历一个方向，然后dfs就结束了，所以这样就造成了错误，后来改成void就过了。

以此可以扩展出模板吧，《dfs二维图判断是否有环》

https://github.com/Oh233/Algorithm_study/blob/master/codeforces/Round%23290/510B.cpp
