#include<GL/glut.h>

void maincube(GLfloat colr1, GLfloat colr2, GLfloat colr3) {
    glBegin(GL_QUADS);

    // Front face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Top face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Left face
    glColor3f(colr1, colr2, colr3);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();
}


void drawcube(){
glPushMatrix();
glScalef(0.05,0.04,0.05);
glTranslatef(30,5,1);
maincube(0.5f,0.5f,0.5f);
glPopMatrix();

}



void drawlantai(){
glPushMatrix();
glScalef(-1.5,0.040,1.5);
glTranslatef(0,0,0);
maincube(0.5,0.5,0.5);
glPopMatrix();

glPushMatrix();
glScalef(-1.55,0.020,1.55);
glTranslatef(0,-3,0);
maincube(92.0f/255.0f,64.0f/255.0f,51.0f/255.0f);
glPopMatrix();

glPushMatrix();
glScalef(-1.6,0.020,1.6);
glTranslatef(0,-5,0);
maincube(92.0f/255.0f,64.0f/255.0f,51.0f/255.0f);
glPopMatrix();

glPushMatrix();
glScalef(-1.65,0.020,1.65);
glTranslatef(0,-7,0);
maincube(92.0f/255.0f,64.0f/255.0f,51.0f/255.0f);
glPopMatrix();
}

void drawpenyangga(){
// posisi y = 1.tiap y naik 1 maka penyangga nambah 0.4 dari sumbu x sehingga
//1 = 0.4 dengan perbandingan 1/0.4 = x/0.02 didapat hasil 0.05 jadi 1 + 0.05 = 1.05
//0.02 didapat dari lantai yang skala tinggi dibuat 0.04 dengan translasi 0 sehingga
//diambil setengah bagaian atasnya yaitu 0.02

//penyangga 1
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,29);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

//penyangga 2
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,29);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

//penyangga 3 (tengah)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,0);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

//penyangga 4 (tengah)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,0);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

//penyangga 5(belakang)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,-29);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

//penyangga 6 (belakang)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,-29);
maincube(212.0f/255.0f,123.0f/255.0f,6.0f/255.0f);
glPopMatrix();

}
void drawrumput(){
glPushMatrix();
glScalef(3,0.08,3);
glTranslatef(0,-3,0);
maincube(18.0f/255.0f,1.0f,65.0f/255.0f);
glPopMatrix();
}


//garis bantu
void drawline(){
glBegin(GL_LINES);
glLineWidth(5);
glColor3f(0,0,0);
glVertex3f(-5,0,0);
glVertex3f(5,0,0);
glEnd();

glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex3f(0,5,0);
glVertex3f(0,-5,0);
glEnd();
}


void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(-3,3,6,
          0,0,0,
          0,1,0);

drawrumput();
drawlantai();
drawpenyangga();
drawline();
//drawcube();


glutSwapBuffers();
}

void reshape(int width, int height){
glClearColor(1,1,1,1);
glViewport(0,0,width,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0 ,(double)width/(double)height,1.0,100.0);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char**argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(800,600);
glutCreateWindow("Project 3D");

glEnable(GL_DEPTH_TEST);

glutDisplayFunc(display);
glutReshapeFunc(reshape);

glutMainLoop();
return 0;
}
