#pragma once

#include "aapch.h"
#include "core.h"
#include "window.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/event.h"
#include "ayyudha/layerStack.h"

#include "ayyudha/imgui/imguiLayer.h"

#include "ayyudha/renderer/shader.h"

namespace AA
{

	class AYYUDHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event &e);

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);
		
		inline Window &GetWindow() { return *m_Window; }

		inline static Application &Get(){	return *s_Instance; }

		private:
			std::unique_ptr<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			bool OnWindowClose(WindowCloseEvent & e);
			LayerStack m_LayerStack;

			unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
			std::unique_ptr<Shader> m_Shader;

		private:
			static Application *s_Instance;
		};

		// To be defined in CLIENT
		Application *CreateApplication();

	} // namespace AA