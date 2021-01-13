#pragma once
#include "Renderer.h"
#include <cassert>

struct Texture
{
	enum class Type 
	{
		Diffuse,
		Specular,
		Normal,
		Height,
	};

public:
	Texture(std::string const& path);
	~Texture();
	
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeigth() const { return m_Heigth; }
	inline Type GetType() const { return m_Type; }


private:
	Type m_Type;
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Heigth, m_BPP;
};

inline std::string StringifyTextureType(Texture::Type type)
{
	switch (type)
	{
	case Texture::Type::Diffuse:	return std::string("diffuse");
	case Texture::Type::Specular:	return std::string("specular");
	case Texture::Type::Normal:		return std::string("normal");
	case Texture::Type::Height:		return std::string("height");
	}

	assert(false && "Unhandled texture type");
	return {};
};