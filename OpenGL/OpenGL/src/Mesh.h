#pragma once

#include <string>
#include <vector>
#include "glm/glm.hpp"

#include "Shader.h"
#include "Texture.h"
#include "assimp/scene.h"

struct Vertex 
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};


class Mesh {
public:
    Mesh(std::vector<Vertex>&& vertices, std::vector<unsigned int>&& indices, std::vector<Texture>&& textures);
    void Draw(Shader& shader);

private:
    //  render data
    unsigned int m_VAO, m_VBO, m_EBO;
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    std::vector<Texture> m_Textures;

    void InitMesh();
};