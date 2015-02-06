
/* 来自codeforce的510C
 * 用队列写的拓扑排序
 * 其中n是点的个数
 * ans这个东西更多的相当于点所带的性质，原题中是点自身代表的字母
 * 这个性质当然可以更换
 */

string ans;
queue<int> q;

bool topo_sort(int n) {

  // 算每一个点的入度
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      if (w[i][j]) in[j]++;
    }
  }

  for (int i=1;i<=n;i++) {
    if (in[i] == 0) {
      q.push(i);
      ans += i-1+'a';
    }
  }

  while (!q.empty()) {
    int tmp = q.front(); q.pop();
    for (int i=1;i<=n;i++) {
      if (w[tmp][i]) {
	in[i]--;
	if (in[i] == 0) {
	  q.push(i);
	  ans += i-1+'a';
	}
      }
    }
  }

  if (.....) return false;
  else return true;
}
