
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word
// 如果 word 存在于网格中，返回 true ；否则，返回 false

// DFS + 回溯
class Solution {
public:
    // 阵的行和列
    int m, n; 

    // 偏移量数组
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS 函数：判断能否从 board[x][y] 开始搜索到字符串单词 s[u ~ n - 1]
    bool dfs(vector<vector<char>>& board, string word, int u, int x, int y) {
        // 递归出口：（注意以下两行的顺序不能反）
        if (board[x][y] != word[u]) return false; // 若当前搜索到的位置和字符串的下标 u 不匹配，则搜索失败
        if (u == word.size() - 1) return true; // 若已经匹配到了最后一个字符了，返回true，搜索成功

        char c = board[x][y]; // 保存 当前遍历位置的字符

        board[x][y] = '#'; // 先将当前遍历位置的字符设置成特殊字符

        // 枚举下一个遍历的位置 (a, b)
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            // 若（a, b）越界或（a, b）已经被走过，则跳过
            if (a < 0 || a >= m || b < 0 || b >= n || board[a][b] == '#') continue;
            // 若下一个字符可以搜索成功，则搜索成功
            if (dfs(board, word, u + 1, a, b) == true) return true;
        }

        board[x][y] = c; // 若向 4 个方向枚举都不成功，则恢复当前字符，返回 false

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // 遍历矩阵的每个点 (i, j)，从 (i, j) 开始搜索 word
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                // 如果遍历某个起点 (i, j) 时，能找到 word，则搜索成功
                if (dfs(board, word, 0, i, j) == true) return true;
            }
        }

        // 如果遍历完了整个矩阵都没有扎到 word，则搜索失败
        return false;
    }
};


// DFS 框架
class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string word, int u, int x, int y) {
        
    }

    bool exist(vector<vector<char>>& board, string word) {

    }
};


// 无注释版本
class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string word, int u, int x, int y) {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true;

        char c = board[x][y];
        
        board[x][y] = '#';

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a >= m || b < 0 || b >= n || board[a][b] == '#') continue;
            if (dfs(board, word, u + 1, a, b) == true) return true;
        }

        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (dfs(board, word, 0, i, j) == true) return true;
            }
        }

        return false;
    }
};
