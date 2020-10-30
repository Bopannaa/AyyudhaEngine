#pragma once

#include "core.h"
#include "events/event.h"

namespace AA {

	class AYYUDHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}