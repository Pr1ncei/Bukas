#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Bukas::Application* Bukas::CreateApplication();

int main(int argc, char** argv) {
	Bukas::Log::Init();
	Bukas::Log::GetCoreLogger()->warn("Binuksan ang Log!");
	Bukas::Log::GetClientLogger()->info("Kamusta!");

	auto app = Bukas::CreateApplication();
	app->Run();
	delete app;
}

#endif