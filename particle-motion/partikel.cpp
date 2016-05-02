// Program : Simulasi Gerak Partikel 

#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define pi 3.141592653589793

using namespace std;

GLint warna1[2]={0,1},warna2[2]={1,0},w1=0,w2=1,ws=1;
GLfloat x[2]={1,0.5},y[2]={0,0.1},z[2]={0,0},xs,ys;
GLfloat vx[2]={0.002,0.001},vy[2]={0.002*sqrt(3),-0.002};
GLfloat a=3,b=-3,c=a*sqrt(3);
GLfloat r[2]={sqrt(vx[0]*vx[0]+vy[0]*vy[0]),sqrt(vx[1]*vx[1]+vy[1]*vy[1])};
GLfloat teta[2]={atan(vy[0]/vx[0]),atan(vy[1]/vx[1])};
GLfloat g_kanan,g_kiri,g_bawah;

void Draw() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_STRIP);
        glVertex3f(b, 0, 0.0);
        glVertex3f(0, c, 0.0);
        glVertex3f(a, 0, 0.0);
        glVertex3f(b, 0, 0.0);
    glEnd();

    for (int i=0;i<2;i++){
			xs=x[i]+vx[i];
			ys=y[i]+vy[i];
 
		g_kanan=-c/a*xs+c;
    if (ys>g_kanan){
			vx[i]=-r[i]*cos(pi/3-teta[i]);
			vy[i]=-r[i]*sin(pi/3-teta[i]);
			teta[i]=atan(vy[i]/vx[i]);
	  }

    g_kiri=-c/b*xs+c;
	  if (ys>g_kiri){
			vx[i]=r[i]*cos(pi/3+teta[i]);
			vy[i]=-r[i]*sin(pi/3+teta[i]);
			teta[i]=atan(vy[i]/vx[i]);
	  }
	   
	  g_bawah=0.;
	  if (ys<g_bawah){
			vy[i]=-vy[i];
			teta[i]=atan(vy[i]/vx[i]);
	  }
	  
	  x[i] += vx[i];
	  y[i] += vy[i];
	    
	  glColor3f(0, (i+w1)%2,(i+w2)%2);
	    glPushMatrix();
        	glTranslated(x[i],y[i],0);
        	glutSolidSphere(0.2,20,20);
    	    glPopMatrix();
		
    }
    // cek tumbukan
    if ((fabs(x[1]-x[0])+fabs(y[1]-y[0]))<0.5){
				w1=(w1+1)%2;
				w2=(w2+1)%2;
		}
    glFlush();
    glutPostRedisplay();
}
 
void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.5, 3.5, -0.5, 6, -1.0, 1.0);
}
 
int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Pergerakan Partikel");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
