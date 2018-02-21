#include "VertexArray.hpp"
#include <iostream>

VertexArray::~VertexArray(){
    delete m_vbo;
    delete m_ibo;
}


VertexArray::VertexArray(vertData* data, int count, unsigned int* indicies, int ind_count){
    glGenVertexArrays(1, &m_id);    		     
    glBindVertexArray(m_id);
    m_vbo = new ArrayBuffer(data, count * sizeof(vertData));
    m_ibo = new IndexBuffer(indicies, sizeof(unsigned int) * ind_count );

    m_vbo->Bind();
    m_ibo->Bind();
}

VertexArray::VertexArray(ArrayBuffer& vbo, IndexBuffer& ibo){
    glGenVertexArrays(1, &m_id);    		     
    glBindVertexArray(m_id);
    m_vbo = &vbo;
    m_ibo = &ibo;


    m_vbo->Bind();
    m_ibo->Bind();
}

void VertexArray::Bind() const {
    glBindVertexArray(m_id);
    // X,Y
    glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // S, T
    glVertexAttribPointer(1,2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2*sizeof(float)));
    glEnableVertexAttribArray(1);
}
void VertexArray::Unbind() const {
    glBindVertexArray(0);
}
