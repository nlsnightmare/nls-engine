#pragma once
#include <GL/glew.h>
#include "ArrayBuffer.hpp"
#include "ArrayBuffer.hpp"
#include "IndexBuffer.hpp"

class VertexArray
{
public:
    VertexArray(vertData * data, int count, unsigned int* indicies, int ind_count);
    VertexArray(ArrayBuffer& vbo, IndexBuffer& ibo);
    virtual ~VertexArray();		    

    void Bind() const;
    void Unbind() const;
    
private:
    unsigned int m_id;
    ArrayBuffer* m_vbo;
    IndexBuffer* m_ibo;

};
