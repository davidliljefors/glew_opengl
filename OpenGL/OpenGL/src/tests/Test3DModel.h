#pragma once
#include "Test.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace test
{
	class Test3DModel : public Test
	{
	public:
		Test3DModel();
		~Test3DModel();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		glm::vec4 m_ClearColor;


	};
}