#include "StaticShader.h"

#include <GL/glew.h>
#include <iostream>

StaticShader::StaticShader() : IShaderProgram(false, true){

}

StaticShader::~StaticShader(){

}

void StaticShader::construct() {
    loadShader("./shaders/static.vert", GL_VERTEX_SHADER);
    loadShader("./shaders/static.frag", GL_FRAGMENT_SHADER);
    setTransform("transform");
    setProjection("projection");
}

void StaticShader::bindAttributes() {
    bindAttribute(0, "position");
    bindAttribute(1, "color");
    bindAttribute(3, "normal");
}

void StaticShader::loadStaticUniforms() {
    loadVecU(getUniformLocation("lightColor"), glm::vec3(1.0f, 1.0f, 1.0f));
    loadVecU(getUniformLocation("lightPos"), glm::vec3(0.0f, 0.0f, 0.0f));
}
