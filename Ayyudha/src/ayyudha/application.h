#pragma once

#include "aapch.h"
#include "core.h"
#include "window.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/event.h"
#include "ayyudha/layerStack.h"

#include "ayyudha/imgui/imguiLayer.h"

#include "ayyudha/renderer/shader.h"
#include "ayyudha/renderer/buffer.h"
#include "ayyudha/renderer/vertexArray.h"

#include "ayyudha/renderer/orthographicCamera.h"

namespace AA
{

	class AYYUDHA_API Application
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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;

	private:
		static Application *s_Instance;
	};

	// To be defined in CLIENT
	Application *CreateApplication();

} // namespace AA