#ifndef GL_ABSTRACTION_PROGRAM
#define GL_ABSTRACTION_PROGRAM

class GlProgram {
    private:
        unsigned int id;
        const unsigned int errorLogSize;
        char* errorLog;
    public:
        GlProgram();
        void addShader(unsigned int shaderType, const char* sourceCode);
        char* getError();
        void compile();
        unsigned int getId();
        ~GlProgram();

};

#endif /* ifndef GLABSTRACTION_PROGRAM */
