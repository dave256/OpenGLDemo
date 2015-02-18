//
//  ShaderProgram.h
//  
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#ifndef __Texture2D__ShaderProgram__
#define __Texture2D__ShaderProgram__


#ifdef __APPLE__
//#include <GL/glew.h>
#include <OpenGL/gl.h>
#else
#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <string>

class ShaderProgram {

public:
    ShaderProgram();
    void makeProgramFromShaderFiles(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
    void makeProgramFromShaders(std::string vertexShader, std::string fragmentShader);

    void compileShader(std::string shaderCode, GLenum shaderType);

    GLuint program() { return _program; }
    void useProgram() { glUseProgram(_program); }

protected:
    GLuint _program;
};

#endif /* defined(__Texture2D__ShaderProgram__) */
