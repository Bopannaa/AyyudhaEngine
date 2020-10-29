#pragma once

#ifdef AA_PLATFORM_WINDOWS

extern AA::Application* AA::CreateApplication();

int main(int argc, char** argv)
{
	auto app = AA::CreateApplication();
	app->Run();
	delete app;
}

#elif AA_PLATFORM_LINUX
	extern AA::Application* AA::CreateApplication();

	int main(int argc, char** argv)
	{
		auto app = AA::CreateApplication();
		app->Run();
		delete app;
	}
#endif