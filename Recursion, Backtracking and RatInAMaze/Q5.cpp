#include <iostream>
using namespace std;

void print(int s[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

bool safe(int x, int y, int m[4][4], int s[4][4]) {
    return (x >= 0 && x < 4 && y >= 0 && y < 4 && m[x][y] && !s[x][y]);
}

bool solve(int x, int y, int m[4][4], int s[4][4]) {
    if (x == 3 && y == 3) {
        s[x][y] = 1;
        return true;
    }

    if (safe(x, y, m, s)) {
        s[x][y] = m[x][y];

        for (int i = 1; i <= m[x][y]; i++) {
            if (solve(x, y + i, m, s)) {
                return true;
            }
        }

        for (int i = 1; i <= m[x][y]; i++) {
            if (solve(x + i, y, m, s)) {
                return true;
            }
        }

        s[x][y] = 0;
    }

    return false;
}

int main() {
    int maze[4][4] = {
						{2, 1, 0, 0},
                      	{3, 0, 0, 1},
                      	{0, 1, 0, 1},
                      	{0, 0, 0, 1}
					 };

    int sol[4][4] = {0};

    if (solve(0, 0, maze, sol)) {
        cout << "Solution Found:" << endl;
        print(sol);
    } else {
        cout << "Sorry, no solution found." << endl;
    }
}
