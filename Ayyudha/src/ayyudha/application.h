#pragma once

#include "aapch.h"
#include "core.h"
#include "window.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/event.h"
#include "ayyudha/layerStack.h"

#include "ayyudha/imgui/imguiLayer.h"

namespace AA
{

	class  Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event &e);

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);

		inline Window &GetWindow() { return *m_Window; }

		inline static Application &Get() { return *s_Instance; }

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer *m_ImGuiLayer;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent &e);
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;

	private:
		static Application *s_Instance;
	};

	// To be defined in CLIENT
	Application *CreateApplication();

} // namespace AA