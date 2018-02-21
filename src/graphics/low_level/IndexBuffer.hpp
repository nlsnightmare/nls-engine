#pragma once

class IndexBuffer
{
public:
    IndexBuffer();
    IndexBuffer(void * data, int size);
    virtual ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int m_id;
};
