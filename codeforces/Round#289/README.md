Since my english is not well enough to describe the solutions, I decide to write this solution using Chinese.

The english version of official solution can be found here:

http://codeforces.com/blog/entry/16119

which is written by the author of these problem sets.

Codeforces #289

<hr>
<h3> Problem A </h3>

水题，开一个n*n的数组，记下来a[n][n]就好了。

https://github.com/Oh233/Algorithm_study/blob/master/codeforces/Round%23289/509A.cpp

<hr>
<h3> Problem B </h3>

开始读题的时候惊了一下，题目是说给定那么n个盒子，然后给m个颜色，然后往盒子里面扔颜色，要求对于每一种颜色，任意两个盒子里面的这种颜色的个数的差不可以超过1。

开始想的是我靠这tm该怎么做。

过了一会儿自己想出了一个做法，列下：

solution 1：

首先读取数据，并且记录下最大的那个盒子，然后比如这个盒子的容量是12，然后一共有5个颜色，那就把这5个颜色先一种颜色放两个到盒子里面，然后剩下的2个空位分别放颜色1和颜色2。

处理完第一组，下面就是其他组，对于每一组来说，就算一个差，比如说有一个盒子容量是8，这个差了4，那就依次减去颜色1，2（因为这个是多加的），然后再减去5，4。依次类推。

好的，那为什么会有这种想法呢，问题就在于这个“平均分配”的思想，开始读到这道题的条件的时候我想的就是差尽量小，等同于要尽量平均的分配。这样的话最好的情况就是先把大的平均处理干净，然后再依据大的和小的的差来处理其他盒子之间的关系。

