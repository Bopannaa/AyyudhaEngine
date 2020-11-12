#include "aapch.h"
#include "texture.h"

#include "renderer.h"
#include "platform/opengl/openglTexture.h"
#include "ayyudha/application.h"
#include "ayyudha/log.h"

namespace AA {

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    AA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLTexture2D>(Application::Get().CorrectFilePath(path));
		}

		AA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}