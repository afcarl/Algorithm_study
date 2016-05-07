/*
 * POJ1753_Flip_Game.cpp
 *
 * Author: Haozhi Qi
 * Copyright (c) 2016 Haozhi Qi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

bool check_cond(int state) {
  if (state == 0 || state == 65535) return true;
  else return false;
}

int main() {

  // predefined array to do flip operations
  int state_trans[16] = {
    51200, 58368, 29184, 12544,
    35968, 20032, 10016,  4880,
     2248,  1252,   626,   305,
      140,    78,    39,    19 };

  vector<bool> visit(65536, false);
  vector<int> steps(65536, 0);
  
  // initialize input
  int state = 0;
  for (int i = 0; i < 4; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 4; ++j) {
      state <<= 1;
      if (s[j] == 'b') state += 1;
    }
  }

  if (check_cond(state)) {
    cout << steps[state] << endl;
    return 0;
  }

  queue<int> state_queue;
  state_queue.push(state);

  while (!state_queue.empty()) {
    int cur_state = state_queue.front();
    state_queue.pop();
    for (int i = 0; i < 16; ++i) {
      int next_state = cur_state ^ state_trans[i];
      if (visit[next_state]) continue;
      visit[next_state] = true;
      steps[next_state] = steps[cur_state] + 1;
      if (check_cond(next_state)) {
        cout << steps[next_state] << endl;
        return 0;
      }
      state_queue.push(next_state);
    }
  }
  cout << "Impossible" << endl;
  return 0;
}