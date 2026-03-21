#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.1415926535898

void lingkaran(float x, float y, float radius, int points, bool filled) {
    if (filled) glBegin(GL_POLYGON);
    else glBegin(GL_LINE_LOOP);
    
    for (int i = 0; i < points; i++) {
        float angle = 2.0f * PI * i / points;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void background() {
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.7f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glColor3f(1.0f, 0.9f, 0.4f);
    lingkaran(0.7f, 0.6f, 0.15f, 50, true);

    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.5f, 0.3f);
    glVertex2f(-1.2f, 0.0f);
    glVertex2f(-0.5f, 0.4f);
    glVertex2f(0.2f, 0.0f);
    glColor3f(0.3f, 0.6f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(1.2f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    glPushMatrix(); 
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for (float x = -1.0f; x < 1.0f; x += 0.4f) {
        glVertex2f(x, -0.5f);
        glVertex2f(x + 0.2f, -0.5f);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}


void mobil() {
    glPushMatrix();

    glColor3f(0.8f, 0.1f, 0.1f); 

    glRectf(-0.25f, -0.1f, 0.25f, 0.05f); 

    glBegin(GL_QUADS);
    glVertex2f(-0.15f, 0.05f);
    glVertex2f(0.10f, 0.05f);
    glVertex2f(0.05f, 0.15f);
    glVertex2f(-0.12f, 0.15f);
    glEnd();

    glColor3f(0.9f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.10f, 0.07f);
    glVertex2f(0.05f, 0.07f);
    glVertex2f(0.02f, 0.13f);
    glVertex2f(-0.08f, 0.13f);
    glEnd();
    
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.23f, 0.0f);
    glEnd();

    glPopMatrix();
}

void roda() {
    glPushMatrix(); 

    glColor3f(0.1f, 0.1f, 0.1f);
    lingkaran(0.0f, 0.0f, 0.08f, 30, true);

    glColor3f(0.7f, 0.7f, 0.7f);
    lingkaran(0.0f, 0.0f, 0.05f, 20, true);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.05f, 0.0f); glVertex2f(0.05f, 0.0f);
    glVertex2f(0.0f, -0.05f); glVertex2f(0.0f, 0.05f);
    glEnd();

    glPopMatrix(); 
}


void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    background();

    glPushMatrix();

    glTranslatef(0.0f, -0.2f, 0.0f);
    mobil();


    glPushMatrix();
    glTranslatef(-0.15f, -0.1f, 0.0f);
    roda();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, -0.1f, 0.0f);
    roda();
    glPopMatrix();


    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Mobil 2D Praktikum 3");

    glutDisplayFunc(RenderScene);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
