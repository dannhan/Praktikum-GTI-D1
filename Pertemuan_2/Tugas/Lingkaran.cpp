#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(200 / 255.0f, 41 / 255.0f, 28 /255.0f); 
    
    glBegin(GL_POLYGON);
    int points = 100;
    float radius = 0.5f;
    
    for (int i = 0; i < points; i++) {
        float angle = 2.0f * PI * i / points;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
    
  glFlush();
}

void reshape(int w, int h) {
  if (w == 0 || h == 0) return;

  glViewport(0, 0, w, h);

  float aspect = static_cast<float>(w) / static_cast<float>(h);
  float left = -1.0f, right = 1.0f, bottom = -1.0f, top = 1.0f;

  if (aspect > 1.0f) {
    left *= aspect;
    right *= aspect;
  } else {
    bottom /= aspect;
    top /= aspect;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(left, right, bottom, top, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0 / 255.0f,  106 / 255.0f, 78 / 255.0f, 1.0f); 
    glutMainLoop();
    return 0;
}
