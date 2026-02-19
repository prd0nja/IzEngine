#include "StringUtils.hpp"

namespace IzEngine
{
	std::string StringUtils::ToLower(const std::string& str)
	{
		std::string result = str;
		std::ranges::transform(result, result.begin(), [](unsigned char c) { return std::tolower(c); });
		return result;
	}

	std::string StringUtils::NormalizePath(const std::string& path)
	{
		std::string result = path;
		std::ranges::replace(result, '\\', '/');
		std::ranges::transform(result, result.begin(), [](unsigned char c) { return std::tolower(c); });
		return result;
	}
}
