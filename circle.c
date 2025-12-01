#include <stdio.h>
#include <graphics.h>
using namespace std;

// Function to plot all eight symmetric points
void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Mid-Point Circle Drawing Algorithm
void midPointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    drawCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int xc, yc, r;
    cout << "Enter center of circle (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius of circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    midPointCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}

