#pragma once

#ifdef AA_PLATFORM_WINDOWS

extern AA::Application* AA::CreateApplication();

int main(int argc, char** argv)
{
	AA::Log::Init();
	AA_CORE_WARN("Initialized Log!");
	int a = 5;
	AA_INFO("Hello! Var={0}", a);

	auto app = AA::CreateApplication();
	app->Run();
	delete app;
}

#elif AA_PLATFORM_LINUX
	extern AA::Application* AA::CreateApplication();

	int main(int argc, char** argv)
	{
		AA::Log::Init();
		AA_CORE_WARN("Initialized Log!");
		int a = 5;
		AA_INFO("Hello! Var={0}", a);
		auto app = AA::CreateApplication();
		app->Run();
		delete app;
	}
#endif