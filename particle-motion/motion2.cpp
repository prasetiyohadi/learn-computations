#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#define PI 3.141592653589793
using namespace std;

GLboolean coll;
GLint color1[2] = {0, 1}, color2[2] = {1, 0}, w1 = 0, w2 = 1, ws = 1;
GLfloat a[2] = {0.0, 0.0}, b[2] = {6.0, 0.0}, c[2] = {3.0, 4.0}, r = 0.1f;
GLfloat x[2] = {2.5, 3.5}, y[2] = {3.0, 3.0}, xt[2], yt[2];
GLfloat vx[2] = {0.05, -0.05}, vy[2] = {-0.05, -0.05}, vxt[2], vyt[2], vr[2];
GLfloat dt = 0.01, t = 0;
GLfloat theta[2] = {atan2(vy[0], vx[0]), atan2(vy[1], vx[1])}, thetat[2], beta;
GLfloat alpha[2] = {0.927, 2.214};
GLfloat T[2][2][2] = {{{cos(2.0*alpha[0]), sin(2.0*alpha[0])}, {sin(2.0*alpha[0]), -cos(2.0*alpha[0])}}, 
    {{cos(2.0*alpha[1]), sin(2.0*alpha[1])}, {sin(2.0*alpha[1]), -cos(2.0*alpha[1])}}};

static size_t nbytes = 3*660*440;
static char* framedata = new char[nbytes];


void Draw () {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(a[0], a[1], 0.0);
        glVertex3f(b[0], b[1], 0.0);
        glVertex3f(c[0], c[1], 0.0);
        glVertex3f(a[0], a[0], 0.0);
    glEnd();

    for (int i=0; i<2; i++) {
        xt[i] = x[i] + vx[i]*dt;
        yt[i] = y[i] + vy[i]*dt;
        vr[i] = sqrt(pow(vx[i], 2)+pow(vy[i], 2));

        if (sqrt(pow(xt[0]-xt[1], 2)+pow(yt[0]-yt[1], 2)) < 2*r) {
            coll = true;
            beta = atan2((yt[0]-y[1]), (xt[0]-xt[1]));
            vxt[0] = vr[1]*cos(theta[1]-beta);
            vyt[0] = vr[0]*sin(theta[0]-beta);
            vxt[1] = vr[0]*cos(theta[0]-beta);
            vyt[1] = vr[1]*sin(theta[1]-beta);
            for (int j=0; j<2; j++) {
                vx[j] = vxt[j]*cos(beta)+vyt[j]*cos(beta+PI/2);
                vy[j] = vxt[j]*sin(beta)+vyt[j]*sin(beta+PI/2);
                theta[j] = atan2(vy[j], vx[j]);
            }
        } else coll = false;

        if (yt[i]+0.06 > 4.0*(xt[i]-0.08)/3.0) {
            thetat[i] = 2.0*PI + 2.0*alpha[0] - theta[i];
            vx[i] = vr[i]*cos(thetat[i]);
            vy[i] = vr[i]*sin(thetat[i]);
            //theta[i] = atan2(vy[i], vx[i]);
        }

        if (yt[i]+0.06 > -4.0*(xt[i]+0.08)/3.0+8.0) {
            thetat[i] = 2.0*PI + 2.0*alpha[1] - theta[i];
            vx[i] = vr[i]*cos(thetat[i]);
            vy[i] = vr[i]*sin(thetat[i]);
            //theta[i] = atan2(vy[i], vx[i]);
        }

        if (yt[i]-r < 0.0) {
            thetat[i] = 2.0*PI - theta[i];
            vx[i] = vr[i]*cos(thetat[i]);
            vy[i] = vr[i]*sin(thetat[i]);
            //theta[i] = atan2(vy[i], vx[i]);
        }
    }

    for (int i=0; i<2; i++) {
        x[i] = x[i] + vx[i]*dt;
        y[i] = y[i] + vy[i]*dt;
        theta[i] = atan2(vy[i], vx[i]);

        glColor3f((i+w1)%2, 0, (i+w2)%2);
        glPushMatrix();
            glTranslated(x[i], y[i], 0);
            glutSolidSphere(r, 20, 20);
        glPopMatrix();
    }

    t = t + dt;
    glFlush();
    glutPostRedisplay();

    glReadPixels(0, 0, 660, 440, GL_RGB,GL_UNSIGNED_BYTE, framedata);
    fwrite(framedata, 1, nbytes, stdout);
    glutSwapBuffers();
}


void Initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.05f, b[0]+0.05f, -0.05f, c[1]+0.05f, 0.0f, 1.0f);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(660, 440);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Particle Motion");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
