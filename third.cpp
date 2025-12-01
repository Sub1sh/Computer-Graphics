#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the triangle
    int x1 = 200, y1 = 100;
    int x2 = 100, y2 = 300;
    int x3 = 300, y3 = 300;

    // Draw triangle using lines
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch(); // Wait for key press
    closegraph(); // Close graphics mode
    return 0;
}

