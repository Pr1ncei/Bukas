#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Bukas::Application* Bukas::CreateApplication();

int main(int argc, char** argv) {
	auto app = Bukas::CreateApplication();
	app->Run();
	delete app;
}

#endif