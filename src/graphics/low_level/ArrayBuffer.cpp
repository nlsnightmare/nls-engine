#include <GL/glew.h>
#include "ArrayBuffer.hpp"

ArrayBuffer::ArrayBuffer(){
}
ArrayBuffer::ArrayBuffer(void * data, int size)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

}

ArrayBuffer::~ArrayBuffer(){
    glDeleteBuffers(1, &m_id);
}

void ArrayBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void ArrayBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
