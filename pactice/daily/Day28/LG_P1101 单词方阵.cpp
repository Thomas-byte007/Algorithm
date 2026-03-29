#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// 定义最大尺寸，题目中 n <= 100
const int MAXN = 105;

int n;
char grid[MAXN][MAXN];
bool keep[MAXN][MAXN]; // 标记该位置是否属于单词 "yizhong"

// 8 个方向的增量：右，左，下，上，右下，左下，右上，左上
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

string target = "yizhong";

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n)) return 0;

    // 读取矩阵
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // 初始化标记数组为 false
    memset(keep, 0, sizeof(keep));

    // 遍历每一个格子
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 只有当当前字符是 'y' 时，才可能是单词的开头
            if (grid[i][j] == 'y') {
                // 尝试 8 个方向
                for (int k = 0; k < 8; ++k) {
                    bool match = true;
                    // 检查长度为 7 的单词是否匹配
                    for (int len = 0; len < 7; ++len) {
                        int nx = i + dx[k] * len;
                        int ny = j + dy[k] * len;

                        // 1. 边界检查：如果超出矩阵范围，则匹配失败
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            match = false;
                            break;
                        }

                        // 2. 字符检查：如果字符不匹配，则匹配失败
                        if (grid[nx][ny] != target[len]) {
                            match = false;
                            break;
                        }
                    }

                    // 如果该方向完全匹配，则标记这 7 个位置
                    if (match) {
                        for (int len = 0; len < 7; ++len) {
                            int nx = i + dx[k] * len;
                            int ny = j + dy[k] * len;
                            keep[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (keep[i][j]) {
                cout << grid[i][j];
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}
