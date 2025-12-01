#include <GL/glut.h> // FreeGLUT

// Initialize OpenGL state
void initOpenGL() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer

    glBegin(GL_TRIANGLES);

    // Triangle 1 - Farther (White)
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex3f(-0.5f, -0.5f, -1.0f);
    glVertex3f( 0.5f, -0.5f, -1.0f);
    glVertex3f( 0.0f,  0.5f, -1.0f);

    // Triangle 2 - Closer (Yellow), overlaps triangle 1
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(-0.3f, -0.3f, -0.5f);
    glVertex3f( 0.7f, -0.3f, -0.5f);
    glVertex3f( 0.2f,  0.7f, -0.5f);

    glEnd();

    glutSwapBuffers(); // Swap front and back buffers
}

// Reshape callback
void reshape(int w, int h) {
    glViewport(0, 0, w, h); // Set viewport to window dimensions
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 0.1, 100.0); // Perspective view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0,   // Eye position
              0.0, 0.0, 0.0,   // Look-at point
              0.0, 1.0, 0.0);  // Up direction
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffering and depth
    glutInitWindowSize(800, 600);
    glutCreateWindow("Z-Buffer - Visible Surface Detection (FreeGLUT)");

    initOpenGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop(); // Enter main loop
    return 0;
}

