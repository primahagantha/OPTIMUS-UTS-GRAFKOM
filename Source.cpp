#include <glut.h>
#include <math.h>

float X = 0.0f;
float Y = -0.3f;
bool isJumping = false;
float jumpSpeed = 0.005f;
float gravity = -0.000025f;
float verticalSpeed = 0.0f;

void drawSky() {
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3ub(176, 224, 230);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();
}

void drawBuilding(float xOffset) {
    glBegin(GL_QUADS);
    glColor3ub(82, 53, 53);
    glVertex2f(xOffset - 0.15f, 0.0f);
    glVertex2f(xOffset + 0.15f, 0.0f);
    glVertex2f(xOffset + 0.15f, 0.8f);
    glVertex2f(xOffset - 0.15f, 0.8f);
    glEnd();

    for (float y = 0.2f; y <= 0.5f; y += 0.15f) {
        glBegin(GL_QUADS);
        glColor3ub(176, 224, 230);
        glVertex2f(xOffset - 0.05f, y);
        glVertex2f(xOffset + 0.05f, y);
        glColor3ub(135, 206, 250);
        glVertex2f(xOffset + 0.05f, y + 0.1f);
        glVertex2f(xOffset - 0.05f, y + 0.1f);
        glEnd();
    }
}


void drawGrass() {
    glBegin(GL_QUADS);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();
}

void drawRoad() {
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    glColor3ub(255, 255, 255);
    for (float x = -0.8f; x < 1.0f; x += 0.4f) {
        glBegin(GL_QUADS);
        glVertex2f(x, -0.3f);
        glVertex2f(x + 0.2f, -0.3f);
        glVertex2f(x + 0.2f, -0.32f);
        glVertex2f(x, -0.32f);
        glEnd();
    }
}

void keyboard(unsigned char key, int xPos, int yPos) {
    switch (key) {
    case 'A':
    case 'a':
        X -= 0.1f;
        break;
    case 'D':
    case 'd':
        X += 0.1f;
        break;
    case ' ':
        if (!isJumping) {
            isJumping = true;
            verticalSpeed = jumpSpeed;
        }
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !isJumping) {
        isJumping = true;
        verticalSpeed = jumpSpeed;
    }
}

void updateJump() {
    if (isJumping) {
        Y += verticalSpeed;
        verticalSpeed += gravity;
        if (Y <= -0.3f) {
            Y = -0.3f;
            isJumping = false;
            verticalSpeed = 0.0f;
        }
    }
}

void drawCharacter() {
    glPushMatrix();
    glTranslatef(X, Y, 0.0f);

    // Kepala
    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0.4f);
    glVertex2f(-0.035f, 0.45f);
    glVertex2f(0.0f, 0.475f);
    glVertex2f(0.035f, 0.45f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.035f, 0.35f);
    glVertex2f(0.0f, 0.325f);
    glVertex2f(-0.035f, 0.35f);
    glEnd();

    // Mata
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(-0.025f, 0.425f);
    glVertex2f(0.025f, 0.425f);
    glEnd();

    // Idung
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.0f, 0.375f);
    glEnd();

    // Mulut
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.02f, 0.365f);
    glVertex2f(0.0f, 0.36f);
    glVertex2f(0.02f, 0.365f);
    glEnd();

    // Badan
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0.325f);
    glVertex2f(0.05f, 0.325f);
    glVertex2f(0.04f, 0.075f);
    glVertex2f(-0.04f, 0.075f);
    glEnd();

    // Tangan
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0.325f);
    glVertex2f(-0.09f, 0.325f);
    glVertex2f(-0.1f, 0.175f);
    glVertex2f(-0.05f, 0.175f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.05f, 0.325f);
    glVertex2f(0.09f, 0.325f);
    glVertex2f(0.1f, 0.175f);
    glVertex2f(0.05f, 0.175f);
    glEnd();

    // Telapak Tangan
    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0.175f);
    glVertex2f(-0.1f, 0.175f);
    glVertex2f(-0.1f, 0.125f);
    glVertex2f(-0.05f, 0.125f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.05f, 0.175f);
    glVertex2f(0.1f, 0.175f);
    glVertex2f(0.1f, 0.125f);
    glVertex2f(0.05f, 0.125f);
    glEnd();

    // Kaki
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.005f, 0.075f);
    glVertex2f(-0.005f, -0.025f);
    glVertex2f(-0.075f, -0.025f);
    glVertex2f(-0.04f, 0.075f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.005f, 0.075f);
    glVertex2f(0.005f, -0.025f);
    glVertex2f(0.075f, -0.025f);
    glVertex2f(0.04f, 0.075f);
    glEnd();

    // Sepatu
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.075f, -0.025f);
    glVertex2f(-0.005f, -0.025f);
    glVertex2f(-0.005f, -0.05f);
    glVertex2f(-0.085f, -0.05f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.005f, -0.025f);
    glVertex2f(0.075f, -0.025f);
    glVertex2f(0.085f, -0.05f);
    glVertex2f(0.005f, -0.05f);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawBuilding(-0.75f);
    drawBuilding(-0.25f);
    drawBuilding(0.25f);
    drawBuilding(0.75f);
    drawGrass();
    drawRoad();

    drawCharacter();

    updateJump();
    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Baldi Movement on Road");

    glClearColor(34 / 255.0, 139 / 255.0, 34 / 255.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}