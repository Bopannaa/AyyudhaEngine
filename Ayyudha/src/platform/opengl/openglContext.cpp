#include "aapch.h"
#include "openglContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/gl.h>

namespace AA
{

	OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
		: m_WindowHandle(windowHandle)
	{
		AA_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AA_CORE_ASSERT(status, "Failed to initialize Glad!");

		AA_CORE_INFO("OpenGL Info:");
		AA_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		AA_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		AA_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef AA_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		AA_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

} // namespace AA