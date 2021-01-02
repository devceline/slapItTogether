#include <glAbstractions/vertexBuffer.hpp>
#include <GL/glew.h>

#include <iostream>

template<>
VertexBuffer<float>::VertexBuffer(unsigned int attribCount, int* attribArray):
    glType(GL_FLOAT), vertexElementCount(0)
{
    glGenBuffers(1, &id);
    this->bind();

    unsigned int sum = 0;
    for(int i = 0; i < attribCount; ++i){
        if(attribArray[i] < 0){
            sum += attribArray[i] * -1;
        }
        else sum += attribArray[i];
    }

    int accumalatedByteCount = 0;
    for(int i = 0; i < attribCount; ++i){
        int attrib;
        GLboolean needsNormalization = GL_FALSE;
        
        if(attribArray[i] < 0){
            needsNormalization = GL_TRUE;
            attrib = attribArray[i] * -1;
        }
        else attrib = attribArray[i];

        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
                i, attrib, 
                this->getType(), needsNormalization, 
                sizeof(float) * sum,
                (const void*) accumalatedByteCount
        );

        vertexElementCount += attribArray[i];
        accumalatedByteCount = attribArray[i] * sizeof(float);
    }

    std::cout << "SUM: " << sum << '\n' << "BYTE COUNT: " << accumalatedByteCount << std::endl;


}

template<>
void VertexBuffer<float>::pushData(unsigned int count, float* data){
    this->bind();
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
}
    




