//
//  OpenGLDemo.h
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#ifndef __Texture2D__OpenGLDemo__
#define __Texture2D__OpenGLDemo__

#include "ShaderProgram.h"
#include "OpenGLBase.h"

class OpenGLDemo : public OpenGLBase {

public:
    OpenGLDemo();

    virtual void displayCallback();
    virtual void keyboardCallback(unsigned char key, int x, int y);

    void setup(std::string textureFilePath);
    void loadTexture(std::string textureFilePath);

protected:
    ShaderProgram _shaderProgram;

    // type for how to draw the data
    GLenum _drawType;

    // buffer IDs
    GLuint _buffers[2];

    // data for polygon 0
    GLfloat _poly0[15];

    // data for polygon 1
    GLfloat _poly1[15];
};

#endif /* defined(__Texture2D__OpenGLDemo__) */
