
Since my english is not well enough to describe the solutions, I decide to write this solution using Chinese.

The english version of official solution can be found here:
http://codeforces.com/blog/fcspartakm
which is written by the author of these problem sets.

Codeforces #288

Problem A

类似于染色问题，给一个n * m的方块矩阵，然后有k步染色，每一步提供染色点的横纵坐标值。
如果到某一步的时候恰好出现了有一块2*2的方阵全被染色了的话就输出这一步的步数，如果全部步数都走完了仍然没有出现这样的方阵的话就输出0。

本来这道题我的代码很丑的，就是先判断是不是在角上，再判断是不是在边上，在判断不是以上两种的话该怎么办，结果就写了很长很长也浪费了时间。可是这道题出现在第一题的位置，不该这么费时间。思考了一下之后发现横纵坐标其实都是从1开始的，那么也就是说只要把数组开的合适，那其实无论在不在矩阵的角上，判断四方方块的时候都是不会越界的。
暴力搜，scanf 46ms，cin 300ms，不解释。

https://github.com/Oh233/Algorithm_study/blob/master/codeforces/Round%23288/508A.cpp
