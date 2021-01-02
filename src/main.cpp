#include <iostream>
#include <vector>

#include <GL/glew.h>   
#include "GLFW/glfw3.h"

#include <glAbstractions/program.hpp>
#include <glAbstractions/vertexBuffer.hpp>
#include <utils/file.hpp>


void GLAPIENTRY messageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam){
    
    std::cout <<  message << std::endl;

}

int main(void){
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(500, 500, "Testing OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        std::cout << "GLEW FAIL" << std::endl;
        return 123;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);

    GlProgram program;

    File vShaderFile("../resources/shaders/vertexShader.glsl", TEXT_FILE);
    File fShaderFile("../resources/shaders/fragmentShader.glsl", TEXT_FILE);

    program.addShader(GL_VERTEX_SHADER, vShaderFile.getStringContent()->c_str());
    std::cout << program.getError() << std::endl;
    program.addShader(GL_FRAGMENT_SHADER, fShaderFile.getStringContent()->c_str());
    std::cout << program.getError() << std::endl;
    program.compile();


    glUseProgram(program.getId());


    float vectors[15] = {
       -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 
        0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 
        0.5f,  -0.5f, 1.0f, 0.0f, 0.0f, 

    };

    int layout[2] = {2, 3};
    VertexBuffer<float> vb(2, layout);
    vb.pushData(15, vectors);


    GLuint elements[] = {
        0,1,2//,3,4,5
    };

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);


    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        glfwSwapBuffers(window);
    }



    return 0;
}
