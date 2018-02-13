#pragma once


struct vertData {
    float pos[2];
    float textcoord[2];
    vertData(){}
    vertData(float x, float y, float s, float t){
	pos[0] = x;
	pos[1] = y;
	textcoord[0] = s;
	textcoord[1] = t;
    }
};

class ArrayBuffer
{
public:
    ArrayBuffer();
    ArrayBuffer(void * data, int size);
    virtual ~ArrayBuffer();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int m_id;
};
