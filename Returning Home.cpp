
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    
    vector<pair<int, int>> portals(m);
    for (int i = 0; i < m; ++i) {
        cin >> portals[i].first >> portals[i].second;
    }
    
    // 基本曼哈顿距离
    int min_time = abs(sx - fx) + abs(sy - fy);
    
    // 找出起点和终点附近的传送点
    vector<pair<int, int>> near_start, near_end;
    
    for (auto [x, y] : portals) {
        if (x == sx || y == sy) {
            near_start.emplace_back(x, y);
        }
        if (x == fx || y == fy) {
            near_end.emplace_back(x, y);
        }
    }
    
    // 计算通过传送点的最短路径
    // 情况1：直接使用一个传送点
    for (auto [x, y] : near_start) {
        int dist = abs(x - fx) + abs(y - fy);
        min_time = min(min_time, dist);
    }
    
    for (auto [x, y] : near_end) {
        int dist = abs(sx - x) + abs(sy - y);
        min_time = min(min_time, dist);
    }
    
    // 情况2：使用两个传送点（起点传送点→终点传送点）
    if (!near_start.empty() && !near_end.empty()) {
        // 找出起点传送点到终点传送点的最小曼哈顿距离
        int min_dist = INT_MAX;
        for (auto [x1, y1] : near_start) {
            for (auto [x2, y2] : near_end) {
                int dist = abs(x1 - x2) + abs(y1 - y2);
                min_dist = min(min_dist, dist);
            }
        }
        min_time = min(min_time, min_dist);
    }
    
    cout << min_time << endl;
    
    return 0;
}
