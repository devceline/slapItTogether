
#ifndef GL_ABSTRACTION_VERTEX_BUFFER
#define GL_ABSTRACTION_VERTEX_BUFFER 

#include <vector>
#include <GL/glew.h>

#include <iostream>

template<typename T>
class VertexBuffer {
    private:
        unsigned int id;
        unsigned int vertexElementCount;
        const unsigned int glType;
        std::vector<T> data;
        unsigned int attribCounter;

    public:
        VertexBuffer(unsigned int attribCount, int* attribArray);

        const unsigned int getType() {
            return this->glType;
        }

        const unsigned int getId() {
            return this->id;
        }

        const void bind() {
            glBindBuffer(GL_ARRAY_BUFFER, this->getId());
        }

        void pushData(unsigned int count, T* data);

        

};


#endif /* ifndef GL_ABSTRACTION_VERTEX_BUFFER */
