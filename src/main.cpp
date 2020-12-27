#include <iostream>

#include <GL/glew.h>   
#include "GLFW/glfw3.h"

#include <utils/file.hpp>




int compileProgram() {

    std::cout << "Compiling program..." << std::endl;;

    int vShader = glCreateShader(GL_VERTEX_SHADER);
    int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    int program = glCreateProgram();

    File vShaderFile("../resources/shaders/vertexShader.glsl", TEXT_FILE);
    File fShaderFile("../resources/shaders/fragmentShader.glsl", TEXT_FILE);

    const char* vShaderSource = vShaderFile.getStringContent()->c_str();
    const char* vSources[] = {vShaderSource};
    int vSourceLengths[] = {static_cast<int>(vShaderFile.getStringContent()->length())};
    glShaderSource(vShader, 1, vSources, vSourceLengths);
    glCompileShader(vShader);

    const char* fShaderSource = fShaderFile.getStringContent()->c_str();
    const char* fSources[] = {fShaderSource};
    int fSourceLengths[] = {static_cast<int>(fShaderFile.getStringContent()->length())};
    glShaderSource(fShader, 1, fSources, fSourceLengths);
    glCompileShader(fShader);

    int size;
    char info[256];
    glGetShaderInfoLog(vShader, 256, &size, info);
    std::cout << info << std::endl;

    glGetShaderInfoLog(fShader, 256, &size, info);
    std::cout << info << std::endl;

    glAttachShader(program, vShader);
    glAttachShader(program, fShader);

    glLinkProgram(program);

    return program;
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

    int program = compileProgram();
    glUseProgram(program);

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
