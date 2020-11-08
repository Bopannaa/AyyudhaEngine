#include "aapch.h"
#include "vertexArray.h"

#include "renderer.h"
#include "platform/opengl/openglVertexArray.h"

namespace AA {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:    AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}