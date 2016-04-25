//
// Created by Yuki miyatake on 2016/02/06.
//

#include "render.h"
#include <GLFW/glfw3.h>
#include "lib/math.h"

void init(){
    /*
    static GLfloat lightPosition[4] = { 0.25f, 1.0f, 0.25f, 0.0f };
    static GLfloat lightDiffuse[3] = { 1.0f, 1.0f, 1.0f };
    static GLfloat lightAmbient[3] = { 0.25f, 0.25f, 0.25f };
    static GLfloat lightSpecular[3] = { 1.0f, 1.0f, 1.0f };


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);




    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.5, 1.5, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
*/

    rabbit::vec2 v1;
    rabbit::vec2 v2;

    v2.x_ = 1;
    v2 += v1;
    v2 += 10;
    rabbit::vec2 v3 = v2;


}


void update(){


}


void render(){
    float ratio;
    /*
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
*/
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

}
