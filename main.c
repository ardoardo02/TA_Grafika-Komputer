#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>

const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah;

void initGL() {
    glClearColor(0.69, 0.89, 1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}


void lingkaran(GLfloat x_tengah, GLfloat y_tengah, GLfloat radius) {
    const double PI = 3.141592653589793;
    int i, jumlah_titik;

    glBegin(GL_POLYGON);
    jumlah_titik = 50;

    for (i = 0; i <= 90; i++) {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();
}

void kotak(GLfloat x, GLfloat y, GLfloat size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

//jendela
void jendela(GLfloat x, GLfloat y) {
    //bingkai
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.2);
    glVertex2f(x + 0.12, y + 0.2);
    glVertex2f(x + 0.12, y);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(x + 0.02, y + 0.02);
    glVertex2f(x + 0.02, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02);
    glEnd();

    //teralis vertical 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x + 0.02 + 0.025, y);
    glVertex2f(x + 0.02 + 0.025, y + 0.2);
    glEnd();

    //teralis vertical 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x + 0.02 + 0.055, y);
    glVertex2f(x + 0.02 + 0.055, y + 0.2);
    glEnd();

    //teralis horizontal 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y + 0.06);
    glVertex2f(x + 0.12, y + 0.06);
    glEnd();

    //teralis horizontal 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y + 0.10);
    glVertex2f(x + 0.12, y + 0.10);
    glEnd();

    //teralis horizontal 3
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y + 0.14);
    glVertex2f(x + 0.12, y + 0.14);
    glEnd();
}

//jendela tengah
void jendelaTengah(GLfloat x, GLfloat y) {
    //bingkai
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.2);
    glVertex2f(x + 0.12, y + 0.2);
    glVertex2f(x + 0.12, y);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(x + 0.02, y + 0.02);
    glVertex2f(x + 0.02, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02);
    glEnd();

    //teralis vertical 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(x + 0.02 + 0.025, y);
    glVertex2f(x + 0.02 + 0.025, y + 0.2);
    glEnd();

    //teralis vertical 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.02 + 0.055, y);
    glVertex2f(x + 0.02 + 0.055, y + 0.2);
    glEnd();

    //teralis horizontal 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.06);
    glVertex2f(x + 0.12, y + 0.06);
    glEnd();

    //teralis horizontal 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.10);
    glVertex2f(x + 0.12, y + 0.10);
    glEnd();

    //teralis horizontal 3
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.14);
    glVertex2f(x + 0.12, y + 0.14);
    glEnd();
}

// pintu
void pintu(GLfloat x, GLfloat y) {
    //bingkai
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.2);
    glVertex2f(x + 0.12, y + 0.2);
    glVertex2f(x + 0.12, y);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor3f(.4, .27, .02);
    glVertex2f(x + 0.02, y + 0.02);
    glVertex2f(x + 0.02, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02 + 0.16);
    glVertex2f(x + 0.02 + 0.08, y + 0.02);
    glEnd();

    //teralis vertical 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0, 0, 0);
    glVertex2f(x + 0.02 + 0.025, y);
    glVertex2f(x + 0.02 + 0.025, y + 0.2);
    glEnd();

    //teralis vertical 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.02 + 0.055, y);
    glVertex2f(x + 0.02 + 0.055, y + 0.2);
    glEnd();

    //teralis horizontal 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.06);
    glVertex2f(x + 0.12, y + 0.06);
    glEnd();

    //teralis horizontal 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.10);
    glVertex2f(x + 0.12, y + 0.10);
    glEnd();

    //teralis horizontal 3
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x, y + 0.14);
    glVertex2f(x + 0.12, y + 0.14);
    glEnd();

    //ventilasi 1
    glBegin(GL_QUADS);
    glColor3f(.4, .27, .02);
    glVertex2f(x + 0.015, y + 0.21);
    glVertex2f(x + 0.110, y + 0.21);
    glVertex2f(x + 0.110, y + 0.26);
    glVertex2f(x + 0.015, y + 0.26);
    glEnd();

    //garis ventilasi 1
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glColor3f(0, 0, 0);
    glVertex2f(x + 0.015, y + 0.21);
    glVertex2f(x + 0.110, y + 0.21);
    glEnd();

    //garis ventilasi 2
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.110, y + 0.26);
    glVertex2f(x + 0.015, y + 0.26);
    glEnd();

    //garis ventilasi 3
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.110, y + 0.21);
    glVertex2f(x + 0.110, y + 0.26);
    glEnd();

    //garis ventilasi 4
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.02 + 0.025, y + 0.21);
    glVertex2f(x + 0.02 + 0.025, y + 0.26);
    glEnd();

    //garis ventilasi 5
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.02 + 0.055, y + 0.21);
    glVertex2f(x + 0.02 + 0.055, y + 0.26);
    glEnd();

    //garis ventilasi 6
    glBegin(GL_LINES);
    glLineWidth(20.20);
    glVertex2f(x + 0.015, y + 0.21);
    glVertex2f(x + 0.015, y + 0.26);
    glEnd();
}

//atasan
void atasan(GLfloat x, GLfloat y) {
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.06);
    glVertex2f(x + 1.1, y - 0.06);
    glVertex2f(x + 1.1, y);
    glEnd();
}

//pilar
void pilar(GLfloat x, GLfloat y) {
    //tiang
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.9);
    glVertex2f(x + 0.1, y + 0.9);
    glVertex2f(x + 0.1, y);
    glEnd();

    //kerucut
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(x - 0.05, y + 0.9);
    glVertex2f(x, y + 1.0);
    glVertex2f(x + 0.1, y + 1.0);
    glVertex2f(x + 0.15, y + 0.9);
    glEnd();
}

//tiangtengah
void tiang(GLfloat x, GLfloat y) {
    glColor3f(0.98, 0.98, 0.98);
    lingkaran(x + .025, y, .05);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.75);
    glVertex2f(x + 0.05, y - 0.75);
    glVertex2f(x + 0.05, y);

    glVertex2f(x - .025, y - .75);
    glVertex2f(x - .025, y - .89);
    glVertex2f(x + .075, y - .89);
    glVertex2f(x + .075, y - .75);
    glEnd();
}

//cerobong
void cerobong1(GLfloat x, GLfloat y) {
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.25);
    glVertex2f(x + 0.1, y + 0.25);
    glVertex2f(x + 0.1, y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(x, y + 0.25);
    glVertex2f(x, y + 0.26);
    glVertex2f(x + 0.1, y + 0.26);
    glVertex2f(x + 0.1, y + 0.25);
    glEnd();
}

//cerobong2
void cerobong2(GLfloat x, GLfloat y) {
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.25);
    glVertex2f(x + 0.2, y + 0.25);
    glVertex2f(x + 0.2, y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(x, y + 0.25);
    glVertex2f(x, y + 0.26);
    glVertex2f(x + 0.2, y + 0.26);
    glVertex2f(x + 0.2, y + 0.25);
    glEnd();
}

void sannggahanAtap() {
    glColor3f(.975, .975, .975);
    //kiri
    kotak(-1.575, .4, .05);

    kotak(-1.5, .4, .025);
    kotak(-1.45, .4, .025);
    kotak(-1.4, .4, .025);
    kotak(-1.35, .4, .025);
    kotak(-1.3, .4, .025);
    kotak(-1.25, .4, .025);

    kotak(-1.2, .4, .05);

    kotak(-1.125, .4, .025);
    kotak(-1.075, .4, .025);
    kotak(-1.025, .4, .025);
    kotak(-.975, .4, .025);
    kotak(-.925, .4, .025);
    kotak(-.875, .4, .025);

    kotak(-.825, .4, .05);

    kotak(-.75, .4, .025);
    kotak(-.7, .4, .025);
    kotak(-.65, .4, .025);
    kotak(-.6, .4, .025);
    kotak(-.55, .4, .025);

    //kanan
    kotak(.525, .4, .025);
    kotak(.575, .4, .025);
    kotak(.625, .4, .025);
    kotak(.675, .4, .025);
    kotak(.725, .4, .025);

    kotak(.775, .4, .05);

    kotak(.85, .4, .025);
    kotak(.9, .4, .025);
    kotak(.95, .4, .025);
    kotak(1, .4, .025);
    kotak(1.05, .4, .025);
    kotak(1.1, .4, .025);

    kotak(1.15, .4, .05);

    kotak(1.225, .4, .025);
    kotak(1.275, .4, .025);
    kotak(1.325, .4, .025);
    kotak(1.375, .4, .025);
    kotak(1.425, .4, .025);
    kotak(1.475, .4, .025);

    kotak(1.525, .4, .05);

    glBegin(GL_QUADS);
    glVertex2f(-1.575, .425);
    glVertex2f(1.525, .425);
    glVertex2f(1.525, .45);
    glVertex2f(-1.575, .45);
    glEnd();
}

void tangga() {
    glBegin(GL_QUADS);

    glColor3f(.91, .91, .91);
    glVertex2f(-.45, -0.445);
    glVertex2f(-.45, -0.415);
    glVertex2f(.45, -0.415);
    glVertex2f(.45, -0.445);

    glColor3f(.86, .86, .86);
    glVertex2f(-.45, -0.445);
    glVertex2f(-.45, -0.43);
    glVertex2f(.45, -0.43);
    glVertex2f(.45, -0.445);

    glColor3f(.92, .92, .92);
    glVertex2f(-.45, -0.475);
    glVertex2f(-.45, -0.445);
    glVertex2f(.45, -0.445);
    glVertex2f(.45, -0.475);

    glColor3f(.87, .87, .87);
    glVertex2f(-.45, -0.475);
    glVertex2f(-.45, -0.46);
    glVertex2f(.45, -0.46);
    glVertex2f(.45, -0.475);

    glColor3f(.92, .92, .92);
    glVertex2f(-.15, -0.475);
    glVertex2f(-.15, -0.39);
    glVertex2f(.15, -0.39);
    glVertex2f(.15, -0.475);

    glEnd();
}

void lampu() {
    glBegin(GL_QUADS);

    glColor3f(0.1, 0.1, 0.1);

    glVertex2f(-.004, .03);
    glVertex2f(-.004, .4);
    glVertex2f(.004, .4);
    glVertex2f(.004, .03);

    glVertex2f(-.04, -.07);
    glVertex2f(-.04, .03);
    glVertex2f(.04, .03);
    glVertex2f(.04, -.07);

    glColor3f(.76, .77, .47);

    glVertex2f(-.03, -.06);
    glVertex2f(-.03, .02);
    glVertex2f(.0305, .02);
    glVertex2f(.0305, -.06);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.1, 0.1, 0.1);

    glVertex2f(-.015, -.065);
    glVertex2f(-.015, .025);

    glVertex2f(.016, -.065);
    glVertex2f(.016, .025);
    glEnd();
}

void pilarujung(GLfloat x, GLfloat y) {
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.1);
    glVertex2f(x + 0.1, y + 0.1);
    glVertex2f(x + 0.1, y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(x + 0.1, y + 0.1);
    glVertex2f(x - 0.05 + 0.1, y + 0.1 + 0.05);
    glVertex2f(x, y + 0.1);
    glEnd();
}

void garismerahbendera(GLfloat x, GLfloat y) {
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.007);
    glVertex2f(x + 0.2, y + 0.007);
    glVertex2f(x + 0.2, y);
    glEnd();
}

void grass() {
    glBegin(GL_QUADS);
    glColor3f(.33, .58, .27);
    glVertex2f(-2, -1);
    glVertex2f(-2, -.2);
    glVertex2f(2, -.2);
    glVertex2f(2, -1);
    glEnd();
}

void sky() {
    glBegin(GL_QUADS);
    glColor3f(.69, .89, 1);
    glVertex2f(-2, 1);
    glVertex2f(2, 1);
    glColor3f(.88, .96, 1);
    glVertex2f(2, -.5);
    glVertex2f(-2, -.5);
    glEnd();
}

void road() {
    glBegin(GL_POLYGON); //tengah & kanan
    glColor3f(.6, .6, .6);
    glVertex2f(1.5, -.6);
    glVertex2f(2, -.75);
    glVertex2f(2, -.95);
    glVertex2f(1.5, -.8);
    glVertex2f(.6, -.65);
    glVertex2f(-.6, -.65);
    glVertex2f(-.6, -.45);
    glVertex2f(.6, -.45);
    glEnd();
    glBegin(GL_POLYGON); //kiri
    glColor3f(.6, .6, .6);
    glVertex2f(-1.5, -.8);
    glVertex2f(-2, -.95);
    glVertex2f(-2, -.75);
    glVertex2f(-1.5, -.6);
    glVertex2f(-.6, -.45);
    glVertex2f(-.6, -.65);
    glEnd();
}

//ornamen segitiga
void ornamensegitiga(GLfloat x, GLfloat y) {
    glBegin(GL_TRIANGLES);
    glColor3f(0.97, 0.97, 0.97);
    glVertex2f(x, y);
    glVertex2f(x + 0.10, y + 0.06);
    glVertex2f(x + 0.20, y);
    glEnd();
}

//ornamen 1/3 lingkaran
void ornamensepertigalingkaran(GLfloat x, GLfloat y, GLfloat a, GLfloat b, GLfloat c) {
    glColor3f(0.97, 0.97, 0.97);
    glBegin(GL_POLYGON);
    radius = c;
    jumlah_titik = 60;
    x_tengah = a;
    y_tengah = b;


    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex2f(x / 100, y / 100);
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(x, y);
    glVertex2f(x + 0.28, y);
    glVertex2f(x + 0.28, y - 0.17);
    glVertex2f(x, y - 0.17);
    glEnd();
}

void ornamensepertigalingkarantengah(GLfloat x, GLfloat y, GLfloat a, GLfloat b, GLfloat c) {

    glColor3f(0.87, 0.87, 0.87);
    glBegin(GL_POLYGON);
    radius = c;
    jumlah_titik = 60;
    x_tengah = a;
    y_tengah = b;


    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex2f(x / 100, y / 100);
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(x, y);
    glVertex2f(x + 0.28, y);
    glVertex2f(x + 0.28, y - 0.17);
    glVertex2f(x, y - 0.17);
    glEnd();
}

void fountain() {
    glBegin(GL_QUADS); //tengah
    glColor3f(.775, .775, .775);
    glVertex2f(.5, -.775);
    glVertex2f(.5, -.8);
    glVertex2f(-.5, -.8);
    glVertex2f(-.5, -.775);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.7, .7, .7);
    glVertex2f(.5, -.8);
    glVertex2f(.5, -.85);
    glVertex2f(-.5, -.85);
    glVertex2f(-.5, -.8);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(.775, .775, .775);
    glVertex2f(.5, -.775);
    glVertex2f(.5, -.8);
    glVertex2f(1, -1.1);
    glVertex2f(1, -1.075);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.7, .7, .7);
    glVertex2f(.5, -.8);
    glVertex2f(.5, -.85);
    glVertex2f(1, -1.15);
    glVertex2f(1, -1.1);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(.775, .775, .775);
    glVertex2f(-.5, -.775);
    glVertex2f(-.5, -.8);
    glVertex2f(-1, -1.1);
    glVertex2f(-1, -1.075);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.7, .7, .7);
    glVertex2f(-.5, -.8);
    glVertex2f(-.5, -.85);
    glVertex2f(-1, -1.15);
    glVertex2f(-1, -1.1);
    glEnd();

    glBegin(GL_QUADS); //air
    glColor3f(.07, .82, .65);
    glVertex2f(-.5, -.85);
    glVertex2f(.5, -.85);
    glVertex2f(1, -1.15);
    glVertex2f(-1, -1.15);
    glEnd();
}

void bush(GLfloat x, GLfloat y) {
    glColor3f(.36, .71, .28);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + .2, y);
    glVertex2f(x + .2, y + .05);
    glVertex2f(x, y + .05);
    glEnd();

    lingkaran(x, y + .05, .05);
    lingkaran(x + .075, y + .075, .07);
    lingkaran(x + .15, y + .1, .05);
    lingkaran(x + .2, y + .06, .06);
}

void tanaman() {
    bush(-1.525, -0.44);
    bush(-1.15, -0.44);
    bush(-0.775, -0.44);
    bush(1.31, -0.44);
    bush(.935, -0.44);
    bush(0.56, -0.44);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //sky
    sky();

    //grass
    grass();

    //road
    road();

    //air mancur
    fountain();

    //bangunan dasar
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(-1.6, -0.4);
    glVertex2f(-1.6, 0.4);
    glVertex2f(1.6, 0.4);
    glVertex2f(1.6, -0.4);
    glEnd();

    pilarujung(-1.5, 0.4);
    pilarujung(1.4, 0.4);

    //cerobong kiri & kanan
    cerobong1(-0.8, 0.515);
    cerobong1(0.7, 0.515);

    //Atap pertama
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(-1.08, 0.4);
    glVertex2f(-1.08, 0.465);
    glVertex2f(1.08, 0.465);
    glVertex2f(1.08, 0.4);
    glEnd();

    //pinggiran atap
    sannggahanAtap();

    //Atap kedua
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(-1.2, 0.465);
    glVertex2f(-1.2, 0.485);
    glVertex2f(1.2, 0.485);
    glVertex2f(1.2, 0.465);
    glEnd();

    //atap
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-1.2, 0.485);
    glVertex2f(-1, 0.615);
    glVertex2f(1, 0.615);
    glVertex2f(1.2, 0.485);
    glEnd();

    //bangunan tengah
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-0.5, -0.45);
    glVertex2f(-0.5, 0.45);
    glVertex2f(0.5, 0.45);
    glVertex2f(0.5, -0.45);
    glEnd();

    //bangunan atas
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(-0.62, 0.5);
    glVertex2f(-0.62, 0.7);
    glVertex2f(0.62, 0.7);
    glVertex2f(0.62, 0.5);
    glEnd();

    //alas bangunan atas
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(-0.645, 0.7);
    glVertex2f(-0.645, 0.72);
    glVertex2f(0.645, 0.72);
    glVertex2f(0.645, 0.7);
    glEnd();

    //bendera
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.85);
    glVertex2f(0.0, 0.934);
    glVertex2f(0.2, 0.934);
    glVertex2f(0.2, 0.85);
    glEnd();

    garismerahbendera(0.0, 0.85);
    garismerahbendera(0.0, 0.864);
    garismerahbendera(0.0, 0.878);
    garismerahbendera(0.0, 0.892);
    garismerahbendera(0.0, 0.906);
    garismerahbendera(0.0, 0.92);
    garismerahbendera(0.0, 0.934);

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(0.0, 0.892);
    glVertex2f(0.0, 0.941);
    glVertex2f(0.08, 0.941);
    glVertex2f(0.08, 0.892);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2f(0.075, 0.895);
    glVertex2f(0.055, 0.895);
    glVertex2f(0.035, 0.895);
    glVertex2f(0.015, 0.895);

    glVertex2f(0.065, 0.9);
    glVertex2f(0.045, 0.9);
    glVertex2f(0.025, 0.9);
    glVertex2f(0.005, 0.9);

    glVertex2f(0.075, 0.905);
    glVertex2f(0.055, 0.905);
    glVertex2f(0.035, 0.905);
    glVertex2f(0.015, 0.905);

    glVertex2f(0.065, 0.910);
    glVertex2f(0.045, 0.910);
    glVertex2f(0.025, 0.910);
    glVertex2f(0.005, 0.910);

    glVertex2f(0.075, 0.915);
    glVertex2f(0.055, 0.915);
    glVertex2f(0.035, 0.915);
    glVertex2f(0.015, 0.915);

    glVertex2f(0.065, 0.920);
    glVertex2f(0.045, 0.920);
    glVertex2f(0.025, 0.920);
    glVertex2f(0.005, 0.920);

    glVertex2f(0.075, 0.925);
    glVertex2f(0.055, 0.925);
    glVertex2f(0.035, 0.925);
    glVertex2f(0.015, 0.925);

    glVertex2f(0.065, 0.930);
    glVertex2f(0.045, 0.930);
    glVertex2f(0.025, 0.930);
    glVertex2f(0.005, 0.930);

    glVertex2f(0.075, 0.935);
    glVertex2f(0.055, 0.935);
    glVertex2f(0.035, 0.935);
    glVertex2f(0.015, 0.935);
    glEnd();

    //tiang benderaa
    glBegin(GL_QUADS);
    glColor3f(0.92, 0.92, 0.92);
    glVertex2f(0.005, 0.7);
    glVertex2f(0.005, 0.941);
    glVertex2f(-0.005, 0.941);
    glVertex2f(-0.005, 0.7);
    glEnd();

    //cerobong tengah
    cerobong2(-0.55, 0.5);
    cerobong2(0.35, 0.5);

    //atap segitiga luar
    glBegin(GL_TRIANGLES);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(-0.6, 0.5);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.0, 0.75);
    glEnd();

    //atap segitiga dalam
    glBegin(GL_TRIANGLES);
    glColor3f(0.93, 0.93, 0.93);
    glVertex2f(-0.50, 0.52);
    glVertex2f(0.50, 0.52);
    glVertex2f(0.0, 0.73);
    glEnd();
    glColor3f(0.85, 0.85, 0.85);
    kotak(-0.44, 0.535, .025);
    kotak(-0.36, 0.565, .025);
    kotak(-0.28, 0.6, .025);
    kotak(-0.20, 0.635, .025);
    kotak(-0.12, 0.665, .025);
    kotak(0.088, 0.665, .025);
    kotak(0.168, 0.635, .025);
    kotak(0.248, 0.6, .025);
    kotak(0.328, 0.565, .025);
    kotak(0.408, 0.535, .025);

    //atasan atap segitiga luar kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(-0.6, 0.5);
    glVertex2f(0.0, 0.75);
    glVertex2f(0.0, 0.77);
    glVertex2f(-0.64, 0.5);
    glEnd();

    //atasan atap segitiga luar kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.0, 0.75);
    glVertex2f(0.0, 0.77);
    glVertex2f(0.64, 0.5);
    glEnd();

    //ornamensegitiga
    ornamensegitiga(-0.74, -0.08);
    ornamensegitiga(-1.24, -0.08);
    ornamensegitiga(0.54, -0.08);
    ornamensegitiga(1.04, -0.08);

    //ornamen 1/3 lingkaran
    ornamensepertigalingkaran(-1.03, -0.08, -89, -11, 11);
    ornamensepertigalingkaran(-1.53, -0.08, -139, -11, 11);
    ornamensepertigalingkaran(0.75, -0.08, 89, -11, 11);
    ornamensepertigalingkaran(1.25, -0.08, 139, -11, 11);
    //ornamen 1/3 lingkaran tengah
    ornamensepertigalingkarantengah(-0.465, -0.08, -33, -11, 11);
    ornamensepertigalingkarantengah(0.185, -0.08, 33, -11, 11);
    ornamensepertigalingkarantengah(-0.13, -0.1, 0, -14, 13);


    //jendela bagian kanan atas
    jendela(0.58, 0.1);
    jendela(0.83, 0.1);
    jendela(1.08, 0.1);
    jendela(1.33, 0.1);

    //jendela bagian kanan bawah
    jendela(0.58, -0.3);
    jendela(0.83, -0.3);
    jendela(1.08, -0.3);
    jendela(1.33, -0.3);

    //jendela bagian kiri atas
    jendela(-0.7, 0.1);
    jendela(-0.95, 0.1);
    jendela(-1.2, 0.1);
    jendela(-1.45, 0.1);

    //jendela bagian kiri bawah
    jendela(-0.7, -0.3);
    jendela(-0.95, -0.3);
    jendela(-1.2, -0.3);
    jendela(-1.45, -0.3);

    //atasan kiri
    atasan(-1.6, 0.4);
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(-1.6, 0.385);
    glVertex2f(-.5, 0.385);
    glVertex2f(-.5, 0.4);
    glVertex2f(-1.625, 0.4);
    glEnd();

    //atasan kanan
    atasan(0.5, 0.4);
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(1.6, 0.385);
    glVertex2f(.5, 0.385);
    glVertex2f(.5, 0.4);
    glVertex2f(1.625, 0.4);

    //jendela tengah atas
    jendelaTengah(-0.385, 0.1);
    jendelaTengah(-0.06, 0.1);
    jendelaTengah(0.265, 0.1);

    //jendela tengah bawah
    jendelaTengah(-0.385, -0.3);
    jendelaTengah(0.265, -0.3);

    //lampu
    lampu();

    //atasan tengah
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(-0.5, 0.45);
    glVertex2f(-0.5, 0.45 - 0.06);
    glVertex2f(-0.5 + 1.0, 0.45 - 0.06);
    glVertex2f(-0.5 + 1.0, 0.45);
    glEnd();

    //sambungan atasan tengah
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(-0.5, 0.45);
    glVertex2f(-0.5 + 1.0, 0.45);
    glVertex2f(-0.5 + 1.03, 0.45 + 0.05);
    glVertex2f(-0.5 - 0.03, 0.45 + 0.05);
    glEnd();
    glColor3f(0.93, 0.93, 0.93);
    kotak(-0.49, 0.47, .025);
    kotak(-0.44, 0.47, .025);
    kotak(-0.39, 0.47, .025);
    kotak(-0.34, 0.47, .025);
    kotak(-0.29, 0.47, .025);
    kotak(-0.24, 0.47, .025);
    kotak(-0.19, 0.47, .025);
    kotak(-0.14, 0.47, .025);
    kotak(-0.09, 0.47, .025);
    kotak(-0.04, 0.47, .025);
    kotak(0.01, 0.47, .025);
    kotak(0.06, 0.47, .025);
    kotak(0.11, 0.47, .025);
    kotak(0.16, 0.47, .025);
    kotak(0.21, 0.47, .025);
    kotak(0.26, 0.47, .025);
    kotak(0.31, 0.47, .025);
    kotak(0.36, 0.47, .025);
    kotak(0.41, 0.47, .025);
    kotak(0.46, 0.47, .025);

    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.12, -0.35);
    glVertex2f(-0.1, -0.3);
    glVertex2f(0, -0.3);
    glVertex2f(0, -0.35);
    glEnd();
    pintu(-0.12, -0.39);
    pintu(0, -0.39);

    //tangga
    tangga();

    //tanaman
    tanaman();

    //tiang tengah
    tiang(-0.5, 0.4);
    tiang(-0.2, 0.4);
    tiang(0.15, 0.4);
    tiang(0.45, 0.4);

    glFlush();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(1400, 700);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Gedung Putih US");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    initGL();
    glutMainLoop();

    return 0;
}
