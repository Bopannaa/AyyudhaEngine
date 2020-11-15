#include "aapch.h"
#include "renderCommand.h"

#include "platform/opengl/openglRendererAPI.h"

namespace AA
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();

} // namespace AA