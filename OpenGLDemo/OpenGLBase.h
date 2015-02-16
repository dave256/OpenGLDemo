//
//  OpenGLBase.h
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#ifndef __Texture2D__OpenGLBase__
#define __Texture2D__OpenGLBase__

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <string>

class OpenGLBase {

public:
    OpenGLBase();

    //----------------------------------------------------------------------
    // callbacks to override in subclass

    /*! display callback called to update OpenGL window
     */
    virtual void displayCallback();

    /*! keyboard callback called when key pressed in OpenGL window
     * \param key ASCII value of key pressed
     * \param x x-coordinate of mouse pointer when key pressed
     * \param y y-coordinate of mouse pointer when key pressed
     */
    virtual void keyboardCallback(unsigned char key, int x, int y);

    /*! keyboard callback called when key released in OpenGL window
     * \param key ASCII value of key pressed
     * \param x x-coordinate of mouse pointer when key pressed
     * \param y y-coordinate of mouse pointer when key pressed
     */
    virtual void keyboardUpCallback(unsigned char key, int x, int y);

    /*! mouse callback called when mouse button pressed/released in OpenGL window
     * \param button - number for which mouse button was pressed
     * \param state - state of mouse button (GLUT_DOWN or GLUT_UP)
     * \param x x-coordinate of mouse pointer when button pressed/released
     * \param y y-coordinate of mouse pointer when button pressed/released
     */
    virtual void mouseCallback(int button, int state, int x, int y);

    /*! mouse callback when mouse pointer moved
     * \param x x-coordinate of mouse pointer
     * \param y y-coordinate of mouse pointer
     */
    virtual void motionCallback(int x, int y);

    /*! reshape callback when OpenGL window resized
     * \param width new width of OpenGL window
     * \param height new height of OpenGL window
     */
    virtual void reshapeCallback(int width, int height);

    static void timerFunc(int value);
    virtual void timerCallback(int value);

protected:
    GLuint _vao;

private:
    // static callbacks (do not override)
    static void displayFunc();
    static void keyboardFunc(unsigned char key, int x, int y);
    static void keyboardUpFunc(unsigned char key, int x, int y);
    static void mouseFunc(int button, int state, int x, int y);
    static void motionFunc(int x, int y);
    static void reshapeFunc(int w, int h);

};

#endif /* defined(__Texture2D__OpenGLBase__) */
