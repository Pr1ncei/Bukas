#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Bukas::Application* Bukas::CreateApplication();

int main(int argc, char** argv) {
	Bukas::Log::Init();
	BK_CORE_WARN("Binuksan ang Log!");
	BK_CLIENT_INFO("Kamusta!");

	auto app = Bukas::CreateApplication();
	app->Run();
	delete app;
}

#endif