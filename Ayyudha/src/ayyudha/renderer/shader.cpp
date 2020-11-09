#include "aapch.h"
#include "shader.h"

#include "renderer.h"
#include "platform/opengl/openglShader.h"

namespace AA
{
	Shader *Shader::Create(const std::string &vertexSrc, const std::string &fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
} // namespace AA