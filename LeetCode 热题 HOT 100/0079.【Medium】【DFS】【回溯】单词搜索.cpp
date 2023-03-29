
// DFS
class Solution {
public:
    // 阵的行和列
    int m, n; 

    // 偏移量数组
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS 函数：判断能否从 matrix[x][y] 开始搜索到字符串 str[u ~ n-1]
    bool dfs(vector<vector<char>>& matrix, string str, int u, int x, int y) {
        // 递归出口：
        if (matrix[x][y] != str[u]) return false; // 若当前搜索到的位置和字符串的下标 u 不匹配，则搜索失败
        if (u == str.size() - 1) return true; // 若已经匹配到了最后一个字符了，返回true，搜索成功

        char t = matrix[x][y]; // 先保存下当前遍历位置的字符 

        // 如果 t == matrix[x][y] 且 u != str.size() - 1
        matrix[x][y] = '*'; // 将当前遍历位置的字符设置成特殊字符

        // 枚举下一个遍历的位置 (a, b)
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            // 若（a, b）越界或（a, b）已经被走过，则跳过
            if (a < 0 || a > m - 1 || b < 0 || b > n -1 || matrix[a][b] == '*') continue;
            // 若下一个字符可以搜索成功，则搜索成功
            if (dfs(matrix, str, u + 1, a, b) == true) return true;
        }

        // 若向 4 个方向枚举都不成功，则恢复当前字符，返回 false
        matrix[x][y] = t;
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


// 无注释版本


class Solution {
public:
    // 阵的行和列
    int m, n; 

    // 偏移量数组
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS 函数：判断能否从 board[x][y] 开始搜索到字符串 str[u ~ n-1]
    bool dfs(vector<vector<char>>& board, string str, int u, int x, int y) {
        // 递归出口：
        if (board[x][y] != str[u]) return false; // 若当前搜索到的位置和字符串的下标 u 不匹配，则搜索失败
        if (u == str.size() - 1) return true; // 若已经匹配到了最后一个字符了，返回true，搜索成功

        char t = board[x][y]; // 先保存下当前遍历位置的字符 

        // 如果 t == board[x][y] 且 u != str.size() - 1
        board[x][y] = '*'; // 将当前遍历位置的字符设置成特殊字符

        // 枚举下一个遍历的位置 (a, b)
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            // 若（a, b）越界或（a, b）已经被走过，则跳过
            if (a < 0 || a > m - 1 || b < 0 || b > n -1 || board[a][b] == '*') continue;
            // 若下一个字符可以搜索成功，则搜索成功
            if (dfs(board, str, u + 1, a, b) == true) return true;
        }

        // 若向 4 个方向枚举都不成功，则恢复当前字符，返回 false
        board[x][y] = t;
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


// 无注释版本

class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string str, int u, int x, int y) {
        if (board[x][y] != str[u]) return false;
        if (u == str.size() - 1) return true;

        char t = board[x][y];

        board[x][y] = '*';

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a > m - 1 || b < 0 || b > n -1 || board[a][b] == '*') continue;
            if (dfs(board, str, u + 1, a, b) == true) return true;

        }

        board[x][y] = t;

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