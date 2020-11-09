#include "aapch.h"
#include "buffer.h"

#include "renderer.h"

#include "platform/opengl/openglBuffer.h"

namespace AA
{

	VertexBuffer *VertexBuffer::Create(float *vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer *IndexBuffer::Create(uint32_t *indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, size);
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

} // namespace AA