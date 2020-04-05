// https://onlinejudge.org/external/119/11902.pdf

#include <bits/stdc++.h>
using namespace std;

int t, n, in;
vector<vector<int>> AL;
vector<int> status;
vector<int> dfs_num;

void dfs(int u) {
  if (dfs_num[u] == -1) {
    status[u] = 1;
    dfs_num[u] = 1;
    for (auto &v : AL[u]) {
      if (dfs_num[v] == -1) {
        dfs(v);
      }
    }
  }
}

void reset() {
  for (int i = 0; i < n; i++)
    dfs_num[i] = -1;
}

void resetStatus() {
  for (int i = 0; i < n; i++)
    status[i] = -1;

  dfs(0);

  for (int i = 0; i < n; i++)
    if (status[i] == 1) status[i] = 0;
}

void printBoard() {
  int p = n * 2;
  for (int k = 1; k < p; k++) {
    if (k == 1) cout << "+";
    cout << "-";
    if (k == p - 1) cout << "+";
  }
  cout << endl;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      dfs_num.push_back(-1);
      status.push_back(false);
      vector<int> tmp;
      for (int k = 0; k < n; k++) {
        cin >> in;
        if (in == 1) tmp.push_back(k);
      }
      AL.push_back(tmp);
    }

    cout << "Case " << i + 1 << ":" << endl;
    for (int j = 0; j < n; j++) {
      printBoard();
      reset();
      resetStatus();
      reset();
      dfs_num[j] = 1;
      dfs(0);
      for (int k = 0; k < n; k++) {
        cout << "|";

        if (status[k] == -1 || status[k] == 1) cout << "N";
        else cout << "Y";

        if (k == n - 1) cout << "|";
      }
      cout << endl;
      if (j == n - 1) printBoard();
    }
    AL.clear();
    dfs_num.clear();
    status.clear();
  }
  return 0;
}
