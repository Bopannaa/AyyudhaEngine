#pragma once

#include "aapch.h"
#include "core.h"
#include "window.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/event.h"
#include "ayyudha/layerStack.h"

namespace AA {

	class AYYUDHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}