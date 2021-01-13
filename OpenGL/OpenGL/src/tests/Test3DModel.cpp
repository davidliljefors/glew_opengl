#include "Test3Dmodel.h"
#include "Renderer.h"
#include "imgui/imgui.h"


namespace test
{

	Test3DModel::Test3DModel()
		:m_ClearColor{ 0.1f, 0.1f, 0.1f, 1.0f }
	{

	}

	Test3DModel::~Test3DModel()
	{

	}

	void Test3DModel::OnUpdate(float deltaTime)
	{

	}

	void Test3DModel::OnRender()
	{
		GLCall(glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Test3DModel::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", glm::value_ptr(m_ClearColor));
	}

}
