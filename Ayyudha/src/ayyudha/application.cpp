#include "application.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/log.h"

namespace AA {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AA_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AA_TRACE(e);
		}

		while (true);
	}

}