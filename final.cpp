#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib> // For rand()
#include <GL/glu.h> // For GLU functions
#include <time.h>
#include <string.h>

// Angle for rotating lines around the teleport circle
float angle = 0.0f;
float ufoX=-1.0;
float ufoSpeed=0.02;
float spiderX=-1.0;
float spiderSpeed=0.01;
float spiderTargetX=0;
float spiderStopped=false;
bool isAnimating = false;
bool timerRunning = false;
float wizardRotateX = 0.0f;
float wizardRotateY = 0.0f;
float wizardRotateZ= 0.0f;
float wizardAngle= 0.0f;
bool flashWhite = true;
bool lightningEnabled = false;
float lightningFlashDuration = 0.1f; // Flash duration in seconds
float lightningFlashCounter = 0.0f;
float spidermanTranslateX = 0.0f;
float spidermanTranslateY = 0.0f;
bool spidermanlineEnabled = false;
float textPosition = -7.5f; // Start off-screen to the right
const char* billboardText = "Spiderman 2";
float textWidth = 0.0f;
bool initialScroll = true;
GLfloat stars[200][2];


// Function to draw the character
void drawCharacter() {

    //WIZARD
    // Draw head (circle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.1;
        double y = sin(angle) * 0.1;
        glVertex2f(x - 0.3f, y - 0.3f);
    }
    glEnd();

    // Draw face expression (anxious)
    // Draw eyes (white circles)
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.02;
        double y = sin(angle) * 0.02;
        glVertex2f(x - 0.33f, y - 0.27f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.02;
        double y = sin(angle) * 0.02;
        glVertex2f(x - 0.27f, y - 0.27f);
    }
    glEnd();

    // Draw pupils (black circles)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.01;
        double y = sin(angle) * 0.01;
        glVertex2f(x - 0.33f, y - 0.27f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.01;
        double y = sin(angle) * 0.01;
        glVertex2f(x - 0.27f, y - 0.27f);
    }
    glEnd();

    // Draw mouth (anxious expression)
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.34f, -0.33f);
    glVertex2f(-0.33f, -0.35f);
    glVertex2f(-0.27f, -0.35f);
    glVertex2f(-0.26f, -0.33f);
    glEnd();

    // Draw neck (small rectangle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.32f, -0.4f);
    glVertex2f(-0.28f, -0.4f);
    glVertex2f(-0.28f, -0.45f);
    glVertex2f(-0.32f, -0.45f);
    glEnd();

    // Draw body (red shirt)
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.45f);
    glVertex2f(-0.2f, -0.45f);
    glVertex2f(-0.2f, -0.75f);
    glVertex2f(-0.4f, -0.75f);
    glEnd();

    // Draw left arm (rectangle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(-0.35f, -0.5f);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.4f, -0.7f);
    glEnd();

    // Draw right arm (rectangle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.15f, -0.65f);
    glEnd();

    // Draw left leg (green, thin)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.36f, -0.75f);
    glVertex2f(-0.34f, -0.75f);
    glVertex2f(-0.34f, -0.95f);
    glVertex2f(-0.36f, -0.95f);
    glEnd();

    // Draw right leg (green, thin)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.26f, -0.75f);
    glVertex2f(-0.24f, -0.75f);
    glVertex2f(-0.24f, -0.95f);
    glVertex2f(-0.26f, -0.95f);
    glEnd();

    //venom spuderman
    // Head
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.5);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, 0.5);
    glEnd();

    // Eyes (left)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.76, 0.4);
    glVertex2f(-0.76, 0.2);
    glVertex2f(-0.71, 0.2);
    glVertex2f(-0.71, 0.4);
    glEnd();

    // Eyes (right)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.69, 0.4);
    glVertex2f(-0.69, 0.2);
    glVertex2f(-0.64, 0.2);
    glVertex2f(-0.64, 0.4);
    glEnd();

    // Neck
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.75, 0.1);
    glVertex2f(-0.75, -0.4);
    glVertex2f(-0.65, -0.4);
    glVertex2f(-0.65, 0.1);
    glEnd();

    // Body
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.6, 0.0);
    glEnd();

    // Hand (left)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, 0.0);
    glVertex2f(-0.85, -0.3);
    glVertex2f(-0.8, -0.3);
    glVertex2f(-0.8, 0.0);
    glEnd();

    // Fist (left)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, -0.3);
    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.8, -0.35);
    glVertex2f(-0.8, -0.3);
    glEnd();

    // Hand line (left)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.8, -0.4);
    glEnd();

    // Hand (right)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55, 0.0);
    glVertex2f(-0.55, -0.3);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.6, 0.0);
    glEnd();

    // Fist (right)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55, -0.3);
    glVertex2f(-0.55, -0.35);
    glVertex2f(-0.6, -0.35);
    glVertex2f(-0.6, -0.3);
    glEnd();

    // Hand line (right)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, -0.4);
    glEnd();

    // Body (left white)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.75, -0.4);
    glVertex2f(-0.75, -0.2);
    glEnd();

    // Body (right white)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.65, -0.4);
    glVertex2f(-0.65, -0.2);
    glEnd();

    // Belt
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.6, -0.4);
    glEnd();

    // Leg
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.8, -0.8);
    glVertex2f(-0.6, -0.8);
    glVertex2f(-0.6, -0.4);
    glEnd();

    // Leg (line)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.8);
    glVertex2f(-0.7, -0.5);
    glEnd();

    // Spider logo
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(-0.7, -0.2);
    glEnd();

    // Spider logo-1
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.73, -0.1);
    glEnd();

    // Spider logo-2
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.67, -0.1);
    glEnd();

    // Spider logo-3
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.74, -0.24);
    glEnd();

    // Spider logo-4
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.66, -0.24);
    glEnd();

    // Spider logo-5
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.73, -0.3);
    glEnd();

    // Spider logo-6
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.67, -0.3);
    glEnd();

    // Spider logo-7
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.74, -0.17);
    glEnd();

    // Spider logo-8
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.66, -0.17);
    glEnd();


    //spiderman red
    // Head
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_QUADS);
    glVertex2f(0.1, 0.5);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.3, 0.5);
    glEnd();

    // Eyes (left)
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_QUADS);
    glVertex2f(0.14, 0.4);
    glVertex2f(0.14, 0.2);
    glVertex2f(0.19, 0.2);
    glVertex2f(0.19, 0.4);
    glEnd();

    // Eyes (right)
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_QUADS);
    glVertex2f(0.21, 0.4);
    glVertex2f(0.21, 0.2);
    glVertex2f(0.26, 0.2);
    glVertex2f(0.26, 0.4);
    glEnd();

    // Neck
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_QUADS);
    glVertex2f(0.15, 0.1);
    glVertex2f(0.15, -0.4);
    glVertex2f(0.25, -0.4);
    glVertex2f(0.25, 0.1);
    glEnd();

    // Body
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_QUADS);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.3, 0.0);
    glEnd();

    // Hand (left)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.05, 0.0);
    glVertex2f(0.05, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, 0.0);
    glEnd();

    // Fist (left)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.05, -0.3);
    glVertex2f(0.05, -0.35);
    glVertex2f(0.1, -0.35);
    glVertex2f(0.1, -0.3);
    glEnd();

    // Hand line (left)
    glColor3f(1.0, 1.0, 1.0); // White color
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, -0.4);
    glEnd();

    // Hand (right)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.35, 0.0);
    glVertex2f(0.35, -0.3);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.3, 0.0);
    glEnd();

    // Fist (right)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.35, -0.3);
    glVertex2f(0.35, -0.35);
    glVertex2f(0.3, -0.35);
    glVertex2f(0.3, -0.3);
    glEnd();

    // Hand line (right)
    glColor3f(1.0, 1.0, 1.0); // White color
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.3, -0.4);
    glEnd();

    // Body (left blue)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.15, -0.4);
    glVertex2f(0.15, -0.2);
    glEnd();

    // Body (right blue)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.25, -0.4);
    glVertex2f(0.25, -0.2);
    glEnd();

    // Belt
    glColor3f(1.0, 1.0, 1.0); // White color
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.3, -0.4);
    glEnd();

    // Leg
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.1, -0.8);
    glVertex2f(0.3, -0.8);
    glVertex2f(0.3, -0.4);
    glEnd();

    // Leg (line)
    glColor3f(1.0, 1.0, 1.0); // White color
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.8);
    glVertex2f(0.2, -0.5);
    glEnd();

    // Spider logo
    glColor3f(0.0, 0.0, 0.0); // Black color
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(0.2, -0.2);
    glEnd();

    // Spider logo-1
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.17, -0.1);
    glEnd();

    // Spider logo-2
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.23, -0.1);
    glEnd();

    // Spider logo-3
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.16, -0.24);
    glEnd();

    // Spider logo-4
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.24, -0.24);
    glEnd();

    // Spider logo-5
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.17, -0.3);
    glEnd();

    // Spider logo-6
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.23, -0.3);
    glEnd();

    // Spider logo-7
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.16, -0.17);
    glEnd();

    // Spider logo-8
    glBegin(GL_LINES);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.24, -0.17);
    glEnd();
}


// Function to render text
void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void scene1()
{


    glClearColor(0.0f, 0.1f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
//star
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd();

//land
    glColor3f(0.0,0.3,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glEnd();

//transformation=====================================================
    glPushMatrix();
    glTranslatef(ufoX,0.0,0.0);

    //ufo 1
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0,-0.7);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.2,0.6);
    glVertex2f(0,0.6);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0,-0.7);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.2,0.6);
    glVertex2f(0,0.6);
    glEnd();

    //ufo 1.1
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05,0.6);
    glVertex2f(0.25,0.6);
    glVertex2f(0.25,0.65);
    glVertex2f(-0.05,0.65);
    glEnd();

    //ufo 1.2
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1,0.65);
    glVertex2f(0.3,0.65);
    glVertex2f(0.3,0.7);
    glVertex2f(-0.1,0.7);
    glEnd();

    //ufo 1.3
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,0.7);
    glVertex2f(0.1,0.8);
    glVertex2f(0.2,0.7);
    glEnd();

    //ufo 1.4.1
    glColor3f(5.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05,0.7);
    glVertex2f(0.0,0.7);
    glVertex2f(0.0,0.65);
    glVertex2f(-0.05,0.65);
    glEnd();

    //ufo 1.4.2
    glColor3f(5.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.05,0.7);
    glVertex2f(0.1,0.7);
    glVertex2f(0.1,0.65);
    glVertex2f(0.05,0.65);
    glEnd();

    //ufo 1.4.3
    glColor3f(5.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.15,0.7);
    glVertex2f(0.2,0.7);
    glVertex2f(0.2,0.65);
    glVertex2f(0.15,0.65);
    glEnd();

    //ufo 1.4.4
    glColor3f(5.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.25,0.7);
    glVertex2f(0.3,0.7);
    glVertex2f(0.3,0.65);
    glVertex2f(0.25,0.65);
    glEnd();

    glPopMatrix();

//spider man 1----------------------------------------------------------------------------
    //head
    glPushMatrix();
    glTranslatef(spiderX,0.0,0.0);

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,0.5);
    glVertex2f(-0.8,0.1);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.6,0.5);
    glEnd();

    //noticed 1.1
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.55,0.5);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,0.45);
    glVertex2f(-0.55,0.45);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.55,0.5);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,0.45);
    glVertex2f(-0.55,0.45);
    glEnd();

    //noticed 1.2
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.55,0.55);
    glVertex2f(-0.5,0.55);
    glVertex2f(-0.5,0.75);
    glVertex2f(-0.55,0.75);
    glEnd();

    //eyes(left)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.76,0.4);
    glVertex2f(-0.76,0.2);
    glVertex2f(-0.71,0.2);
    glVertex2f(-0.71,0.4);
    glEnd();

    //eyes(right)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.69,0.4);
    glVertex2f(-0.69,0.2);
    glVertex2f(-0.64,0.2);
    glVertex2f(-0.64,0.4);
    glEnd();

    //neck
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.75,0.1);
    glVertex2f(-0.75,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.65,0.1);
    glEnd();

    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,0.0);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.6,0.0);
    glEnd();

    //hand(left)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,0.0);
    glVertex2f(-0.85,-0.3);
    glVertex2f(-0.8,-0.3);
    glVertex2f(-0.8,0.0);
    glEnd();

    //fist(left)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,-0.3);
    glVertex2f(-0.85,-0.35);
    glVertex2f(-0.8,-0.35);
    glVertex2f(-0.8,-0.3);
    glEnd();

    //hand line(left)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.8,-0.4);
    glEnd();

    //hand(right)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55,0.0);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.6,0.0);
    glEnd();

    //fist(left)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.55,-0.35);
    glVertex2f(-0.6,-0.35);
    glVertex2f(-0.6,-0.3);
    glEnd();

    //hand line(right)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //body(left blue)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.2);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.75,-0.4);
    glVertex2f(-0.75,-0.2);
    glEnd();

    //body(right blue)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,-0.2);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.65,-0.2);
    glEnd();

    //belt
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //leg
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.6,-0.8);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //leg(line)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.7,-0.8);
    glVertex2f(-0.7,-0.5);
    glEnd();

    //spider logo
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(-0.7,-0.2);
    glEnd();

    //spider logo-1
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.73,-0.1);
    glEnd();

    //spider logo-2
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.67,-0.1);
    glEnd();

    //spider logo-3
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.74,-0.24);
    glEnd();

    //spider logo-4
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.66,-0.24);
    glEnd();

    //spider logo-5
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.73,-0.3);
    glEnd();

    //spider logo-6
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.67,-0.3);
    glEnd();

    //spider logo-7
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.74,-0.17);
    glEnd();

    //spider logo-8
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.66,-0.17);
    glEnd();

    glPopMatrix();

//villains-------------------------------------------------------------------------------
    //head
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.8,0.5);
    glVertex2f(0.6,0.1);
    glVertex2f(1.0,0.1);
    glEnd();

    //eyes(left)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.7,0.4);
    glVertex2f(0.75,0.3);
    glVertex2f(0.8,0.4);
    glEnd();

    //eyes(right)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.8,0.4);
    glVertex2f(0.85,0.3);
    glVertex2f(0.9,0.4);
    glEnd();

    //mouth
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.7,0.2);
    glVertex2f(0.7,0.1);
    glVertex2f(0.8,0.2);
    glVertex2f(0.8,0.1);
    glVertex2f(0.9,0.2);
    glVertex2f(0.9,0.1);
    glEnd();

    //mouth(line)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(0.7,0.2);
    glVertex2f(0.7,0.1);
    glVertex2f(0.8,0.2);
    glVertex2f(0.8,0.1);
    glVertex2f(0.9,0.2);
    glVertex2f(0.9,0.1);
    glVertex2f(0.7,0.2);
    glVertex2f(0.9,0.2);
    glVertex2f(0.7,0.1);
    glVertex2f(0.9,0.1);
    glEnd();

    //neck
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
    glVertex2f(0.75,0.1);
    glVertex2f(0.75,0.0);
    glVertex2f(0.85,0.0);
    glVertex2f(0.85,0.1);
    glEnd();

    //body
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0.7,0.0);
    glVertex2f(0.7,-0.4);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.9,0.0);
    glEnd();

    //hand(left)
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0.7,0.0);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.6,-0.3);
    glVertex2f(0.6,-0.2);
    glEnd();

    //fist(left)
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
    glVertex2f(0.6,-0.28);
    glVertex2f(0.6,-0.22);
    glVertex2f(0.55,-0.22);
    glVertex2f(0.55,-0.28);
    glEnd();

    //hand(right)
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0.9,0.0);
    glVertex2f(0.9,-0.3);
    glVertex2f(0.95,-0.3);
    glVertex2f(0.95,0.0);
    glEnd();

    //fist(right)
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
    glVertex2f(0.95,-0.3);
    glVertex2f(0.95,-0.35);
    glVertex2f(0.9,-0.35);
    glVertex2f(0.9,-0.3);
    glEnd();

    //body(LINES)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.7,0.0);
    glVertex2f(0.7,-0.4);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.9,0.0);
    glVertex2f(0.7,-0.4);
    glVertex2f(0.9,-0.4);
    glEnd();

    //body decorate
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.7,0.0);
    glVertex2f(0.9,0.0);
    glVertex2f(0.8,-0.1);
    //-----
    glVertex2f(0.8,0.0);
    glVertex2f(0.7,0.0);
    glVertex2f(0.75,0.1);
    //-----
    glVertex2f(0.9,0.0);
    glVertex2f(0.8,0.0);
    glVertex2f(0.85,0.1);
    glEnd();

     //body decorate(LINES)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(0.7,0.0);
    glVertex2f(0.9,0.0);
    glVertex2f(0.8,-0.1);
    //-----
    glVertex2f(0.8,0.0);
    glVertex2f(0.7,0.0);
    glVertex2f(0.75,0.1);
    //-----
    glVertex2f(0.9,0.0);
    glVertex2f(0.8,0.0);
    glVertex2f(0.85,0.1);
    glEnd();

    //leg
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.7,-0.4);
    glVertex2f(0.7,-0.8);
    glVertex2f(0.9,-0.8);
    glVertex2f(0.9,-0.4);
    glEnd();

    //leg
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0.7,-0.4);
    glVertex2f(0.7,-0.8);
    glVertex2f(0.9,-0.8);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.8,-0.8);
    glEnd();

    //sword
    glColor3f(0.68f, 0.85f, 0.90f);
    glBegin(GL_POLYGON);
    //--------
    glVertex2f(0.55,-0.22);
    glVertex2f(0.55,0.5);
    glVertex2f(0.56,0.7);
    glVertex2f(0.56,-0.23);
    glEnd();

    //sword equipment
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.53,-0.20);
    glVertex2f(0.53,-0.16);
    glVertex2f(0.58,-0.20);
    glVertex2f(0.58,-0.16);
    glEnd();

    //sword equipment(LINES)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(0.53,-0.20);
    glVertex2f(0.53,-0.16);
    glVertex2f(0.58,-0.20);
    glVertex2f(0.58,-0.16);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void update(int value)
{
    ufoX+=ufoSpeed;

    if(ufoX>1.0 || ufoX<-1.0)
    {
        ufoSpeed=-ufoSpeed;
    }

       if (!spiderStopped)
        {
        spiderX += spiderSpeed;
            if (spiderX >= spiderTargetX)
            {
                spiderX = spiderTargetX;
                spiderStopped = true;
            }
        }

    glutPostRedisplay();

    glutTimerFunc(50,update,0);
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to dark blue
    glClearColor(0.0f, 0.1f, 0.4f, 1.0f);

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.33f, 0.42f, 0.18f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
// Draw text below the circle
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    renderBitmapString(0.4f, -0.2f, GLUT_BITMAP_HELVETICA_18,  "SPUDERMAN");
    renderBitmapString(0.4f, -0.3f, GLUT_BITMAP_HELVETICA_18, "  SAVE");
    renderBitmapString(0.4f, -0.4f, GLUT_BITMAP_HELVETICA_18, "MY HOME");




    drawCharacter();



}

//scene2

void drawCharacterscene2() {
    // Draw head (circle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.1;
        double y = sin(angle) * 0.1;
        glVertex2f(x - 0.2f, y - 0.1f);
    }
    glEnd();

    // Draw face expression (anxious)
    // Draw eyes (white circles)
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.02;
        double y = sin(angle) * 0.02;
        glVertex2f(x - 0.23f, y - 0.07f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.02;
        double y = sin(angle) * 0.02;
        glVertex2f(x - 0.17f, y - 0.07f);
    }
    glEnd();

    // Draw pupils (black circles)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.01;
        double y = sin(angle) * 0.01;
        glVertex2f(x - 0.23f, y - 0.07f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.01;
        double y = sin(angle) * 0.01;
        glVertex2f(x - 0.17f, y - 0.07f);
    }
    glEnd();

    // Draw mouth (anxious expression)
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.24f, -0.13f);
    glVertex2f(-0.23f, -0.15f);
    glVertex2f(-0.17f, -0.15f);
    glVertex2f(-0.16f, -0.13f);
    glEnd();

    // Draw neck (small rectangle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.22f, -0.2f);
    glVertex2f(-0.18f, -0.2f);
    glVertex2f(-0.18f, -0.25f);
    glVertex2f(-0.22f, -0.25f);
    glEnd();

    // Draw body (red shirt)
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.1f, -0.55f);
    glVertex2f(-0.3f, -0.55f);
    glEnd();

    // Draw left arm (rectangle) with skin color
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.25f, -0.5f);
    glVertex2f(-0.3f, -0.5f);
    glEnd();

    glPushMatrix();
    glRotatef(wizardAngle, wizardRotateX, wizardRotateY,wizardRotateZ);
    // Draw right arm (rectangle) with skin color, pointing to the teleport circle
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex2f(-0.16f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.1f, -0.45f);
    glVertex2f(-0.06f, -0.45f);
    glEnd();
    glPopMatrix();
    // Draw left leg (green, thin)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.26f, -0.55f);
    glVertex2f(-0.24f, -0.55f);
    glVertex2f(-0.24f, -0.75f);
    glVertex2f(-0.26f, -0.75f);
    glEnd();

    // Draw right leg (green, thin)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.16f, -0.55f);
    glVertex2f(-0.14f, -0.55f);
    glVertex2f(-0.14f, -0.75f);
    glVertex2f(-0.16f, -0.75f);
    glEnd();
}

// Function to draw the teleport circle
void drawTeleportCircle() {

    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glLineWidth(5.0f); // Thicker border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.2; // Smaller horizontal radius
        double y = sin(angle) * 0.3; // Larger vertical radius
        glVertex2f(x+0.5f, y-0.5f);
    }
    glEnd();

    // Draw black circle inside, covering the whole area
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.2;
        double y = sin(angle) * 0.3;
        glVertex2f(x+0.5f, y-0.5f);
    }
    glEnd();
}

// Function to draw rotating lines around the teleport circle
void drawRotatingLines() {

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the lines
    glLineWidth(2.0f);

    int numLines = 12;
    float radius = 0.3f;

    glBegin(GL_LINES);
    for (int i = 0; i < numLines; ++i) {
        float currentAngle = angle + i * 2 * 3.14159265 / numLines;
        float x1 = cos(currentAngle) * radius+0.5f;
        float y1 = sin(currentAngle) * radius-0.5f;
        float x2 = cos(currentAngle) * (radius + 0.1f)+0.5f;
        float y2 = sin(currentAngle) * (radius + 0.1f)-0.5f;
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawlightning()
{
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.4,0.5);
    glVertex2f(0.3,0.1);
    glVertex2f(0.4,0.1);
    glVertex2f(0.4,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.375,0.2);
    glVertex2f(0.4,0.5);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.0, -0.1);
    glVertex2f(0.1, 0.2);
    glVertex2f(-0.025, 0.2);
    glVertex2f(0.0, 0.5);
    glEnd();

}
// Timer function to update the rotation angle
void timer(int value) {
    angle += 0.02f; // Update the angle
    if (angle > 2 * 3.14159265) {
        angle -= 2 * 3.14159265; // Reset the angle if it goes beyond 360 degrees
    }

    if (lightningFlashCounter > 0.0f) {
        lightningFlashCounter = 0.0; // Decrease the flash counter
        if (lightningFlashCounter <= 0.0f) {
            lightningEnabled = false; // Disable lightning when the flash duration is over
        }

    if(wizardAngle>=0.0f)
    {
        wizardAngle-=1.0f;
        if(wizardAngle<=0)
        {
            wizardAngle+=5.0f;
        }
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timer, 0); // Call the timer function again after 16 milliseconds
}
}



void drawSquare(float centerX, float centerY, float size) {
    float halfSize = size / 2.0f;
    glBegin(GL_QUADS);
    glVertex2f(centerX - halfSize, centerY - halfSize);
    glVertex2f(centerX + halfSize, centerY - halfSize);
    glVertex2f(centerX + halfSize, centerY + halfSize);
    glVertex2f(centerX - halfSize, centerY + halfSize);
    glEnd();
}

void building()
{

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.5f, 0.2f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.5f, 0.2f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.75f,0.5f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.75f,0.5f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();


    // Draw building
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.5f, -0.7f);
    glVertex2f(-0.5f, 0.2f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(-0.5f, -0.7f);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(-0.4f, 0.3f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.95f, 0.1f);
    glVertex2f(-0.95f, -0.6f);
    glVertex2f(-0.55f, -0.6f);
    glVertex2f(-0.55f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.75f, 0.1f);
    glVertex2f(-0.75f, -0.6f);

    glVertex2f(-0.95f, -0.25f);
    glVertex2f(-0.55f, -0.25f);
    glEnd();

    if (flashWhite) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color
    } else {
        glColor3f(1.0f, 0.627f, 0.478f); // Light orange color
    }
    // Draw squares inside the building
    drawSquare(-0.85f, 0.0f, 0.1f);
    drawSquare(-0.65f, 0.0f, 0.1f);
    drawSquare(-0.85f, -0.4f, 0.1f);
    drawSquare(-0.65f, -0.4f, 0.1f);
    flashWhite = !flashWhite;
    glEnd();


}
void drawcloud()
{
    float radius;
//cloud 1
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(0.3f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(0.4f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(0.5f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();

//cloud 2
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(-0.2f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(-0.1f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        radius=i*3.142/18   ;
        glVertex2f(0.0f+0.1*cos(radius),0.7f+0.1*sin(radius));
    }
    glEnd();
    glFlush();
}

void backgroundscene2(){

    glClearColor(0.0f, 0.1f, 0.4f, 1.0f);




    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to dark blue
    glClearColor(0.0f, 0.1f, 0.4f, 1.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    // Draw stars
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd();

    // Draw land
    glColor3f(0.33f, 0.42f, 0.18f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
    building();

    if (lightningEnabled) {
        drawlightning();
    }

    // Draw the character
    drawCharacterscene2();

    // Draw the teleport circle
    drawTeleportCircle();

    // Draw rotating lines around the teleport circle
    drawRotatingLines();


    drawcloud();
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // White color for text
    renderBitmapString(-0.3f, 0.1f, GLUT_BITMAP_HELVETICA_18, "I need to help Spuderman");

    glFlush();
}

//scene3

void drawTeleportCircle3() {
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glLineWidth(5.0f); // Thicker border
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.4; // Increased horizontal radius
        double y = sin(angle) * 0.7; // Increased vertical radius
        glVertex2f(x + 0.5f, y - 0.1f); // Adjusted y-coordinate to move it higher
    }
    glEnd();

    // Draw black circle inside, covering the whole area
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159265 * i / 300;
        double x = cos(angle) * 0.4;
        double y = sin(angle) * 0.7;
        glVertex2f(x + 0.5f, y - 0.1f);
    }
    glEnd();
}


// Function to draw rotating lines around the teleport circle
void drawRotatingLines3() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the lines
    glLineWidth(2.0f);

    int numLines = 12;
    float radius = 0.6f; // Adjusted to rotate outside the teleport circle

    glBegin(GL_LINES);
    for (int i = 0; i < numLines; ++i) {
        float currentAngle = angle + i * 2 * 3.14159265 / numLines;
        float x1 = cos(currentAngle) * radius + 0.5f;
        float y1 = sin(currentAngle) * radius - 0.1f; // Adjusted y-coordinate to move it higher
        float x2 = cos(currentAngle) * (radius + 0.1f) + 0.5f;
        float y2 = sin(currentAngle) * (radius + 0.1f) - 0.1f; // Adjusted y-coordinate to move it higher
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawspidermanline()
{

    glPushMatrix();
    glTranslatef(spidermanTranslateX, spidermanTranslateY, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.55, -0.19);
    glVertex2f(0.0f,1.0f);
    glEnd();
    glPopMatrix();

}

void drawVenomSpiderMan() {

glPushMatrix();
// Apply translation based on keyboard input
glTranslatef(spidermanTranslateX, spidermanTranslateY, 0.0f);
 // Head
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.5);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, 0.5);
    glEnd();

    // Eyes (left)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.76, 0.4);
    glVertex2f(-0.76, 0.2);
    glVertex2f(-0.71, 0.2);
    glVertex2f(-0.71, 0.4);
    glEnd();

    // Eyes (right)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.69, 0.4);
    glVertex2f(-0.69, 0.2);
    glVertex2f(-0.64, 0.2);
    glVertex2f(-0.64, 0.4);
    glEnd();

    // Neck
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.75, 0.1);
    glVertex2f(-0.75, -0.29);
    glVertex2f(-0.65, -0.29);
    glVertex2f(-0.65, 0.1);
    glEnd();

    // Body
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.8, -0.29);
    glVertex2f(-0.6, -0.29);
    glVertex2f(-0.6, 0.0);
    glEnd();

    // Hand (left)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, 0.0);
    glVertex2f(-0.85, -0.19);
    glVertex2f(-0.8, -0.19);
    glVertex2f(-0.8, 0.0);
    glEnd();

    // Fist (left)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, -0.19);
    glVertex2f(-0.85, -0.24);
    glVertex2f(-0.8, -0.24);
    glVertex2f(-0.8, -0.19);
    glEnd();

    // Hand line (left)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.8, -0.29);
    glEnd();

    // Hand (right)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55, 0.0);
    glVertex2f(-0.55, -0.19);
    glVertex2f(-0.6, -0.19);
    glVertex2f(-0.6, 0.0);
    glEnd();

    // Fist (right)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.55, -0.19);
    glVertex2f(-0.55, -0.24);
    glVertex2f(-0.6, -0.24);
    glVertex2f(-0.6, -0.19);
    glEnd();

    // Hand line (right)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, -0.29);
    glEnd();

    // Body (left white)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.8, -0.29);
    glVertex2f(-0.75, -0.29);
    glVertex2f(-0.75, -0.2);
    glEnd();

    // Body (right white)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.6, -0.29);
    glVertex2f(-0.65, -0.29);
    glVertex2f(-0.65, -0.2);
    glEnd();

    // Belt
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.29);
    glVertex2f(-0.6, -0.29);
    glEnd();

    // Leg
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, -0.29);
    glVertex2f(-0.8, -0.69);
    glVertex2f(-0.6, -0.69);
    glVertex2f(-0.6, -0.29);
    glEnd();

    // Leg (line)
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.69);
    glVertex2f(-0.7, -0.39);
    glEnd();

    // Spider logo
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(-0.7, -0.2);
    glEnd();

    // Spider logo-1
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.73, -0.1);
    glEnd();

    // Spider logo-2
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.67, -0.1);
    glEnd();

    // Spider logo-3
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.74, -0.23);
    glEnd();

    // Spider logo-4
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.66, -0.23);
    glEnd();

    // Spider logo-5
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.73, -0.29);
    glEnd();

    // Spider logo-6
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.67, -0.29);
    glEnd();

    // Spider logo-7
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.74, -0.16);
    glEnd();

    // Spider logo-8
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.66, -0.16);
    glEnd();
     glPopMatrix();
}

void text3()
{
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // White color for text
    renderBitmapString(-0.6f, 0.1f, GLUT_BITMAP_HELVETICA_18, "Someone calling me......");
}

void drawBackgroundscene3() {
    // Set background color to purple
    glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw stars
    glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd();

    // Draw land with yellow-orange mix
    glColor3f(1.0f, 0.65f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glEnd();

    // Draw blue moon
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = 2 * 3.14159265 * i / 360;
        double x = cos(angle) * 0.2;
        double y = sin(angle) * 0.2;
        glVertex2f(x - 0.6f, y + 0.8f);
    }
    glEnd();

     glLoadIdentity();

    drawVenomSpiderMan();

    drawTeleportCircle3();


    drawspidermanline();


    // Draw rotating lines around the teleport circle
    drawRotatingLines3();

    text3();

}

//scene4

void backgroundscene4()
{
    glClearColor(0.0f, 0.1f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
//star
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd();

//land
    glColor3f(0.33f, 0.42f, 0.18f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glEnd();


//spider man 1----------------------------------------------------------------------------
    //head
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,0.5);
    glVertex2f(-0.8,0.1);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.6,0.5);
    glEnd();

    //eyes(left)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.76,0.4);
    glVertex2f(-0.76,0.2);
    glVertex2f(-0.71,0.2);
    glVertex2f(-0.71,0.4);
    glEnd();

    //eyes(right)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.69,0.4);
    glVertex2f(-0.69,0.2);
    glVertex2f(-0.64,0.2);
    glVertex2f(-0.64,0.4);
    glEnd();

    //neck
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.75,0.1);
    glVertex2f(-0.75,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.65,0.1);
    glEnd();

    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,0.0);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.6,0.0);
    glEnd();

    //hand(left)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,0.0);
    glVertex2f(-0.85,-0.3);
    glVertex2f(-0.8,-0.3);
    glVertex2f(-0.8,0.0);
    glEnd();

    //fist(left)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,-0.3);
    glVertex2f(-0.85,-0.35);
    glVertex2f(-0.8,-0.35);
    glVertex2f(-0.8,-0.3);
    glEnd();

    //hand line(left)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.8,-0.4);
    glEnd();

//hand(right)
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(-0.7, 0.0);
glVertex2f(-0.7, -0.08);
glVertex2f(-0.4, -0.08);
glVertex2f(-0.4, 0.0);
glEnd();

//fist(right)
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-0.38, -0.0);
glVertex2f(-0.38, -0.078);
glVertex2f(-0.4, -0.078);
glVertex2f(-0.4, -0.0);
glEnd();

//finger (right)
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-0.38, -0.0);
glVertex2f(-0.38, -0.025);
glVertex2f(-0.36, -0.025);
glVertex2f(-0.36, -0.0);
glEnd();

    //hand line(right)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //body(left blue)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.2);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.75,-0.4);
    glVertex2f(-0.75,-0.2);
    glEnd();

    //body(right blue)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,-0.2);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.65,-0.2);
    glEnd();

    //belt
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //leg
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.6,-0.8);
    glVertex2f(-0.6,-0.4);
    glEnd();

    //leg(line)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.7,-0.8);
    glVertex2f(-0.7,-0.5);
    glEnd();

    //spider logo
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(-0.7,-0.2);
    glEnd();

    //spider logo-1
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.73,-0.1);
    glEnd();

    //spider logo-2
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.67,-0.1);
    glEnd();

    //spider logo-3
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.74,-0.24);
    glEnd();

    //spider logo-4
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.66,-0.24);
    glEnd();

    //spider logo-5
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.73,-0.3);
    glEnd();

    //spider logo-6
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.67,-0.3);
    glEnd();

    //spider logo-7
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.74,-0.17);
    glEnd();

    //spider logo-8
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.66,-0.17);
    glEnd();

//Spiderman 2---------------------------------------------------------------------------------------------
// head
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(0.0, 0.5); // changed from -0.8 to 0.0
glVertex2f(0.0, 0.1);
glVertex2f(0.2, 0.1);
glVertex2f(0.2, 0.5);
glEnd();

// eyes(left)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.04, 0.4); // changed from -0.76 to 0.04
glVertex2f(0.04, 0.2);
glVertex2f(0.09, 0.2);
glVertex2f(0.09, 0.4);
glEnd();

// eyes(right)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.11, 0.4); // changed from -0.69 to 0.11
glVertex2f(0.11, 0.2);
glVertex2f(0.16, 0.2);
glVertex2f(0.16, 0.4);
glEnd();

// neck
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(0.05, 0.1); // changed from -0.75 to 0.05
glVertex2f(0.05, -0.4);
glVertex2f(0.15, -0.4);
glVertex2f(0.15, 0.1);
glEnd();

// body
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(0.0, 0.0); // changed from -0.8 to 0.0
glVertex2f(0.0, -0.4);
glVertex2f(0.2, -0.4);
glVertex2f(0.2, 0.0);
glEnd();

// hand(left)
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(0.2, -0.08); // swapped and negated
glVertex2f(-0.2, -0.08);
glVertex2f(-0.2, 0.0);
glVertex2f(0.2, 0.0);
glEnd();

// fist(left)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-0.2, 0.0); // adjust x-coordinate to align with hand
glVertex2f(-0.22, 0.0); // adjust x-coordinate to align with hand
glVertex2f(-0.22, -0.08);
glVertex2f(-0.2, -0.08);
glEnd();

//finger(left)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-0.22, 0.0);
glVertex2f(-0.22, -0.025);
glVertex2f(-0.25, -0.025);
glVertex2f(-0.25, 0.0);
glEnd();


// hand line(left)
glColor3f(1.0, 1.0, 1.0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(0.0, -0.1);
glVertex2f(0.0, -0.4);
glEnd();

// hand(right)
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(0.25, 0.0); // changed from -0.55 to 0.25
glVertex2f(0.25, -0.3);
glVertex2f(0.3, -0.3);
glVertex2f(0.3, 0.0);
glEnd();

// fist(right)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.25, -0.3); // changed from -0.55 to 0.25
glVertex2f(0.25, -0.35);
glVertex2f(0.3, -0.35);
glVertex2f(0.3, -0.3);
glEnd();

// hand line(right)
glColor3f(1.0, 1.0, 1.0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(0.3, -0.1);
glVertex2f(0.3, -0.4);
glEnd();

// body(left white)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.0, -0.2); // changed from -0.8 to 0.0
glVertex2f(0.0, -0.4);
glVertex2f(0.05, -0.4);
glVertex2f(0.05, -0.2);
glEnd();

// body(right white)
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.2, -0.2); // changed from -0.6 to 0.2
glVertex2f(0.2, -0.4);
glVertex2f(0.15, -0.4);
glVertex2f(0.15, -0.2);
glEnd();

// belt
glColor3f(1.0, 1.0, 1.0);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2f(0.2, -0.4); // changed from -0.8 to 0.2
glVertex2f(0.0, -0.4);
glEnd();

// leg
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0, -0.4);
glVertex2f(0.0, -0.8);
glVertex2f(0.20, -0.8); // reverted from 0.25 to 0.15
glVertex2f(0.20, -0.4); // reverted from 0.25 to 0.15
glEnd();

// leg(line)
glColor3f(1.0, 1.0, 1.0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(0.1, -0.8);
glVertex2f(0.1, -0.5);
glEnd();

// spider logo
glColor3f(1.0, 1.0, 1.0);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glEnd();

// spider logo-1

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.13, -0.1);
glEnd();

// spider logo-2

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.07, -0.1);
glEnd();

// spider logo-3

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.14, -0.24);
glEnd();

// spider logo-4

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.06, -0.24);
glEnd();

// spider logo-5

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.13, -0.3);
glEnd();

// spider logo-6

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.07, -0.3);
glEnd();

// spider logo-7

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.14, -0.17);
glEnd();

// spider logo-8

glBegin(GL_LINES);

glVertex2f(0.1, -0.2); // changed from -0.7 to 0.1
glVertex2f(0.06, -0.17);
glEnd();

    glFlush();

    drawTeleportCircle3();
    drawRotatingLines3();
}

//scene 5

void init() {
    glClearColor(0.1, 0.1, 0.2, 1.0); // Set background color to black
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -15.0, 15.0, -1.0, 1.0);

    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);

    // Generate star positions
    for (int i = 0; i < 200; ++i) {
        stars[i][0] = (static_cast<float>(rand()) / RAND_MAX) * 40.0f - 5.0f;
        stars[i][1] = (static_cast<float>(rand()) / RAND_MAX) * 30.0f + 3.0f;
    }
}


// Draw a single scaffolding level
void drawScaffoldingLevel() {
    glPushMatrix();
    glTranslatef(-8, -10, 0);
    glScalef(1, 1, 0);

    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(6.0f);
    float spacingX = 2.0f;
    float spacingY = 2.0f;
    for (float y = -5.0f; y <= 8.0f; y += spacingY) {
        for (float x = -16.0f; x <= 10.0f; x += spacingX) {
            glBegin(GL_LINES);
            // Vertical beams
            glVertex2f(x, y);
            glVertex2f(x, y + spacingY);
            // Horizontal beams
            glVertex2f(x, y);
            glVertex2f(x + spacingX, y);
            glEnd();
        }
    }
    glPopMatrix();
}

void villain(){
    glPushMatrix();
    glTranslatef(11, -2.3, 0);
    glScalef(6, 6, 0);
    //head
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.8,0.5); glVertex2f(0.6,0.1); glVertex2f(1.0,0.1);
    glEnd();

    //eyes(left)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.7,0.4); glVertex2f(0.75,0.3); glVertex2f(0.8,0.4);
    glEnd();

    //eyes(right)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.8,0.4); glVertex2f(0.85,0.3); glVertex2f(0.9,0.4);
    glEnd();

    //mouth
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.7,0.2); glVertex2f(0.7,0.1); glVertex2f(0.8,0.2); glVertex2f(0.8,0.1);
        glVertex2f(0.9,0.2); glVertex2f(0.9,0.1);
    glEnd();

    //mouth(line)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(0.7,0.2); glVertex2f(0.7,0.1); glVertex2f(0.8,0.2); glVertex2f(0.9,0.1);
    glEnd();

    //neck
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
        glVertex2f(0.75,0.1); glVertex2f(0.75,0.0); glVertex2f(0.85,0.0); glVertex2f(0.85,0.1);
    glEnd();

    //body
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
        glVertex2f(0.7,0.0); glVertex2f(0.7,-0.4); glVertex2f(0.9,-0.4); glVertex2f(0.9,0.0);
    glEnd();

    //hand(left)
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
        glVertex2f(0.7,0.0); glVertex2f(0.7,-0.1); glVertex2f(0.6,-0.3); glVertex2f(0.6,-0.2);
    glEnd();

    //fist(left)
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
        glVertex2f(0.6,-0.28); glVertex2f(0.6,-0.22); glVertex2f(0.55,-0.22); glVertex2f(0.55,-0.28);
    glEnd();

    //hand(right)
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
        glVertex2f(0.9,0.0); glVertex2f(0.9,-0.3); glVertex2f(0.95,-0.3); glVertex2f(0.95,0.0);
    glEnd();

    //fist(right)
    glColor3f(0.96f, 0.96f, 0.86f);
    glBegin(GL_POLYGON);
        glVertex2f(0.95,-0.3); glVertex2f(0.95,-0.35); glVertex2f(0.9,-0.35); glVertex2f(0.9,-0.3);
    glEnd();

    //body(LINES)
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7,0.0); glVertex2f(0.7,-0.4); glVertex2f(0.9,-0.4); glVertex2f(0.9,0.0);
        glVertex2f(0.7,-0.4); glVertex2f(0.9,-0.4);
    glEnd();

    //body decorate
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.7,0.0); glVertex2f(0.9,0.0); glVertex2f(0.8,-0.1);
    //-----
        glVertex2f(0.8,0.0);glVertex2f(0.7,0.0); glVertex2f(0.75,0.1);
    //-----
        glVertex2f(0.9,0.0); glVertex2f(0.8,0.0); glVertex2f(0.85,0.1);
    glEnd();

     //body decorate(LINES)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(0.7,0.0);glVertex2f(0.9,0.0); glVertex2f(0.8,-0.1);
    //-----
        glVertex2f(0.8,0.0); glVertex2f(0.7,0.0); glVertex2f(0.75,0.1);
    //-----
        glVertex2f(0.9,0.0); glVertex2f(0.8,0.0); glVertex2f(0.85,0.1);
    glEnd();

    //leg
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.7,-0.4); glVertex2f(0.7,-0.8); glVertex2f(0.9,-0.8); glVertex2f(0.9,-0.4);
    glEnd();

    //leg
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7,-0.4); glVertex2f(0.7,-0.8); glVertex2f(0.9,-0.8); glVertex2f(0.9,-0.4);
        glVertex2f(0.8,-0.5); glVertex2f(0.8,-0.8);
    glEnd();

    //sword
    glColor3f(0.68f, 0.85f, 0.90f);
    glBegin(GL_POLYGON);
    //--------
        glVertex2f(0.55,-0.22); glVertex2f(0.55,0.5); glVertex2f(0.56,0.7); glVertex2f(0.56,-0.23);
    glEnd();

    //sword equipment
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.53,-0.20);  glVertex2f(0.53,-0.16); glVertex2f(0.58,-0.20); glVertex2f(0.58,-0.16);
    glEnd();

    //sword equipment(LINES)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glLineWidth(2);
        glVertex2f(0.53,-0.20); glVertex2f(0.53,-0.16);glVertex2f(0.58,-0.20);glVertex2f(0.58,-0.16);
    glEnd();

    glPopMatrix();
}

void electro(){
    glPushMatrix();
    glTranslatef(6, 4, 0);
    glScalef(1.5, 1.5, 0);

    // Electro's head
    glColor3f(1.0f, 1.0f, 0.0f);
    float headRadius = 0.3f;
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(360);
            float x = headRadius * cosf(theta);
            float y = headRadius * sinf(theta);
            glVertex2f(x, y);
        }
    glEnd();

    // Draw the body of Electro
    glScalef(2.0f, 2.0f, 2.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Set color to yellow
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
    // Body
        glVertex2f(0.1, -0.1); glVertex2f(0.25, -0.05);  glVertex2f(0.7, -0.15); glVertex2f(0.8, -0.15);
        glVertex2f(0.9, -0.2); glVertex2f(0.8, -0.25); glVertex2f(0.7, -0.2); glVertex2f(0.3, -0.2);
    // upper leg
        glVertex2f(0.5, -0.4); glVertex2f(0.85, -0.6); glVertex2f(1.3, -0.65); glVertex2f(1.3, -0.8);
        glVertex2f(1.2, -0.7); glVertex2f(0.8, -0.67); glVertex2f(0.5, -0.55);
    //lower leg
        glVertex2f(0.6, -0.7); glVertex2f(1.1, -0.9); glVertex2f(1, -1); glVertex2f(0.95, -0.9);
        glVertex2f(0.55, -0.8); glVertex2f(0.35, -0.6); glVertex2f(0, -0.3); glVertex2f(0, -0.5);
        glVertex2f(-0.1, -0.5); glVertex2f(-0.1, -0.2);
    glEnd();

    // Electro's energy source on the chest
    glColor3f(1, 1, 0);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(6.6, 3.1, 0.0f);
    float energySourceRadius = 0.3f;
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(360);
            float x = energySourceRadius * cosf(theta);
            float y = energySourceRadius * sinf(theta);
            glVertex2f(x, y);
        }
    glEnd();
    glPopMatrix();

    // Lightning effects around Electro
    glTranslatef(0.05, 0, 0);
    glScalef(0.7, 0.7, 0);
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0.2, -0.2); glVertex2f(0.18, 0.2); glVertex2f(0.25, 0.1); glVertex2f(0.28, 0.6);
        glVertex2f(0.35, 0.3); glVertex2f(0.5, 1.5); glVertex2f(0.25, -0.3);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0.2, -0.2); glVertex2f(0.05, -2); glVertex2f(0.15, -2.1); glVertex2f(0.25, -0.1);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.15, -1.8); glVertex2f(-0.2, -1.5); glVertex2f(-0.1, -1.9); glVertex2f(0.15, -2.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, -1.5); glVertex2f(-0.45, -3.5); glVertex2f(0, -1.9);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.75, -0.25); glVertex2f(0.75, -0.15); glVertex2f(2.1, -0.5); glVertex2f(2, -0.6);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(2, -0.6); glVertex2f(1.7, -0.5); glVertex2f(1.55, -0.7); glVertex2f(1.9, -0.7);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(1.55, -0.7); glVertex2f(1.9, -0.7); glVertex2f(3, -1);
    glEnd();

    glPopMatrix(); // Restore the previous state of transformations
}

void theLizard() {
    glPushMatrix();
    glTranslatef(7, -2.3, 0); // Adjust position as needed
    glScalef(1.5, 1.5, 0); // Scale the entire figure

    // Body (Green color)
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);

    glEnd();

    // Head
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.2, 0.1); // Center of the head
        glVertex2f(-0.35, -0.2); glVertex2f(-0.25, -0.3);// jaw
        glVertex2f(0.9, -0.2); glVertex2f(1.15, 0); glVertex2f(1.2, 0.3); glVertex2f(1.15, 0.5);
        glVertex2f(1.1, 0.65); glVertex2f(0.8, 0.8); glVertex2f(0.5, 0.8); glVertex2f(0.2, 0.7);
        glVertex2f(0.2, 0.4); //mouth
        glVertex2f(-0.4, 0.3); glVertex2f(-0.45, 0.2); glVertex2f(-0.3, 0.1);
    glEnd();

    // Eye
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.7, 0.7); glVertex2f(0.4, 0.6); glVertex2f(0.5, 0.4);
    glEnd();

    // Tongue
    glColor3f(0.8f, 0.2f, 0.2f);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.2, 0.1); glVertex2f(-0.5, -0.1); glVertex2f(-0.6, -0.05);
    glEnd();

    // Body
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.9, -0.2); glVertex2f(1.2, -0.4); glVertex2f(1.4, -0.6); glVertex2f(1.6, -0.8);
        glVertex2f(1.9, -1.3); glVertex2f(2, -1.9); glVertex2f(1.8, -2.1); glVertex2f(1.4, -2.2);
        glVertex2f(1, -2.1); glVertex2f(0.5, -1.5); glVertex2f(0.3, -0.9); glVertex2f(0.4, -0.24);
    glEnd();

    // front Leg
    glColor3f(0.5, 0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        //glVertex2f(1.3, -1.9);
        glVertex2f(1.1, -2.1); glVertex2f(1, -2.1); glVertex2f(1.5, -2.1); glVertex2f(1.7, -2);
        glVertex2f(1.7, -1.8); glVertex2f(1.5, -1.7); glVertex2f(0.7, -1.8); glVertex2f(0.6, -1.9);
        glVertex2f(0.6, -2.1); glVertex2f(0.8, -3); glVertex2f(1.1, -3);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.8, -3); glVertex2f(1.1, -3); glVertex2f(1.1, -3.2); glVertex2f(0.6, -3.2);
    glEnd();

    // leg behind
    glBegin(GL_QUADS);
        glVertex2f(1.8, -2.1); glVertex2f(1.4, -2.2); glVertex2f(2, -3); glVertex2f(2.2, -3);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(2, -3); glVertex2f(2.2, -3); glVertex2f(2.3, -3.2); glVertex2f(1.8, -3.2);
    glEnd();

    // front arm
    glBegin(GL_POLYGON);
        glVertex2f(1.1, -0.7); glVertex2f(0.9, -0.55); glVertex2f(0.7, -0.65); glVertex2f(0.8, -0.9);
        glVertex2f(1.1, -1.1);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(0.8, -0.9); glVertex2f(1.1, -1.1); glVertex2f(0.2, -1.3); glVertex2f(0.2, -1.1);
    glEnd();
    //fist
    glPointSize(17);
    glBegin(GL_POINTS);
        glVertex2f(0.1, -1.2);
    glEnd();

    //tail
    glBegin(GL_QUADS);
        glVertex2f(2, -1.9); glVertex2f(1.8, -2.1); glVertex2f(2.3, -2.3); glVertex2f(2.2, -2.05);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(2.3, -2.3); glVertex2f(2.2, -2.05); glVertex2f(3, -1.7);
    glEnd();

    glPopMatrix();
}

void spiderman1(){
    glPushMatrix();
    glTranslatef(-1.5, -1, 0);

    //back arm
    glColor3f(0.88, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-1.2, 2.2); glVertex2f(-0.7, 2.6); glVertex2f(-0.9, 3); glVertex2f(-1.7, 2.1);
        glVertex2f(-0.9, 1.8); glVertex2f(-0.9, 2.1);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.2, 2.2); glVertex2f(-0.7, 2.6); glVertex2f(-0.9, 3); glVertex2f(-1.7, 2.1);
        glVertex2f(-0.9, 1.8); glVertex2f(-0.9, 2.1);
    glEnd();

    // Draw Spider-Man's body
    glColor3f(0, 0, 1); // Blue color
    glBegin(GL_QUADS);
        glVertex2f(-1, 1.5); glVertex2f(-0.5, 1.3); glVertex2f(-0.45, 1.75); glVertex2f(-0.95, 1.8);

        glColor3f(1, 0, 0);
        glVertex2f(-0.4, 1.75); glVertex2f(-0.95, 1.8); glVertex2f(-0.9, 3); glVertex2f(-0.3, 2.95);
    glEnd();

    // head
    glColor3f(0.88, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.75, 3.1); glVertex2f(-0.2, 3.05); glVertex2f(-0.2, 3.7); glVertex2f(-0.75, 3.7);
    glEnd();

    // front arm
    glColor3f(0.88, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.3, 2.4); glVertex2f(-0.3, 2.95); glVertex2f(-0.5, 3.3); glVertex2f(-0.8, 3.2);
        glVertex2f(-0.9, 3); glVertex2f(0.4, 1.9); glVertex2f(0.8, 2.8); glVertex2f(0.6, 3);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3, 2.4); glVertex2f(-0.3, 2.95); glVertex2f(-0.5, 3.3); glVertex2f(-0.8, 3.2);
        glVertex2f(-0.9, 3); glVertex2f(0.4, 1.9); glVertex2f(0.8, 2.8); glVertex2f(0.6, 3);
    glEnd();

    glColor3f(0, 0, 1); // blue color
    //fist
    glBegin(GL_QUADS);
        glVertex2f(0.55, 3.05); glVertex2f(0.85, 2.78); glVertex2f(1, 2.95); glVertex2f(0.7, 3.25);
    glEnd();

    // front leg
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.3, 1); glVertex2f(-0.6, 0.3); glVertex2f(-0.35, 0.25); glVertex2f(0.3, 1.1);
        glVertex2f(0.2, 1.3);glVertex2f(-1, 1.5); glVertex2f(-0.8, 1);
    glEnd();

    // back leg
    glBegin(GL_QUADS);
        glVertex2f(-1, 1.5); glVertex2f(-0.8, 1); glVertex2f(-1.4, 0.5); glVertex2f(-1.5, 0.85);

        glVertex2f(-1.4, 0.5); glVertex2f(-1.5, 0.85); glVertex2f(-2.1, 0.4); glVertex2f(-1.9, 0.25);
    glEnd();

    // feet
    glBegin(GL_QUADS);
        //front foot
        glVertex2f(-0.6, 0.3); glVertex2f(-0.35, 0.25); glVertex2f(-0.1, 0); glVertex2f(-0.7, 0);

        //back foot
        glVertex2f(-2.1, 0.4); glVertex2f(-1.9, 0.25); glVertex2f(-1.8, -0.1); glVertex2f(-2.3, 0.2);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.3, 1); glVertex2f(-0.6, 0.3); glVertex2f(-0.35, 0.25); glVertex2f(0.3, 1.1);
        glVertex2f(0.2, 1.3); glVertex2f(-1, 1.5); glVertex2f(-1.5, 0.85); glVertex2f(-1.5, 0.85);
        glVertex2f(-2.1, 0.4); glVertex2f(-1.9, 0.25); glVertex2f(-1.4, 0.5); glVertex2f(-0.8, 1);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6, 0.3); glVertex2f(-0.35, 0.25); glVertex2f(-0.1, 0); glVertex2f(-0.7, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.1, 0.4); glVertex2f(-1.9, 0.25); glVertex2f(-1.8, -0.1); glVertex2f(-2.3, 0.2);
    glEnd();

    // eye
    glColor3f(1, 1, 1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(-0.3,3.5);
    glEnd();

    glPopMatrix();
}

void spiderman2(){
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glScalef(1.2, 1.2, 0);

    // spider string
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2f(-4, -2.5);
        glVertex2f(-8.3, -0.5);
    glEnd();

    // fist and arm
    glBegin(GL_QUADS);

        glColor3f(0, 0, 0);
        //behind arm
        glVertex2f(-3, -3.1); glVertex2f(-3.2, -3.5); glVertex2f(-2.4, -3.7); glVertex2f(-3, -3.1);
        //upper body
        glVertex2f(-2.7, -2.5); glVertex2f(-3.2, -2.8); glVertex2f(-2.6, -3.6); glVertex2f(-2.2, -3.2);
        //head
        glVertex2f(-2.6, -2.5); glVertex2f(-2.7, -1.9); glVertex2f(-3.3, -2); glVertex2f(-3.1, -2.6);

        glColor3f(1, 1, 1);
        //eye
        glVertex2f(-2.7, -2.1); glVertex2f(-2.88, -2.1); glVertex2f(-2.85, -2.2); glVertex2f(-2.7, -2.2);
        //lower body
        glVertex2f(-2.6, -3.5); glVertex2f(-2.2, -3.2); glVertex2f(-1.9, -3.6); glVertex2f(-2.1, -4);
        //fist
        glColor3f(1, 1, 1); glVertex2f(-4.2, -2.6); glVertex2f(-4, -2.3); glVertex2f(-3.8, -2.5); glVertex2f(-4, -2.8);
        //arm
        glColor3f(0, 0, 0);
        glVertex2f(-3.8, -2.5); glVertex2f(-4, -2.8); glVertex2f(-3.3, -3.35); glVertex2f(-3.3, -2.9);
        glVertex2f(-3.3, -3.35); glVertex2f(-3.3, -2.9); glVertex2f(-2.7, -2.5); glVertex2f(-2.5, -2.8);
        // front leg
        glVertex2f(-2.1, -4); glVertex2f(-2, -3.6); glVertex2f(-1, -3.9); glVertex2f(-1.3, -4.2);
        glVertex2f(-1, -3.9); glVertex2f(-1.3, -4.2); glVertex2f(-1.1, -4.8); glVertex2f(-0.8, -4.7);
        //front feet
        glVertex2f(-1.1, -4.8); glVertex2f(-0.8, -4.7); glVertex2f(-0.5, -4.9); glVertex2f(-1, -5);
        //behind leg
        glVertex2f(-2.1, -4); glVertex2f(-1.7, -4.1); glVertex2f(-1.6, -4.6); glVertex2f(-1.9, -4.5);
        glVertex2f(-1.6, -4.6); glVertex2f(-1.9, -4.5); glVertex2f(-2.2, -4.8); glVertex2f(-2, -4.9);
        //feet
        glVertex2f(-2.2, -4.8); glVertex2f(-2, -4.9); glVertex2f(-1.9, -5.3); glVertex2f(-2.45, -5);
    glEnd();

    //outline of body parts
    glColor3f(1, 1, 1);
    //behind arm
    glBegin(GL_LINE_STRIP);
        glVertex2f(-3, -3.1); glVertex2f(-3.2, -3.5); glVertex2f(-2.4, -3.7);
    glEnd();
    //head outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.6, -2.5); glVertex2f(-2.7, -1.9); glVertex2f(-3.3, -2); glVertex2f(-3.1, -2.6);
    glEnd();
    // arm outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-3.8, -2.5); glVertex2f(-4, -2.8); glVertex2f(-3.3, -3.35);
        glVertex2f(-2.5, -2.8); glVertex2f(-2.7, -2.5); glVertex2f(-3.3, -2.9);
    glEnd();
    //body outline
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.5, -2.8); glVertex2f(-2.2, -3.2); glVertex2f(-2.6, -3.5); glVertex2f(-2.9, -3.15);
    glEnd();
    // front leg and feet outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.1, -4); glVertex2f(-2, -3.6); glVertex2f(-1, -3.9); glVertex2f(-0.8, -4.7);
        glVertex2f(-0.5, -4.9); glVertex2f(-1, -5); glVertex2f(-1.1, -4.8); glVertex2f(-0.8, -4.7);
        glVertex2f(-1.1, -4.8);  glVertex2f(-1.3, -4.2); glVertex2f(-1.3, -4.2);
    glEnd();
    //behind leg and feet outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.1, -4); glVertex2f(-1.7, -4.1); glVertex2f(-1.6, -4.6); glVertex2f(-2, -4.9);
        glVertex2f(-1.9, -5.3); glVertex2f(-2.45, -5); glVertex2f(-2.2, -4.8); glVertex2f(-2, -4.9);
        glVertex2f(-2.2, -4.8); glVertex2f(-1.9, -4.5);
    glEnd();

    glPopMatrix();
}

void update5(int value) {
    textPosition -= 0.05f; // Adjust speed as needed
    // Check if the entire text has moved past the left edge of the billboard
    if (textPosition + textWidth < -17.5f) {
        textPosition = -7.5f; // Start just at the right edge of the billboard
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

void renderScrollingText(float y, void *font, const char *string) {
    const char *c;
    float charWidth = 0.7f; // Adjust based on your font
    float billboardLeft = -17.5f;
    float billboardRight = -7.5f;
    float x = textPosition;

    if (initialScroll) {
        textWidth = strlen(string) * charWidth;
        initialScroll = false;
    }

    for (c = string; *c != '\0'; c++) {
        if (x > billboardLeft && x < billboardRight) {
            glRasterPos2f(x, y);
            glutBitmapCharacter(font, *c);
        }
        x += charWidth;
    }
}

void building5(){
    glPushMatrix();
    glBegin(GL_QUADS);
        //building 1
        glColor3f(0.2, 0.4, 0.1);
        glVertex2f(-7, -2); glVertex2f(-6, -2); glVertex2f(-6, -15); glVertex2f(-7, -15);
        //building 2
        glVertex2f(16, -5); glVertex2f(19, -5); glVertex2f(19, -15); glVertex2f(16, -15);
        glColor3f(0.5, 0.43, 0);
        //building 3
        glVertex2f(-5, 3); glVertex2f(5, 3); glVertex2f(5, -15); glVertex2f(-5, -15);
        //building 4
        glVertex2f(-18, 4); glVertex2f(-7, 4); glVertex2f(-7, -15); glVertex2f(-18, -15);
        glVertex2f(-16, 8); glVertex2f(-9, 8); glVertex2f(-9, 4); glVertex2f(-16, 4);
        //building 5
        glColor3f(0.4, 0.6, 0.1);
        glVertex2f(8, -7); glVertex2f(17, -7); glVertex2f(17, -15); glVertex2f(8, -15);


    glEnd();

    //flag
    glColor3f(1, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-9, 6); glVertex2f(-8, 9);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        glVertex2f(-8, 9); glVertex2f(-5, 8); glVertex2f(-5.5, 6.5); glVertex2f(-8.5, 7.5);
        glColor3f(0, 0, 1);
        glVertex2f(-8, 9); glVertex2f(-6.85, 8.6); glVertex2f(-7.08, 7.9); glVertex2f(-8.2, 8.3);
    glEnd();

    //billboard
    glBegin(GL_QUADS);
        //frame
        glColor3f(0, 0, 0);
        glVertex2f(-18, 4); glVertex2f(-7, 4); glVertex2f(-7, -1); glVertex2f(-18, -1);
        //screen
        glColor3f(1, 1, 1);
        glVertex2f(-17.5, 3.5); glVertex2f(-7.5, 3.5); glVertex2f(-7.5, -0.5); glVertex2f(-17.5, -0.5);
    glEnd();
    // Render text on the billboard
    glColor3f(0, 0, 0);
    renderScrollingText(3, GLUT_BITMAP_TIMES_ROMAN_24, billboardText);

    //Venom
    glPushMatrix();
        glTranslatef(-12.5, 0.5, 0);

        glColor3f(0.1, 0.1, 0.1); // Very dark grey, almost black

        // head
        glBegin(GL_POLYGON);
        glVertex2f(0.3, -1); glVertex2f(-0.3, -1); glVertex2f(-0.7, -0.5); glVertex2f(-1, 0.2); glVertex2f(-1.1, 0.7);
        glVertex2f(-1.05, 1); glVertex2f(-0.8, 1.3); glVertex2f(-0.35, 1.5);
        glVertex2f(0.35, 1.5); glVertex2f(0.8, 1.3); glVertex2f(1.05, 1);
        glVertex2f(1.1, 0.7); glVertex2f(1, 0.2); glVertex2f(0.7, -0.5);
        glEnd();
        //mouth
        glColor3f(1, 0, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0, -0.5); glVertex2f(0, 0); glVertex2f(-0.4, 0.1); glVertex2f(-0.9, 0.4);
            glVertex2f(-0.6, -0.3); glVertex2f(-0.1, -1);
            glVertex2f(0.1, -1); glVertex2f(0.6, -0.3); glVertex2f(0.9, 0.4); glVertex2f(0.4, 0.1); glVertex2f(0, 0);
        glEnd();

        glColor3f(1, 1, 1); // White
        //teeth
        glBegin(GL_TRIANGLES);
            //upper teeth
            glVertex2f(-0.8, 0.35); glVertex2f(-0.7, 0.3); glVertex2f(-0.7, 0);
            glVertex2f(-0.65, 0.25); glVertex2f(-0.5, 0.15); glVertex2f(-0.54, -0.3);
            glVertex2f(-0.45, 0.15); glVertex2f(-0.35, 0.1); glVertex2f(-0.4, -0.4);
            glVertex2f(-0.25, 0.05); glVertex2f(-0.15, 0.05); glVertex2f(-0.2, -0.6);
            glVertex2f(-0.1, 0); glVertex2f(0.05, 0); glVertex2f(0, -0.6);
            glVertex2f(0.25, 0.05); glVertex2f(0.15, 0.05); glVertex2f(0.2, -0.6);
            glVertex2f(0.45, 0.15); glVertex2f(0.35, 0.1); glVertex2f(0.4, -0.4);
            glVertex2f(0.65, 0.25); glVertex2f(0.5, 0.15); glVertex2f(0.54, -0.3);
            glVertex2f(0.8, 0.35); glVertex2f(0.7, 0.3); glVertex2f(0.7, 0);
            //lower teeth
            glVertex2f(-0.7, -0.1); glVertex2f(-0.6, -0.3); glVertex2f(-0.65, 0.2);
            glVertex2f(-0.55, -0.35); glVertex2f(-0.45, -0.5); glVertex2f(-0.5, -0.1);
            glVertex2f(-0.4, -0.6); glVertex2f(-0.25, -0.8); glVertex2f(-0.3, -0.1);
            glVertex2f(-0.15, -0.9); glVertex2f(-0.05, -1); glVertex2f(-0.1, -0.2);
            glVertex2f(0.7, -0.1); glVertex2f(0.6, -0.3); glVertex2f(0.65, 0.2);
            glVertex2f(0.55, -0.35); glVertex2f(0.45, -0.5); glVertex2f(0.5, -0.1);
            glVertex2f(0.4, -0.6); glVertex2f(0.25, -0.8); glVertex2f(0.3, -0.1);
            glVertex2f(0.15, -0.9); glVertex2f(0.05, -1); glVertex2f(0.1, -0.2);
        glEnd();
        // Left eye
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(-0.65, 0.7); glVertex2f(-0.5, 0.7); glVertex2f(-0.5, 0.8); glVertex2f(-0.6, 0.9);
            glVertex2f(-0.6, 1.1); glVertex2f(-0.7, 1); glVertex2f(-0.75, 0.8); glVertex2f(-0.65, 0.5);
            glVertex2f(-0.55, 0.4); glVertex2f(-0.4, 0.3); glVertex2f(-0.2, 0.3); glVertex2f(-0.1, 0.4);
            glVertex2f(-0.5, 0.7);
        glEnd();
        //right eye
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.65, 0.7); glVertex2f(0.5, 0.7); glVertex2f(0.5, 0.8); glVertex2f(0.6, 0.9);
            glVertex2f(0.6, 1.1); glVertex2f(0.7, 1); glVertex2f(0.75, 0.8); glVertex2f(0.65, 0.5);
            glVertex2f(0.55, 0.4); glVertex2f(0.4, 0.3); glVertex2f(0.2, 0.3); glVertex2f(0.1, 0.4);
            glVertex2f(0.5, 0.7);
        glEnd();

    glPopMatrix();

    glColor3f(0, 0, 0);
    glPointSize(60);
    glBegin(GL_POINTS);
        // windows for building 3
        for(int y = 1; y > -13; y-=3){
            for(int x = -3; x < 4; x+=3)
                glVertex2f(x, y);
        }
        // windows for building 4
        for(int y = -3; y > -13; y-=3){
            for(int x = -15; x < -8; x+=3)
                glVertex2f(x-0.5, y+0.5);
        }
    glEnd();

    glPopMatrix();
}




void backgroundscene5()
{

    init();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset transformations
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd(); glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.7, 0.8);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.9, 0.4);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.17, 0.6);
    glVertex2f(-0.13, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-0.19, 0.5);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.17, 0.4);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.9, 0.8);
    glVertex2f(0.1, 0.8);
    glVertex2f(0.19, 0.5);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.17, 0.4);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.9, 0.8);
    glVertex2f(0.1, 0.9);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.8);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.9, 0.4);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.17, 0.9);
    glVertex2f(0.13, 0.5);
    glEnd();
    building5();
    drawScaffoldingLevel();
    villain();
    electro();
    theLizard();
    spiderman1();
    spiderman2();
    glutSwapBuffers(); // Swap buffers for double buffering
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            scene1();
            if (!isAnimating) {
                isAnimating = true; // Start animation
                glutTimerFunc(50, update, 0); // Start the continuous timer
            }
            break;
        case '2':
        backgroundscene2();
        if (!timerRunning) {
            timerRunning = true;
            glutTimerFunc(16, timer, 0);
        }
        wizardAngle += 5.0f;
        wizardRotateX += 0.0f;
        wizardRotateY += 0.0f;
        wizardRotateZ += 0.6f;
        if(wizardAngle>=5.0f)
            {
                wizardAngle=0.0f;
                glutTimerFunc(16, timer, 0);
            }
    lightningEnabled = true;
    lightningFlashCounter = lightningFlashDuration; // Reset the flash counte

        glutPostRedisplay();


            break;
        case '3':
            drawBackgroundscene3();
               angle += 0.02f; // Update the angle
        if (angle > 2 * 3.14159265) {
            angle -= 2 * 3.14159265; // Reset the angle if it goes beyond 360 degrees
        }
        glutPostRedisplay(); // Request a redraw
        glutTimerFunc(16, timer, 0); // Call the timer function again after 16 milliseconds
        spidermanTranslateX += 1.0f;
        spidermanlineEnabled = true;
            break;

        case'4':
            backgroundscene4();
            if (angle > 2 * 3.14159265) {
            angle -= 2 * 3.14159265; // Reset the angle if it goes beyond 360 degrees
            }
        glutPostRedisplay(); // Request a redraw
        glutTimerFunc(16, timer, 0); // Call the timer function again after 16 milliseconds

        break;

        case '5' :
    backgroundscene5();
    textPosition -= 0.05f; // Adjust speed as needed
    // Check if the entire text has moved past the left edge of the billboard
    if (textPosition + textWidth < -17.5f) {
        textPosition = -7.5f; // Start just at the right edge of the billboard
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
    break;
        default:
            break;
    }
    glFlush();
    glutPostRedisplay();
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Cover");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
