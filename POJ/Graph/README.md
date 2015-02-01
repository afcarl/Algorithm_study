Hello everyone.

This is the file containing tutorial of my solutions.
Since my english is not good enough and most of POJ users are Chinese students, I decided to write the tutorial using Chinese language. If any foreign users want to communicate with me, you can contact me using github or gmail: nevermrqi@gmail.com

<h3> POJ 1789 </h3>
<hr>
<h4> 朴素prim </h4>

之前做过这道题，没过，于是这几天复习的时候继续做。这道题就是一张十分稠密的图，综合来看用邻接矩阵存权值不浪费内存又好写。
然后就是run一个朴素的prim算法，之前想要加堆的优化发现还是有一些难做，觉得过一些日子再研究好了。
没什么可说的，权值就是从1到7计算一下。
之前做的错误是因为邻接矩阵没有memset，因为当时的方法检测如果是0就设为INF，但是没有memset就有上一次test_case跑过的地方设定了错误的权值。
最后也没用string，改成char*数组完事。

<h3> POJ 2075 </h3>
<hr>
<h4> 朴素prim </h4>

嘛，其实prim的min_cost[i]数组就是从已生成的集合中到外面点的最小距离。
vis来记是否生成的点。
然后一个prim完事，略微值得一说的是这道题的点也是以string形式给出的。那么因为这里是按顺序给并且不会有重复，所以就用一个map标记转换一下就可以。联想起cf的508D那道题需要加hash value是因为可能有重复并且不能简单的标记为1，2，3，4。嗯还是很合理的。

<h3> POJ 3255 </h3>
<hr>
<h4>dijkstra求次短路</h4>

这道题是我那本小白书上的题，大意就是要找一条从点1到点N的次短路径。
开始的时候完全没有头绪，甚至dijkstra的堆实现也都没有看过，读了好几遍题解终于明白了，下面就详细说一下。
首先用邻接表建图这一步就不说了，之前试了一下，用邻接矩阵存数据的话会MLE

<h3> POJ 3723 </h3>
<hr>
<h4> Kruskal 并查集 生成树 </h4>

这道题依然是我的小白书上的题，是kruskal的一道练习题。
