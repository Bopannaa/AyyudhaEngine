#include "application.h"

#include "ayyudha/events/applicationEvent.h"
#include <GLFW/glfw3.h>

namespace AA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		while (m_Running)
		{
			AA_TRACE(e);
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AA_TRACE(e);
		}
		while (true);
	}

}