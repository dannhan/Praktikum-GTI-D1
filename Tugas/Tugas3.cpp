#include <GL/glut.h>

void piramida(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    const int tinggi = 12;
    const float sisiDasar = 0.15f;
    const float jarak = 0.01f;

    float lebarAlas = tinggi * sisiDasar;

    for (int y = 0; y < tinggi; y++) {
        for (int x = 0; x < (tinggi - y); x++) {
            float r = 0.2f + (static_cast<float>(x) / tinggi);
            float g = 0.4f + (static_cast<float>(y) / tinggi);
            float b = 0.8f; 
            glColor3f(r, g, b);

            float xOffset = y * (sisiDasar / 2.0f);
            float blokX = (x * sisiDasar) + xOffset - (lebarAlas / 2.0f);
            float blokY = (y * sisiDasar) - (lebarAlas / 2.0f);

            glRectf(blokX + (jarak / 2.0f), 
                    blokY + (jarak / 2.0f), 
                    blokX + sisiDasar - (jarak / 2.0f), 
                    blokY + sisiDasar - (jarak / 2.0f));
        }
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Piramida");

    glutDisplayFunc(piramida);

    glClearColor(22.0f / 255.0f, 29.0f / 255.0f, 31.0f / 255.0f, 1.0f);

    glutMainLoop(); 
    return 0;
}
