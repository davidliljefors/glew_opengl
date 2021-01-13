#pragma once
#include <Gl/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))


void GLClearError();
bool GLLogCall(char const* function, char const* file, int line);

class Renderer
{
public:
	void Clear() const;
	void Draw(VertexArray const& va, IndexBuffer const& ib, Shader const& shader) const;

};