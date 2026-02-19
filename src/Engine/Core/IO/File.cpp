#include "File.hpp"

namespace IzEngine
{
	bool File::IsValid() const
	{
		return !Data.empty();
	}
}
