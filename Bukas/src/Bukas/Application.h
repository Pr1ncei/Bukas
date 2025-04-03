#pragma once

#include "Core.h"
namespace Bukas {
	class BUKAS_API Application {
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}