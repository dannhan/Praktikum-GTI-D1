#include <GL/glut.h>
#include <cmath>

void roket(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. Hidung Roket 
    glColor3f(0.9f, 0.1f, 0.1f); // Warna Merah
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.6f);   // Titik pusat/puncak
        glVertex2f(-0.15f, 0.3f); // Kiri bawah
        glVertex2f(0.0f, 0.25f);  // Tengah bawah (sedikit melengkung ke atas)
        glVertex2f(0.15f, 0.3f);  // Kanan bawah
    glEnd();

    // 2. Badan Roket
    // Sangat efisien untuk membuat tabung atau panel bersambung
    glColor3f(0.8f, 0.8f, 0.8f); // Warna Abu-abu terang
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.15f, 0.3f);  // Kiri atas
        glVertex2f(0.15f, 0.3f);   // Kanan atas
        glVertex2f(-0.15f, -0.3f); // Kiri tengah
        glVertex2f(0.15f, -0.3f);  // Kanan tengah
        glVertex2f(-0.2f, -0.4f);  // Kiri bawah (sedikit melebar)
        glVertex2f(0.2f, -0.4f);   // Kanan bawah (sedikit melebar)
    glEnd();

    // 3. Sirip Roket
    // Sempurna untuk bentuk segi empat independen
    glColor3f(0.9f, 0.1f, 0.1f); // Warna Merah
    glBegin(GL_QUADS);
        // Sirip Kiri
        glVertex2f(-0.15f, -0.1f);
        glVertex2f(-0.35f, -0.4f);
        glVertex2f(-0.35f, -0.5f);
        glVertex2f(-0.2f, -0.4f);
        // Sirip Kanan
        glVertex2f(0.15f, -0.1f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.35f, -0.5f);
        glVertex2f(0.35f, -0.4f);
    glEnd();

    // 4. Api
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.15f, -0.4f); // Kiri atas
        glVertex2f(-0.1f, -0.7f);  // Ujung api kiri
        glVertex2f(0.0f, -0.4f);   // Tengah atas
        glVertex2f(0.05f, -0.8f);  // Ujung api tengah (paling panjang)
        glVertex2f(0.15f, -0.4f);  // Kanan atas
    glEnd();

    // 5. Jendela Roket
    glColor3f(0.0f, 0.8f, 1.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
        float radius = 0.08f;
        for (int i = 0; i < 360; i += 10) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.0f + radius * cos(theta), 0.0f + radius * sin(theta));
        }
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Roket");

    glutDisplayFunc(roket);

    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);

    glutMainLoop();
    return 0;
}
