#include "Renderer.h"
#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(char const* function, char const* file, int line)
{

	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ") " << function <<
			" " << std::endl << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(VertexArray const& va, IndexBuffer const& ib, Shader const& shader) const
{
	//shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount() , GL_UNSIGNED_INT, nullptr));
}
