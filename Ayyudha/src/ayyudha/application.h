#pragma once

#include "aapch.h"
#include "core.h"
#include "events/event.h"
#include "window.h"

namespace AA {

	class AYYUDHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}