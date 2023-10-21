#pragma once

#define NLOHMANN_DEFINE_POLY(ChildClass) \
	virtual void Serialize(nlohmann::json& json) override \
	{ \
		ChildClass::Serialize(json); \
		to_json(json, *this); \
	}

#define NLOHMANN_DEFINE_POLY_BASE() \
	virtual void Serialize(nlohmann::json& json) \
	{ \
		to_json(json, *this); \
	}
