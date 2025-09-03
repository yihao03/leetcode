#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Coord {
  int x, y;
  bool operator==(const Coord &other) const {
    return x == other.x && y == other.y;
  }
};
template <> struct hash<Coord> {
  size_t operator()(const Coord &c) const {
    return hash<int>()(c.x) ^ (hash<int>()(c.y) << 1);
  }
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    unordered_map<char, vector<Coord>> charMap;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        charMap[board[i][j]].push_back(Coord{i, j});
      }
    }

    vector<string> result;

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    for (auto &word : words) {
      if (charMap.find(word[0]) == charMap.end()) {
        continue;
      }

      queue<pair<Coord, int>> q;
      unordered_map<Coord, bool> visited;

      for (const auto &pos : charMap[word[0]]) {
        q.push(pair{pos, 0});
      }

      while (!q.empty()) {
        pair<Coord, int> curr = q.front();
        q.pop();
        if (curr.second == word.size() - 1) {
          result.push_back(word);
          break;
        }

        if (visited[curr.first]) {
          continue;
        }

        visited[curr.first] = true;

        for (int i = 0; i < 4; ++i) {
          Coord cur = curr.first;
          Coord next{cur.x + dx[i], cur.y + dy[i]};
          if (next.x >= 0 && next.x < board.size() && next.y >= 0 &&
              next.y < board[0].size() && board[next.x][next.y] == word[i]) {
            q.push({next, curr.second + 1});
          }
        }
      }
    }
    return result;
  }
};
