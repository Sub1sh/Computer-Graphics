#include <GL/glut.h>
#include <stdio.h>
int choice = 0;
float tx = 0, ty = 0, tz = 0;
float angle = 0;
float sx = 1.0, sy = 1.0, sz = 1.0;
float shearXY = 0.0;
void drawCube() {
    glPushMatrix();
    glTranslatef(0.0, 0.0, -6.0);  
    switch (choice) {
        case 1:
            glTranslatef(tx, ty, tz);
            break;
        case 2:
            glRotatef(angle, 1.0, 1.0, 0.0);
            break;
        case 3:
            glScalef(sx, sy, sz);
            break;
        case 4:
            glScalef(1.0, -1.0, 1.0); 
            break;
        case 5: {
            GLfloat shearMatrix[16] = {
                1, shearXY, 0, 0,
                0,    1,    0, 0,
                0,    0,    1, 0,
                0,    0,    0, 1
            };
            glMultMatrixf(shearMatrix);
            break;
        }
        default:
            break;
    }
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1,  1);
    glVertex3f( 1, -1,  1);
    glVertex3f( 1,  1,  1);
    glVertex3f(-1,  1,  1);
    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1,  1, -1);
    glVertex3f( 1,  1, -1);
    glVertex3f( 1, -1, -1);
    glColor3f(0, 0, 1);
    glVertex3f(-1,  1, -1);
    glVertex3f(-1,  1,  1);
    glVertex3f( 1,  1,  1);
    glVertex3f( 1,  1, -1);
    glColor3f(1, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f( 1, -1, -1);
    glVertex3f( 1, -1,  1);
    glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1);
    glVertex3f( 1, -1, -1);
    glVertex3f( 1,  1, -1);
    glVertex3f( 1,  1,  1);
    glVertex3f( 1, -1,  1);
    glColor3f(1, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1,  1);
    glVertex3f(-1,  1,  1);
    glVertex3f(-1,  1, -1);
    glEnd();
    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    drawCube();
    glutSwapBuffers();
}
void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
void initGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 1, 1);
}
int main(int argc, char** argv) {
    printf("===== 3D Transformations on Cube =====\n");
    printf("1. Translation\n");
    printf("2. Rotation\n");
    printf("3. Scaling\n");
    printf("4. Reflection (Y-axis)\n");
    printf("5. Shearing (XY)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter translation (tx ty tz): ");
            scanf("%f %f %f", &tx, &ty, &tz);
            break;
        case 2:
            printf("Enter rotation angle in degrees: ");
            scanf("%f", &angle);
            break;
        case 3:
            printf("Enter scaling factors (sx sy sz): ");
            scanf("%f %f %f", &sx, &sy, &sz);
            break;
        case 5:
            printf("Enter shear factor (XY): ");
            scanf("%f", &shearXY);
            break;
        case 4:
            printf("Reflection across Y-axis will be applied.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 600);
    glutCreateWindow("3D Transformation on Cube");
    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}








