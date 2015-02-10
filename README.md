# Algorithm_study
Notes on studying algorithm

===========================2015/1/30 UPDATE===============================

Some of my solutions haven't been uploaded to github (Since I decide to use it to store my solution recently), you can find them at http://blog.csdn.net/oh233, but this is written by Chinese.

<hr>
<h2 style="text-align:center"> 一只弱菜的日记 </h2> </center>

<h3> 2015/2/1 </h3>
还挺不想用这个称呼叫自己的，从当年天不怕地不怕的少年，到现在越来越认清楚自己的实力，这个过程也是比较的心酸乏力。
开这篇日志，也是记载一下心路历程，如果能激励后人一二，想必也是功德一件。
今天给昨天做的codeforces补题，C题还是挺难的。是一个贪心题。但是我改了一天都没有过，最后请教了yre同学，在她的帮助下终于过掉了这个题。
和yre同学吃饭的时候聊到，为什么现在以我的水平能看到的cf题都是这样似乎没有算法包含的题，都是一些暴力搜索+某些优化就能做出来。她说了几点，但我认为可能往后做就好了，现在以提升自己的实力为要义，切不可急于求成。

切不可急于求成。要静心。


<hr>
<h3> Target Problem </h3>

<hr>
Problem Statement
    
You have a string s that contains at least K characters. Cat Snuke will remove exactly K characters from the string. Afterwards, Snuke will show you the new string and you have to guess the original indices of all removed characters. You win the game if you guess all of them correctly.  For example, suppose that s="snuke" and K=2. Snuke removed two characters and showed you the string "nue". In this situation you can easily deduce that Snuke must have removed the characters s[0] and s[3]. You announce that the indices of removed characters are 0 and 3, and you win the game.  You are given the string s and the int K. Return "Certain" (quotes for clarity) if you can always be sure to win the game, regardless of which characters Snuke removes. Otherwise, return "Uncertain". Note that the return value is case-sensitive.
Definition
    
Class:
Decipherability
Method:
check
Parameters:
string, int
Returns:
string
Method signature:
string check(string s, int K)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
K will be between 1 and 50, inclusive.
-
The length of s will be between K and 50, inclusive.
-
Every character in s will be a lowercase letter ('a'-'z').
Examples
0)

    
"snuke"
2
Returns: "Certain"
This is the example from the problem statement. As all characters are unique, you can always determine the indices of the erased ones.
1)

    
"aba"
1
Returns: "Certain"
Snuke will show you one of the strings "ba", "aa", and "ab". In the first case you can be sure that he erased the character at index 0. The second and the third string correspond to indices 1 and 2, respectively.
2)

    
"aba"
2
Returns: "Uncertain"
If Snuke shows you the string "a", there are two possibilities: either he erased the characters at indices 0 and 1, or the characters at indices 1 and 2.
3)

    
"abcdabcd"
3
Returns: "Certain"

4)

    
"koukyoukoukokukikou"
2
Returns: "Uncertain"

5)

    
"wolfsothe"
8
Returns: "Uncertain"

6)

    
"aa"
2
Returns: "Certain"

<hr>

Problem Statement
    
You are given an integer sequence A and an int N that is a power of 2. All elements of A are between 0 and N-1, inclusive.  You can now choose an integer B which is between 0 and N-1, inclusive. This integer determines a new sequence C defined as follows: For each valid i, C[i] = (A[i] xor B).  Given the sequence C, we will count the pairs of indices (i,j) such that both i<j and C[i]<C[j]. Compute and return the largest result we can obtain.  You are given the int N. You are also given ints sz, A0, A1, P, Q, and R. Use the following pseudocode to generate the sequence A:  
A[0] = A0;
A[1] = A1;
for (i = 2; i < sz; i++) {
    A[i] = (A[i - 2] * P + A[i - 1] * Q + R) modulo N;
}
Definition
    
Class:
XorSequence
Method:
getmax
Parameters:
int, int, int, int, int, int, int
Returns:
long long
Method signature:
long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
Watch out for integer overflow when generating the sequence A.
Constraints
-
N will be between 2 and 1,073,741,824 (2^30), inclusive.
-
N will be a power of 2.
-
sz will be between 2 and 131,072, inclusive.
-
A0 will be between 0 and N-1, inclusive.
-
A1 will be between 0 and N-1, inclusive.
-
P will be between 0 and N-1, inclusive.
-
Q will be between 0 and N-1, inclusive.
-
R will be between 0 and N-1, inclusive.
Examples
0)

    
4
6
3
2
0
1
3
Returns: 8
Using the provided pseudocode you should compute that A={3,2,1,0,3,2}. For B=3 we then get C={0,1,2,3,0,1}. For this C there are 8 pairs (i,j) such that i<j and C[i]<C[j]. These are the 8 pairs: (0,1), (0,2), (0,3), (0,5), (1,2), (1,3), (2,3), and (4,5). No other choice of B produces more than 8 pairs.
1)

    
8
8
2
5
3
1
4
Returns: 13
A={2,5,7,2,3,5,2,5}.
2)

    
8
7
3
0
1
2
4
Returns: 12
A={3,0,7,2,7,4,3}.
3)

    
32
15
7
9
11
2
1
Returns: 60
A={7,9,0,4,9,31,2,26,11,21,4,16,13,11,6}.
4)

    
131072
131072
7
7
1
0
0
Returns: 0
All elements of A are equal to 7. Regardless of the value of B you choose, all elements in C will be equal as well. Thus, the number of pairs we seek is always zero.
5)

    
131072
131070
411
415
398
463
9191
Returns: 4302679760

<hr>

Problem Statement
    
You have one or more sequences of shopping carts. You are given the lengths of these sequences in a vector <int> a. You are going to remove all the shopping carts.  The process of removing the carts will consist of one or more turns. Each turn will take exactly one minute. At the beginning of each turn, you will have some sequences of carts. For each of those sequences you can choose between two options:
split it (in an arbitrary place) into two shorter sequences
remove one shopping cart from the sequence
  There is one additional constraint: during the entire process you can only choose to split a sequence at most b times.  You are given vector <int> a and int b. Compute and return the smallest number of minutes in which it is possible to remove all the carts.
Definition
    
Class:
CartInSupermarket
Method:
calcmin
Parameters:
vector <int>, int
Returns:
int
Method signature:
int calcmin(vector <int> a, int b)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
The number of elements in a will be between 1 and 50, inclusive. 
-
Each element in a will be between 1 and 1,000,000,000, inclusive. 
-
b will be between 0 and 1,000,000,000, inclusive.
Examples
0)

    
{8}
3
Returns: 4
We have a single sequence of 8 carts and we can use at most 3 splits. The optimal solution takes 4 minutes. During the first minute split the sequence of 8 carts into two sequences with 4 carts each. During the second minute perform two splits, dividing each of the two 4-cart sequences into two new sequences with 2 carts each. Thus, after the second minute you will have four sequences of 2 carts. In the third minute choose to remove a cart from each of them. Repeat that choice in the fourth minute and you are done.
1)

    
{6,6,5}
3
Returns: 4
One optimal solution with only 4 minutes looks as follows:
Split each of the first two sequences from 6 to 3+3. Remove a cart from the third sequence, shortening it from 5 to 4. Sequences after the first minute: {3,3,3,3,4}.
Shorten each of the sequences of length 3. Split the sequence of length 4 into 2+2. Sequences after the second minute: {2,2,2,2,2,2}.
Shorten each sequence. Sequences after the third minute: {1,1,1,1,1,1}.
Shorten each sequence again and you are done.
2)

    
{12,5,6,2,6,8}
4
Returns: 6

3)

    
{15,20,11,13,18,24,25,21,22,10,15,14,19}
0
Returns: 25

4)

    
{671122748,846444748,84701624,608579554,672060899,967957440,31438849,734849843,376589643,904285209
,80693344,211737743,85405464,444633541,293184188,935462519,146753109,972886045,496631016,601669536
,257574086,958464570,6294570,546189534,668105964,601197313,784337929,921840143,70408284,722040626
,253400894,56411549,811940644,152086353,122638884,776352066,118932182,177589709,538122558,127914469
,523761221,290027568,734517444,819458123,699130727,784698122,810265337,283326309,593596316,368671876}
6478
Returns: 3805054

<hr>




<hr>
<h3> Unwritten analysis </h3>

CF 509E
CF 509C
