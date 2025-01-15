#include <iostream>
#include <vector>
#include <queue>
#include <utility> // Для std::pair

using namespace std;

const int ROWS = 5; // Количество строк
const int COLS = 5; // Количество столбцов

// Функция для выполнения волнового алгоритма и поиска пути
bool waveAlgorithm(int maze[ROWS][COLS], pair<int, int> start, pair<int, int> end) {
    // Проверка корректности стартовой и конечной точки
    if (maze[start.first][start.second] == 1 || maze[end.first][end.second] == 1) {
        return false; // Невозможно начать или закончить в стене
    }

    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    queue<pair<int, int>> q;

    // Направления движения: вниз, вверх, вправо, влево
    int moves[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        // Проверка, достигли ли мы конечной точки
        if (current == end) {
            return true;
        }

        // Перебор всех возможных направлений
        for (int i = 0; i < 4; i++) {
            int newRow = current.first + moves[i][0];
            int newCol = current.second + moves[i][1];

            // Проверка валидности нового положения
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS &&
                maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push(make_pair(newRow, newCol));
            }
        }
    }

    return false; // Путь не найден
}

int main() {
    setlocale(LC_ALL, "Russian");
    int maze[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0}
    };

    pair<int, int> start = { 0, 0 }; // Стартовая позиция
    pair<int, int> end = { 4, 4 };   // Конечная позиция

    if (waveAlgorithm(maze, start, end)) {
        cout << "Путь найден!" << endl;
    }
    else {
        cout << "Путь не найден." << endl;
    }

    return 0;
}