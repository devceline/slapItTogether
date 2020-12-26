#include <iostream>
#include <GL/glew.h>   
#include "GLFW/glfw3.h"

int main(void){
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(500, 500, "Testing OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        std::cout << "GLEW FAIL" << std::endl;
        return 123;
    }

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        if(GLFW_KEY_Q == GLFW_KEY_DOWN){
            glfwSetWindowShouldClose(window, 1);
        }
        glfwSwapBuffers(window);
    }



    return 0;
}
