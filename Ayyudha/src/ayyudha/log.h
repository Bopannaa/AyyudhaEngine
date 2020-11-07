#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace AA {

	class AYYUDHA_API Log
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

// Core log macros
#define AA_CORE_TRACE(...)    ::AA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AA_CORE_INFO(...)     ::AA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AA_CORE_WARN(...)     ::AA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AA_CORE_ERROR(...)    ::AA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AA_CORE_FATAL(...)    ::AA::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AA_TRACE(...)	      ::AA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AA_INFO(...)	      ::AA::Log::GetClientLogger()->info(__VA_ARGS__)
#define AA_WARN(...)	      ::AA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AA_ERROR(...)	      ::AA::Log::GetClientLogger()->error(__VA_ARGS__)
#define AA_FATAL(...)	      ::AA::Log::GetClientLogger()->critical(__VA_ARGS__) 