#ifndef GL_ABSTRACTION_PROGRAM
#define GL_ABSTRACTION_PROGRAM

class GlProgram {
    private:
        const unsigned int id;
        const unsigned int errorLogSize;
        char* errorLog;
    public:
        GlProgram();
        const unsigned int getId();
        void addShader(unsigned int shaderType, const char* sourceCode);
        void use();
        char* getError();
        void compile();
        ~GlProgram();

};

#endif /* ifndef GLABSTRACTION_PROGRAM */
