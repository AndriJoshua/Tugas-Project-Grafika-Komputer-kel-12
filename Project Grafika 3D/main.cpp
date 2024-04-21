#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint texture; // Variable to store the texture ID
GLuint texture2;
GLuint texture3;
GLuint texture4;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering

    // Tekstur 1 (kayu penyangga)
    int width, height, channels;
    unsigned char* image = stbi_load("C:/Users/andri/Documents/codingan oe/OpenGl CPP/Project Grafika 3D/texture/wood.jpg", &width, &height, &channels, STBI_rgb_alpha);
    if (image == NULL) {
        printf("Error loading texture\n");
        exit(1);
    }
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //tekstur 2 (lantai)
     int width2, height2, channels2;
    unsigned char* image2 = stbi_load("C:/Users/andri/Documents/codingan oe/OpenGl CPP/Project Grafika 3D/texture/darkwood.jpg", &width2, &height2, &channels2, STBI_rgb_alpha);
    if (image2 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }

    // Generate and bind texture 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2);
    stbi_image_free(image2);

    // Set texture parameters (same as before)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //tekstur 3(rumput)
    int width3, height3, channels3;
    unsigned char* image3 = stbi_load("C:/Users/andri/Documents/codingan oe/OpenGl CPP/Project Grafika 3D/texture/Lgrass.jpg", &width3, &height3, &channels3, STBI_rgb_alpha);
    if (image3 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }


    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width3, height3, 0, GL_RGBA, GL_UNSIGNED_BYTE, image3);
    stbi_image_free(image3);

    // Set texture parameters (same as before)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     int width4, height4, channels4;
    unsigned char* image4 = stbi_load("C:/Users/andri/Documents/codingan oe/OpenGl CPP/Project Grafika 3D/texture/birch.jpg", &width4, &height4, &channels4, STBI_rgb_alpha);
    if (image4 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }


    glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width3, height3, 0, GL_RGBA, GL_UNSIGNED_BYTE, image4);
    stbi_image_free(image4);

    // Set texture parameters (same as before)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Mengaktifkan pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // satu sumber cahaya

    // Set up Sumber cahaya
    GLfloat light_position[] = { -1.0, 0.0, 0.0, 1.0 }; // Light position (x, y, z, w)

// Define the diffuse and ambient light colors
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Diffuse color (r, g, b, a)
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // Ambient color (r, g, b, a)

// Set light properties
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}

void drawbrick() {
    glBindTexture(GL_TEXTURE_2D, texture2);
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);

    // Back face
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);
    glEnd();
}

void drawbirchwood() {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);  // Top-left

    // Back face
    glNormal3f(0.0, 0.0, -1.0); // Normal for the back face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);  // Top-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);  // Bottom-left

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);  // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);   // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);  // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1); // Top-left

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Top-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);  // Top-left
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);   // Bottom-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);  // Bottom-right

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);  // Top-left

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);  // Bottom-left
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);  // Top-right
    glEnd();
}

void KubusRumput() {
    glBindTexture(GL_TEXTURE_2D, texture3);
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);  // Top-left

    // Back face
    glNormal3f(0.0, 0.0, -1.0); // Normal for the back face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);  // Top-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);  // Bottom-left

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);  // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);   // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);  // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1); // Top-left

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Top-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);  // Top-left
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);   // Bottom-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);  // Bottom-right

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);  // Top-left

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);  // Bottom-left
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);  // Top-right
    glEnd();
}

void KubusAtap(){
    glBindTexture(GL_TEXTURE_2D, texture4);
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);  // Top-left

    // Back face
    glNormal3f(0.0, 0.0, -1.0); // Normal for the back face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);  // Top-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);  // Bottom-left

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);  // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);   // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);  // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1); // Top-left

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1); // Top-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);  // Top-left
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);   // Bottom-left
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);  // Bottom-right

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1); // Bottom-left
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);  // Bottom-right
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);   // Top-right
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);  // Top-left

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1); // Bottom-right
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);  // Bottom-left
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);   // Top-left
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);  // Top-right
    glEnd();
}
void drawcube(){
glPushMatrix();
glScalef(3,2,0.2);
glTranslatef(0,0,0);
drawbrick();
glPopMatrix();
}

void drawlantai(){

glPushMatrix();
glScalef(-1.6,0.040,1.6);
glTranslatef(0,0,0);
drawbrick();
glPopMatrix();

glPushMatrix();
glScalef(-1.65,0.020,1.65);
glTranslatef(0,-3,0);
drawbrick();
glPopMatrix();

glPushMatrix();
glScalef(-1.7,0.020,1.7);
glTranslatef(0,-5,0);
drawbrick();
glPopMatrix();

glPushMatrix();
glScalef(-1.75,0.020,1.75);
glTranslatef(0,-7,0);
drawbrick();
glPopMatrix();
}

void drawpenyangga(){
// posisi y = 1.tiap y naik 1 maka penyangga nambah 0.4 dari sumbu x sehingga
//1 = 0.4 dengan perbandingan 1/0.4 = x/0.02 didapat hasil 0.05 jadi 1 + 0.05 = 1.05
//0.02 didapat dari lantai yang skala tinggi dibuat 0.04 dengan translasi 0 sehingga
//diambil setengah bagian atasnya yaitu 0.02

//penyangga 1
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,29);
drawbirchwood();
glPopMatrix();

//penyangga 2
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,29);
drawbirchwood();
glPopMatrix();

//penyangga 3 (tengah)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,0);
drawbirchwood();
glPopMatrix();

//penyangga 4 (tengah)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,0);
drawbirchwood();
glPopMatrix();

//penyangga 5(belakang)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(-29,1.05,-29);
drawbirchwood();
glPopMatrix();

//penyangga 6 (belakang)
glPushMatrix();
glScalef(0.05,0.8,0.05);
glTranslatef(29,1.05,-29);
drawbirchwood();
glPopMatrix();

}

void drawrumput(){
glPushMatrix();
glScalef(3,0.08,3);
glTranslatef(0,-3,0);
KubusRumput();
glPopMatrix();
}


//garis bantu
void drawline(){
glBegin(GL_LINES);
glLineWidth(5);
glColor3f(1,0,0);
glVertex3f(-5,0,0);
glVertex3f(5,0,0);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(0,5,0);
glVertex3f(0,-5,0);
glEnd();
}

void drawatap(){
glPushMatrix();
glScalef(1.4,0.15,0.02);
glTranslatef(0,10,73);
KubusAtap();
glPopMatrix();

glPushMatrix();
glScalef(1.4,0.15,0.02);
glTranslatef(0,10,-73);
KubusAtap();
glPopMatrix();

glPushMatrix();
glRotatef(90, 0.0, 1.0, 0.0);
glScalef(0.75 - 0.05 - 0.025, 0.15, 0.02);
glTranslatef(-1.07, 10, 73);
KubusAtap();
glPopMatrix();

glPushMatrix();
glRotatef(90, 0.0, 1.0, 0.0);
glScalef(0.75 - 0.05 - 0.025, 0.15, 0.02);
glTranslatef(1.07, 10, 73);
KubusAtap();
glPopMatrix();

glPushMatrix();
glRotatef(-90, 0.0, 1.0, 0.0);
glScalef(0.75-0.05-0.025, 0.15, 0.02);
glTranslatef(-1.07 , 10, 73);
KubusAtap();
glPopMatrix();

glPushMatrix();
glRotatef(-90, 0.0, 1.0, 0.0); // Rotate around the y-axis
glScalef(0.75 - 0.025 - 0.05, 0.15, 0.02);
glTranslatef(1.07, 10, 73);
KubusAtap();
glPopMatrix();

//atap penutup atas
glPushMatrix();
glScalef(1.5,0.02,1.5);
glTranslatef(0,0.8/0.01+3,0);
KubusAtap();
glPopMatrix();

//balok atap tenagah
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,0);
KubusAtap();
glPopMatrix();

//balok atap depan
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
KubusAtap();
glPopMatrix();

//balok atap belakang
glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,-29);
KubusAtap();
glPopMatrix();

glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29/2);
KubusAtap();
glPopMatrix();

glPushMatrix();
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,-29/2);
KubusAtap();
glPopMatrix();

//balok kanan
glPushMatrix();
glRotatef(90,0,1,0);
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
KubusAtap();
glPopMatrix();

//balok kiri
glPushMatrix();
glRotatef(-90,0,1,0);
glScalef(2,0.05,0.05);
glTranslatef(0,0.8/0.025+2.5,29);
KubusAtap();
glPopMatrix();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(-3,3,7,
          0,0,0,
          0,1,0);

drawrumput();
drawlantai();
drawpenyangga();
drawatap();
drawline();
//drawcube();


glutSwapBuffers();
}

void reshape(int width, int height){
glClearColor(0,0,0,0);
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

glutMainLoop();
return 0;
}
