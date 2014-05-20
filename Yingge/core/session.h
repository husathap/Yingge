#pragma once

#include <map>
#include <string>

// This class contains information on each game's session. This maps nicely with JSON.
namespace yingge
{
	class Session
	{
	public:
		std::string sceneName;
		std::string savedDateTime;

		std::map<std::string, std::string> strings;
		std::map<std::string, double> numbers;
		std::map<std::string, bool> booleans;

		Session::Session()
		{
			Session::sceneName = "";
			Session::savedDateTime = "";
			Session::strings = std::map<std::string, std::string>();
			Session::numbers = std::map<std::string, double>();
			Session::booleans = std::map<std::string, bool>();
		}
	};
}