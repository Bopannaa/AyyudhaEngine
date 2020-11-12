#include "aapch.h"
#include "renderCommand.h"

#include "platform/opengl/openglRendererAPI.h"

namespace AA
{
	RendererAPI *RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

} // namespace AA