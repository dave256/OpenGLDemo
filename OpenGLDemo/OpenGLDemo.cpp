//
//  OpenGLDemo.cpp
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#include "Utils.h"
#include "OpenGLDemo.h"

#include "Angel.h"

using std::string;

//----------------------------------------------------------------------

OpenGLDemo::OpenGLDemo()
{

}

//----------------------------------------------------------------------

void OpenGLDemo::setup(std::string textureFilename)
{
    // black background
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // default draw as line loop
    _drawType = GL_LINE_LOOP;

    // set point size to 5 so easy to see
    glPointSize(5);

    size_t pos;

    // initialize points for triangle 0
    pos = 0;

    // specify x, y, r, g, b for each point
    // point 0
    _poly0[pos++] = -0.75;
    _poly0[pos++] = -0.75;
    _poly0[pos++] = 1.0;
    _poly0[pos++] = 0.0;
    _poly0[pos++] = 0.0;

    // point 1
    _poly0[pos++] = -0.25;
    _poly0[pos++] = -0.75;
    _poly0[pos++] = 1.0;
    _poly0[pos++] = 0.0;
    _poly0[pos++] = 0.0;

    // point 2
    _poly0[pos++] = -0.25;
    _poly0[pos++] = 0.5;
    _poly0[pos++] = 1.0;
    _poly0[pos++] = 0.0;
    _poly0[pos++] = 0.0;

    // initialize points for triangle 1
    pos = 0;

    // specify x, y, r, g, b for each point
    // point 0
    _poly1[pos++] = 0.0;
    _poly1[pos++] = -0.75;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 1.0;

    // point 1
    _poly1[pos++] = 0.5;
    _poly1[pos++] = -0.75;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 1.0;

    // point 2
    _poly1[pos++] = 0.5;
    _poly1[pos++] = 0.5;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 0.0;
    _poly1[pos++] = 1.0;


    // Create and initialize a buffer object
    // (cache data in graphics card memory)
    glGenBuffers(1, &_buffers[0]);
    glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GL_FLOAT), _poly0, GL_STATIC_DRAW);

    // Create and initialize a buffer object
    // (cache data in graphics card memory)
    glGenBuffers(1, &_buffers[1]);
    glBindBuffer(GL_ARRAY_BUFFER, _buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GL_FLOAT), _poly1, GL_STATIC_DRAW);

    string vshaderPath = "vshader.txt";
    string fshaderPath = "fshader.txt";
    vshaderPath = pathUsingEnvironmentVariable(vshaderPath, "GL_SHADER_DIR");
    fshaderPath = pathUsingEnvironmentVariable(fshaderPath, "GL_SHADER_DIR");
    _shaderProgram.makeProgramFromShaderFiles(vshaderPath, fshaderPath);
    _shaderProgram.useProgram();
}

//----------------------------------------------------------------------

void OpenGLDemo::loadTexture(std::string textureFilePath)
{
    
}

//----------------------------------------------------------------------

void OpenGLDemo::displayCallback()
{
    // clear the window
    glClear(GL_COLOR_BUFFER_BIT);


    // use one of the two sections of code to specify the data

    // get the integer location for the vPosition attribute
    // in the vertex shader
    GLuint vPosition = glGetAttribLocation(_shaderProgram.program(), "vPosition");
    // indicate we will be specifying this attribute using a vertex attribute array
    glEnableVertexAttribArray(vPosition);


    // section 1
    // buffer for first triangle
    glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);

    // specify the actual vertex data from the buffer
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));

    // draw the buffer for the first triangle
    glDrawArrays(_drawType, 0, 3);

    // draw the second triangle
    // switch to buffer for second triangle
    glBindBuffer(GL_ARRAY_BUFFER, _buffers[1]);

    // after glBindBuffer, must call glVertexAttribPointer again
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));

    // draw using the buffer for the second triangle
    glDrawArrays(_drawType, 0, 3);

    /*
     // section 2
     // specify buffer 0 to unbind
     glBindBuffer(GL_ARRAY_BUFFER, 0);

     // specify points for first triangle
     glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), _poly0);
     // draw it
     glDrawArrays(_drawType, 0, 3);

     // specify points for second triangle
     glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), _poly1);
     /// draw it
     glDrawArrays(_drawType, 0, 3);
     */

    // force display update
    glutSwapBuffers();
}


//----------------------------------------------------------------------

void OpenGLDemo::keyboardCallback(unsigned char key, int x, int y)
{
    switch( key ) {
        case 033: // Escape Key
        case 'q': case 'Q':
            exit(EXIT_SUCCESS);
            break;

        case 'l':
            _drawType = GL_LINE_LOOP;
            break;

        case 'f':
            _drawType = GL_TRIANGLES;
            break;

        case 'p':
            _drawType = GL_POINTS;
            break;
    }

    // redisplay the scene
    glutPostRedisplay();
}


//----------------------------------------------------------------------
