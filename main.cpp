#include <iostream>
#include <conio.h>

using namespace std;

void drawBoard(int width, int height, int x, int y) {
    system("cls");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (col == x && row == y) {
                cout << 'X';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << "Use W A S D to move, Q to quit." << endl;
}

int main() {
    const int width = 20;
    const int height = 20;
    int x = width / 2;
    int y = height / 2;

    drawBoard(width, height, x, y);

    while (true) {
        int key = _getch();
        if (key == 'q' || key == 'Q') {
            break;
        }
        if (key == 'w' || key == 'W') {
            if (y > 0) y--;
        } else if (key == 's' || key == 'S') {
            if (y < height - 1) y++;
        } else if (key == 'a' || key == 'A') {
            if (x > 0) x--;
        } else if (key == 'd' || key == 'D') {
            if (x < width - 1) x++;
        }
        drawBoard(width, height, x, y);
    }

    return 0;
}