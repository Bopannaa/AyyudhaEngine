#pragma once

#include "aapch.h"
#include "ayyudha/core/core.h"
#include "ayyudha/core/window.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/event.h"
#include "ayyudha/core/layerStack.h"

#include "ayyudha/imgui/imguiLayer.h"

namespace AA
{

	class Application
	{
	public:
		Application(std::string base_directory);
		virtual ~Application() = default;
		void Run();
		void OnEvent(Event &e);
		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);
		std::string CorrectFilePath(const std::string &);

	public:
		inline Window &GetWindow() { return *m_Window; }
		inline static Application &Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent &e);
		bool OnWindowResize(WindowResizeEvent &e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer *m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		std::string m_BaseDirectory;

	private:
		static Application *s_Instance;
	};

	// To be defined in CLIENT
	Application *CreateApplication();

} // namespace AA