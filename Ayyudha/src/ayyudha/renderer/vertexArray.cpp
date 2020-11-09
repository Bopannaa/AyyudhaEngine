#include "aapch.h"
#include "vertexArray.h"

#include "renderer.h"
#include "platform/opengl/openglVertexArray.h"

namespace AA
{

	VertexArray *VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

} // namespace AA