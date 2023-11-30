#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc để lưu trữ tọa độ của một điểm
struct Point {
    int x, y;
};

// Hàm kiểm tra điểm có nằm trong ảnh hay không
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Hàm Flood Fill sử dụng DFS để xác định các điểm ảnh kề nhau có cùng màu
void floodFillDFS(const vector<vector<int>> &image, int x, int y, int color, vector<vector<bool>> &visited) {
    int rows = image.size();
    int cols = image[0].size();

    // Kiểm tra điểm có hợp lệ không và có cùng màu không
    if (!isValid(x, y, rows, cols) || image[x][y] != color || visited[x][y]) {
        return;
    }

    // Đánh dấu điểm này đã được thăm
    visited[x][y] = true;

    // In ra điểm hiện tại
    cout << "(" << x << ", " << y << ") ";

    // Duyệt các điểm lân cận
    floodFillDFS(image, x + 1, y, color, visited);
    floodFillDFS(image, x - 1, y, color, visited);
    floodFillDFS(image, x, y + 1, color, visited);
    floodFillDFS(image, x, y - 1, color, visited);
}

int main() {
    // Ví dụ ảnh đầu vào
    vector<vector<int>> image = {
        {1, 1, 1, 2, 1},
        {1, 2, 2, 2, 1},
        {1, 1, 1, 1, 1},
        {2, 2, 1, 2, 2}
    };

    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    
    // Ví dụ xác định các điểm ảnh kề nhau có cùng màu tại một điểm bắt đầu
    int x = 1; // Tọa độ x bắt đầu
    int y = 1; // Tọa độ y bắt đầu
    int color = image[x][y]; // Lấy màu tại điểm bắt đầu
    floodFillDFS(image, x, y, color, visited);
    cout << endl;

    return 0;
}
