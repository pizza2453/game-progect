#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

void drawBoard(int width, int height, int x, int y, int cloneX, int cloneY, int targetX, int targetY) {
    system("cls");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (col == x && row == y) {
                cout << 'X';
            } else if (col == cloneX && row == cloneY) {
                cout << 'C';
            } else if (col == targetX && row == targetY) {
                cout << 'Y';
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
    int cloneX = x;
    int cloneY = y;
    
    deque<pair<int, int>> positionHistory;
    positionHistory.push_back({x, y});

    srand((unsigned)time(NULL));
    int targetX = rand() % width;
    int targetY = rand() % height;
    while (targetX == x && targetY == y) {
        targetX = rand() % width;
        targetY = rand() % height;
    }

    drawBoard(width, height, x, y, cloneX, cloneY, targetX, targetY);

    while (true) {
        int key = _getch();
        if (key == 'q' || key == 'Q') {
            break;
        }
        
        int newX = x;
        int newY = y;
        
        if (key == 'w' || key == 'W') {
            if (y > 0) newY--;
        } else if (key == 's' || key == 'S') {
            if (y < height - 1) newY++;
        } else if (key == 'a' || key == 'A') {
            if (x > 0) newX--;
        } else if (key == 'd' || key == 'D') {
            if (x < width - 1) newX++;
        }
        
        // Przesunąć klona na poprzednią pozycję gracza
        cloneX = x;
        cloneY = y;
        
        // Przesunąć gracza
        x = newX;
        y = newY;
        
        // Dodać nową pozycję do historii
        positionHistory.push_back({x, y});

        if (x == targetX && y == targetY) {
            do {
                targetX = rand() % width;
                targetY = rand() % height;
            } while (targetX == x && targetY == y);
        }

        drawBoard(width, height, x, y, cloneX, cloneY, targetX, targetY);
    }

    return 0;
}