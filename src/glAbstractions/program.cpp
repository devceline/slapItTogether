#include <glAbstractions/program.hpp>
#include <GL/glew.h>

GlProgram::GlProgram() :
    id(glCreateProgram()), errorLogSize(256)
{
    errorLog = new char[errorLogSize];
}

void GlProgram::addShader(unsigned int shaderType, const char* sourceCode){
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &sourceCode, nullptr);
    glCompileShader(shader);
    glAttachShader(this->id, shader);
    glGetShaderInfoLog(shader, this->errorLogSize, nullptr, this->errorLog);
}

char* GlProgram::getError() {
    return this->errorLog;
}

void GlProgram::compile() {
    glLinkProgram(this->id);
}

void GlProgram::use(){
    glUseProgram(this->id);
}

const unsigned int GlProgram::getId() {
    return this->id;
}

GlProgram::~GlProgram() {
    glDeleteProgram(this->id);
    delete errorLog;
}
