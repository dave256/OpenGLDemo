//
//  OpenGLBase.cpp
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#include <cstdlib>

#include "OpenGLBase.h"

using std::string;

extern OpenGLBase *openGLBase;

//----------------------------------------------------------------------

OpenGLBase::OpenGLBase()
{
    // GLUT callbacks
    glutDisplayFunc(&OpenGLBase::displayFunc);
    glutKeyboardFunc(&OpenGLBase::keyboardFunc);
    glutKeyboardUpFunc(&OpenGLBase::keyboardUpFunc);
    glutMouseFunc(&OpenGLBase::mouseFunc);
    glutReshapeFunc(&OpenGLBase::reshapeFunc);
    glutMotionFunc(&OpenGLBase::motionFunc);

    // Create a vertex array object
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
}

//----------------------------------------------------------------------

void OpenGLBase::displayFunc()
{
    openGLBase->displayCallback();
}

//----------------------------------------------------------------------

void OpenGLBase::keyboardFunc(unsigned char key, int x, int y)
{
    openGLBase->keyboardCallback(key, x, y);
}

//----------------------------------------------------------------------

void OpenGLBase::keyboardUpFunc(unsigned char key, int x, int y)
{
    openGLBase->keyboardUpCallback(key, x, y);
}

//----------------------------------------------------------------------

void OpenGLBase::mouseFunc(int button, int state, int x, int y)
{
    openGLBase->mouseCallback(button, state, x, y);
}

//----------------------------------------------------------------------

void OpenGLBase::motionFunc(int x, int y)
{
    openGLBase->motionCallback(x, y);
}

//----------------------------------------------------------------------

void OpenGLBase::reshapeFunc(int w, int h)
{
    openGLBase->reshapeCallback(w, h);
}
//----------------------------------------------------------------------

void OpenGLBase::timerFunc(int value)
{
    openGLBase->timerCallback(value);
}

//----------------------------------------------------------------------

void OpenGLBase::displayCallback()
{
    // set to background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

//----------------------------------------------------------------------

void OpenGLBase::keyboardCallback(unsigned char key, int x, int y)
{
    switch( key ) {
        case 033: // Escape Key
        case 'q': case 'Q':
            exit(EXIT_SUCCESS);
            break;
    }
}

//----------------------------------------------------------------------

void OpenGLBase::keyboardUpCallback(unsigned char key, int x, int y)
{

}

//----------------------------------------------------------------------

void OpenGLBase::mouseCallback(int button, int state, int x, int y)
{

}

//----------------------------------------------------------------------

void OpenGLBase::motionCallback(int x, int y)
{

}

//----------------------------------------------------------------------

void OpenGLBase::reshapeCallback(int w, int h)
{

}

//----------------------------------------------------------------------

void OpenGLBase::timerCallback(int value)
{

}

//----------------------------------------------------------------------

