#pragma once

#include "aapch.h"
#include "core.h"
#include "events/event.h"
#include "window.h"
#include "ayyudha/events/applicationEvent.h"

namespace AA {

	class AYYUDHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}