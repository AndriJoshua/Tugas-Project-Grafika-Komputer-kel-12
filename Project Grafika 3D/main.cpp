#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//Untuk menyimpan tiap-tiap Variabel tekstur yang digunakan
GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;

//posisi awal kamera
GLfloat cameraX = 0.0f;
GLfloat cameraY=   2.0f;
GLfloat cameraZ = 7.0f;

//sudut awal kamera(look at)
GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;

int lastMouseX;
int lastMouseY;


void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glEnable(GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_NORMALIZE);
    glEnable(GL_SMOOTH);
    // Tekstur 1 (kayu penyangga)
    int width, height, channels;
    unsigned char* image = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/realwood.jpg", &width, &height, &channels, STBI_rgb_alpha);
    if (image == NULL) {
        printf("Error loading texture 1\n");
        exit(1);
    }
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);

    // Parameter Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //tekstur 2 (lantai)
     int width2, height2, channels2;
    unsigned char* image2 = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/realdarkwood2.jpg", &width2, &height2, &channels2, STBI_rgb_alpha);
    if (image2 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }

    // Generate and bind texture 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2);
    stbi_image_free(image2);

    //Parameter Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //tekstur 3(rumput)
    int width3, height3, channels3;
    unsigned char* image3 = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/Lgrass2.jpg", &width3, &height3, &channels3, STBI_rgb_alpha);
    if (image3 == NULL) {
        printf("Error loading texture 3\n");
        exit(1);
    }
    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width3, height3, 0, GL_RGBA, GL_UNSIGNED_BYTE, image3);
    stbi_image_free(image3);

    // Parameter Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     int width4, height4, channels4;
    unsigned char* image4 = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/birch.jpg", &width4, &height4, &channels4, STBI_rgb_alpha);
    if (image4 == NULL) {
        printf("Error loading texture 4\n");
        exit(1);
    }


    glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width3, height3, 0, GL_RGBA, GL_UNSIGNED_BYTE, image4);
    stbi_image_free(image4);

    // Parameter Untuk Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     int width5, height5, channels5;
    unsigned char* image5 = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/wheat.jpg", &width5, &height5, &channels5, STBI_rgb_alpha);
    if (image5 == NULL) {
        printf("Error loading texture 5\n");
        exit(1);
    }

    glGenTextures(1, &texture5);
    glBindTexture(GL_TEXTURE_2D, texture5);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width5, height5, 0, GL_RGBA, GL_UNSIGNED_BYTE, image5);
    stbi_image_free(image5);

    // Parameter Untuk Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     int width6, height6, channels6;
    unsigned char* image6 = stbi_load("C:/Users/andri/Documents/codingan oe/Project 3D World/texture/darkwoodmeja.jpg", &width6, &height6, &channels6, STBI_rgb_alpha);
    if (image6 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }

    glGenTextures(1, &texture6);
    glBindTexture(GL_TEXTURE_2D, texture6);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width5, height5, 0, GL_RGBA, GL_UNSIGNED_BYTE, image6);
    stbi_image_free(image6);

    // Parameter Untuk Tekstur yang digunakan
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };  // Ambient light
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Diffuse light
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular light

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // Define material properties
    GLfloat matAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat matDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };


    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);

}

void drawmaincube(GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    // Depan
    glNormal3f(0.0, 0.0, 1.0); //normal
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);

    // Belakang
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);

    // Atas
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);

    // Bawah
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);

    // Kanan
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);

    // Kiri
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);
    glEnd();
}

void drawcube(){
glPushMatrix();
glScalef(3,2,0.2);
glTranslatef(0,0,0);
drawmaincube(texture1);
glPopMatrix();
}

void drawlantai(){

glPushMatrix();
glScalef(-1.6,0.040,1.6);
glTranslatef(0,0,0);
drawmaincube(texture2);
glPopMatrix();

glPushMatrix();
glScalef(-1.65,0.020,1.65);
glTranslatef(0,-3,0);
drawmaincube(texture2);
glPopMatrix();

glPushMatrix();
glScalef(-1.7,0.020,1.7);
glTranslatef(0,-5,0);
drawmaincube(texture2);
glPopMatrix();

glPushMatrix();
glScalef(-1.75,0.020,1.75);
glTranslatef(0,-7,0);
drawmaincube(texture2);
glPopMatrix();
}

void drawpenyangga(){
// posisi y = 1.tiap y naik 1 maka penyangga nambah 0.4 dari sumbu x sehingga
//1 = 0.4 dengan perbandingan 1/0.4 = x/0.02 didapat hasil 0.05 jadi 1 + 0.05 = 1.05
//0.02 didapat dari lantai yang skala tinggi dibuat 0.04 dengan translasi 0 sehingga
//diambil setengah bagian atasnya yaitu 0.02
//penyangga kanan
for (int i = 0; i < 3; i++) {
    float z = 29 - i * 29;

    glPushMatrix();
    glScalef(0.05, 0.8, 0.05);
    glTranslatef(29, 1.05, z);
    drawmaincube(texture1);
    glPopMatrix();
}
//penyangga kiri
for (int i = 0; i < 3; i++) {
    float z = 29 - i * 29;

    glPushMatrix();
    glScalef(0.05, 0.8, 0.05);
    glTranslatef(-29, 1.05, z);
    drawmaincube(texture1);
    glPopMatrix();
}
}
void drawrumput(){
glPushMatrix();
glScalef(3.5,0.08,3.5);
glTranslatef(0,-3,0);
drawmaincube(texture3);
glPopMatrix();
}

//garis bantu
void drawline(){
glBegin(GL_LINES);
glLineWidth(5);
glColor3f(1,0,0);
glVertex3f(-10,0,0);
glVertex3f(10,0,0);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(0,10,0);
glVertex3f(0,-10,0);
glEnd();

glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex3f(0,0,10);
glVertex3f(0,0,-10);
glEnd();
}

void drawatap(){
glPushMatrix();
glScalef(1.4,0.15,0.02);
glTranslatef(0,10,73);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(1.4,0.15,0.02);
glTranslatef(0,10,-73);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glRotatef(90, 0.0, 1.0, 0.0);
glScalef(0.75 - 0.05 - 0.025, 0.15, 0.02);
glTranslatef(-1.07, 10, 73);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glRotatef(90, 0.0, 1.0, 0.0);
glScalef(0.75 - 0.05 - 0.025, 0.15, 0.02);
glTranslatef(1.07, 10, 73);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glRotatef(-90, 0.0, 1.0, 0.0);
glScalef(0.75-0.05-0.025, 0.15, 0.02);
glTranslatef(-1.07 , 10, 73);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glRotatef(-90, 0.0, 1.0, 0.0); // Rotate around the y-axis
glScalef(0.75 - 0.025 - 0.05, 0.15, 0.02);
glTranslatef(1.07, 10, 73);
drawmaincube(texture4);
glPopMatrix();

//atap penutup atas
glPushMatrix();
glScalef(1.5,0.02,1.5);
glTranslatef(0,0.8/0.01+3,0);
drawmaincube(texture4);
glPopMatrix();

//balok atap tenagah
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,0);
drawmaincube(texture4);
glPopMatrix();

//balok atap depan
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
drawmaincube(texture4);
glPopMatrix();

//balok atap belakang
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,-29);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29/2);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,-29/2);
drawmaincube(texture4);
glPopMatrix();

//balok kanan
glPushMatrix();
glRotatef(90,0,1,0);
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
drawmaincube(texture4);
glPopMatrix();

//balok kiri
glPushMatrix();
glRotatef(-90,0,1,0);
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
drawmaincube(texture4);
glPopMatrix();
}

void drawstep(){
for(int i = 0 ; i < 3;i++){
float z = 20 + i * 5;
glPushMatrix();
glScalef(0.5,0.020,0.1);
glTranslatef(0,-7,z);
drawmaincube(texture1);
glPopMatrix();
}
}

void drawkursi(){
//baris belakang
for(int i = 0 ; i < 3; i++){
float z = 9 - i * 5;
glPushMatrix();
glScalef(0.15,0.02,0.15);
glTranslatef(7.5,3,z);
drawmaincube(texture5);
glPopMatrix();
}

for(int i = 0 ; i < 3;i++){
float z = 9 - i *5;
glPushMatrix();
glScalef(0.15,0.02,0.15);
glTranslatef(4,3,z);
drawmaincube(texture5);
glPopMatrix();
}

for(int i = 0;i<3;i++){
float z = 9 - i * 5;
glPushMatrix();
glScalef(0.15,0.02,0.15);
glTranslatef(-7.5,3,z);
drawmaincube(texture5);
glPopMatrix();
}
for(int i = 0 ; i < 3;i++){
float z = 9 - i * 5;
glPushMatrix();
glScalef(0.15,0.02,0.15);
glTranslatef(-4,3,z);
drawmaincube(texture5);
glPopMatrix();
}

}

void drawtable(){
//meja barisan kanan
for(int i = 0 ; i < 3 ; i ++){
float z = 10 - i * 7.5;
float z_papan = 5 - i * 3.7;
glPushMatrix();//kaki meja 1
glScalef(0.075,0.08,0.1);
glTranslatef(6,1.5,z);
drawmaincube(texture6);
glPopMatrix();

glPushMatrix();
glScalef(0.075,0.08,0.1);
glTranslatef(17,1.5,z);
drawmaincube(texture6);
glPopMatrix();

glPushMatrix();//papan meja 1
glScalef(0.6,0.02,0.2);
glTranslatef(1.43,8+1.5+1,z_papan);
drawmaincube(texture6);
glPopMatrix();
}
//meja barisan kiri
for(int i = 0 ; i < 3 ; i ++){
float z = 10 - i * 7.5;
float z_papan = 5 - i * 3.7;
glPushMatrix();//kaki meja 1
glScalef(-0.075,0.08,0.1);
glTranslatef(6,1.5,z);
drawmaincube(texture6);
glPopMatrix();

glPushMatrix();
glScalef(-0.075,0.08,0.1);
glTranslatef(17,1.5,z);
drawmaincube(texture6);
glPopMatrix();

glPushMatrix();//papan meja 1
glScalef(-0.6,0.02,0.2);
glTranslatef(1.43,8+1.5+1,z_papan);
drawmaincube(texture6);
glPopMatrix();
}
}
void mejadepan(){
glPushMatrix();
glScalef(0.8,0.15,0.01);
glTranslatef(0,1.3,-1*135);
drawmaincube(texture1);
glPopMatrix();

glPushMatrix();
glScalef(0.05,0.15,0.1);
glTranslatef(0,1.3,-12.5);
drawmaincube(texture1);
glPopMatrix();

glPushMatrix();
glScalef(0.8,0.01,0.1);
glTranslatef(0,35,-12.5-0.1);
drawmaincube(texture1);
glPopMatrix();

glPushMatrix();
glScalef(0.8,0.01,0.1);
glTranslatef(0,5,-12.5-0.1);
drawmaincube(texture1);
glPopMatrix();

glPushMatrix();
glScalef(0.01,0.15,0.1);
glTranslated(80,1.3,-12.5-0.1);
drawmaincube(texture1);
glPopMatrix();

glPushMatrix();
glScalef(-0.01,0.15,0.1);
glTranslated(80,1.3,-12.5-0.1);
drawmaincube(texture1);
glPopMatrix();
}

void drawpapantulis(){
glPushMatrix();
glScalef(0.5,0.40,0.01);
glTranslatef(0,1.1,-138);
drawmaincube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(0.4,0.20,0.01);
glTranslatef(0,3,-137);
drawmaincube(texture6);
glPopMatrix();
}

void keyboardfunc(unsigned char key, int x ,int y){
switch (key) {
    case 'i':
    case 'I':
        cameraY-=1.0f;
        break;
    case 'o':
    case 'O':
        cameraY+=1.0f;
        break;
    case 'w':
    case 'W':
        cameraZ -= 0.1f;
        break;
    case 's':
    case 'S':
        cameraZ += 0.1f;
        break;
    case 'a':
    case 'A':
        cameraX -= 0.1f;
        break;
    case 'd':
    case 'D':
        cameraX += 0.1f;
        break;
    }
    glutPostRedisplay();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(cameraX,cameraY,cameraZ,
          angleY,angleX,0,
          0,1,0);

  GLfloat lightPosition[] = { 5.0f, 5.0f, 5.0f, 1.0f }; // Light position above the object
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

drawrumput();
drawlantai();
drawpenyangga();
drawatap();
//drawline();
drawstep();
drawkursi();
drawtable();
mejadepan();
drawpapantulis();
//drawcube();


glutSwapBuffers();
}
void mouse(int x, int y) {
    int deltaX = x - lastMouseX;
    int deltaY = y - lastMouseY;

    angleY += deltaX * 0.1f;
    angleX -= deltaY * 0.1f;

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastMouseX = x;
        lastMouseY = y;
        glutMotionFunc(mouse);
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        glutMotionFunc(NULL);
    }
}
void reshape(int width, int height){
//glClearColor(4.0/255.0,99.0/255.0,202.0/255.0,0);
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
init();
glEnable(GL_DEPTH_TEST);

glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboardfunc);
glutMouseFunc(mouseButton);

glutMainLoop();
return 0;
}

