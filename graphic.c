#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw a circle at (200, 200) with radius 50
    circle(200, 200, 50);

    // Draw a rectangle with top-left (100, 100) and bottom-right (300, 250)
    rectangle(100, 100, 300, 250);

    // Hold the screen until a key is pressed
    getch();

    // Close graphics mode
    closegraph();
    return 0;
}

