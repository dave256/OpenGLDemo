//
//  ShaderProgram.cpp
//  Texture2D
//
//  Created by David Reed on 2/15/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#include "ShaderProgram.h"

#include <iostream>

using std::cerr;
using std::endl;
using std::string;

#include "Utils.h"

//----------------------------------------------------------------------

ShaderProgram::ShaderProgram()
{
    _program = 0;
}

//----------------------------------------------------------------------

void ShaderProgram::makeProgramFromShaderFiles(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
{
    string vertexShader = contentsOfFile(vertexShaderFilePath);
    string fragmentShader = contentsOfFile(fragmentShaderFilePath);
    makeProgramFromShaders(vertexShader, fragmentShader);
}

//----------------------------------------------------------------------

void ShaderProgram::makeProgramFromShaders(std::string vertexShader, std::string fragmentShader)
{
    _program = glCreateProgram();

    compileShader(vertexShader, GL_VERTEX_SHADER);
    compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    // link  and error check
    glLinkProgram(_program);
    GLint linked;
	glGetProgramiv(_program, GL_LINK_STATUS, &linked);

    if (!linked) {
        std::cerr << "Shader program failed to link" << std::endl;
        GLint  logSize;
        glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetProgramInfoLog(_program, logSize, NULL, logMsg);
        std::cerr << logMsg << std::endl;
        delete [] logMsg;
    }
}

//----------------------------------------------------------------------

void ShaderProgram::compileShader(std::string shaderCode, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    const char *shaderString = shaderCode.c_str();
    glShaderSource(shader, 1, (const GLchar *const *)&shaderString, NULL);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        cerr << "Failed to compile shader code:\n\n" << shaderCode << endl;
        GLint  logSize;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        char* logMsg = new char[logSize];
        glGetShaderInfoLog( shader, logSize, NULL, logMsg);
        std::cerr << logMsg << std::endl;
        delete [] logMsg;
        return;
    }
    glAttachShader(_program, shader);
    glDeleteShader(shader);
}

//----------------------------------------------------------------------
