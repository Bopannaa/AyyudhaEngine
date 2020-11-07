#pragma once

#include "ayyudha/renderer/graphicsContext.h"

struct GLFWwindow;

namespace AA {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

} 