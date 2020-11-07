#pragma once

#include "ayyudha/layer.h"

#include "ayyudha/events/applicationEvent.h"
#include "ayyudha/events/keyEvent.h"
#include "ayyudha/events/mouseEvent.h"

namespace AA
{

	class AYYUDHA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

} // namespace AA