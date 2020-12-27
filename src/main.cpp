#include <iostream>

#include <GL/glew.h>   
#include "GLFW/glfw3.h"

#include <glAbstractions/program.hpp>
#include <utils/file.hpp>


int compileProgram() {
}

int main(void){
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(500, 500, "Testing OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        std::cout << "GLEW FAIL" << std::endl;
        return 123;
    }

    GLfloat vectors[] = {
        -0.5f, -0.5f,
        0.0f, 0.0f,
        0.5f, -0.5f

    };



    GlProgram program;

    File vShaderFile("../resources/shaders/vertexShader.glsl", TEXT_FILE);
    File fShaderFile("../resources/shaders/fragmentShader.glsl", TEXT_FILE);

    program.addShader(GL_VERTEX_SHADER, vShaderFile.getStringContent()->c_str());
    program.addShader(GL_FRAGMENT_SHADER, fShaderFile.getStringContent()->c_str());
    program.compile();

    std::cout << program.getError() << std::endl;

    glUseProgram(program.getId());

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vectors), vectors, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, (const void*)0); 
    glEnableVertexAttribArray(0);

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
