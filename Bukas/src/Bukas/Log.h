#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Bukas {
	class BUKAS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros
#define BK_CORE_ERROR(...)      ::Bukas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BK_CORE_WARN(...)       ::Bukas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BK_CORE_INFO(...)		::Bukas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BK_CORE_TRACE(...)		::Bukas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BK_CORE_CRITICAL(...)	::Bukas::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define BK_CLIENT_ERROR(...)    ::Bukas::Log::GetClientLogger()->error(__VA_ARGS__)
#define BK_CLIENT_WARN(...)     ::Bukas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BK_CLIENT_INFO(...)		::Bukas::Log::GetClientLogger()->info(__VA_ARGS__)
#define BK_CLIENT_TRACE(...)	::Bukas::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BK_CLIENT_CRITICAL(...)	::Bukas::Log::GetClientLogger()->critical(__VA_ARGS__)