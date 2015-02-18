//
//  main.cpp
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#ifndef __APPLE__
#include <GL/glew.h>
#endif


#include <iostream>

#include "OpenGLDemo.h"

using std::cerr;
using std::endl;

// must declare as OpenGLBase for Windows
OpenGLBase *openGLBase;

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(30, 60);
    glutCreateWindow("OpenGL Texture");

#ifndef __APPLE__
    //glewExperimental = GL_TRUE
    GLenum err = glewInit();

    if (err != GLEW_OK) {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
        return -1;
    }
#endif

    // print out some info about the graphics drivers
    cerr << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    cerr << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    cerr << "Vendor: " << glGetString(GL_VENDOR) << endl;
    cerr << "Renderer: " << glGetString(GL_RENDERER) << endl;
    GLint textureUnits;
    glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &textureUnits);
    cerr << "Num texture units: " << textureUnits << endl;

    OpenGLDemo *scene = new OpenGLDemo;
    openGLBase = scene;

    scene->setup("");

    glutMainLoop();
    delete openGLBase;

    return 0;
}
