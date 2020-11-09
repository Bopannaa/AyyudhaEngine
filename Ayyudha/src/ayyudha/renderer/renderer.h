#pragma once

#include "renderCommand.h"
#include "orthographicCamera.h"
#include "shader.h"

namespace AA
{

	class Renderer
	{
	public:
		static void BeginScene(OrthographicCamera &camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData *s_SceneData;
	};

} // namespace AA