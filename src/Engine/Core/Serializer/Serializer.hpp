#pragma once
#include <nlohmann/json.hpp>

#ifdef NLOHMANN_JSON_FROM
#undef NLOHMANN_JSON_FROM
#define NLOHMANN_JSON_FROM(v1) \
	if (nlohmann_json_j.contains(#v1)) \
		nlohmann_json_j.at(#v1).get_to(nlohmann_json_t.v1);
#endif

#define NLOHMANN_SERIALIZE(Type, ...) \
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Type, __VA_ARGS__)

#define NLOHMANN_SERIALIZE_NON_INTRUSIVE(Type, ...) \
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type, __VA_ARGS__)

#define NLOHMANN_SERIALIZE_DERIVED(Type, BaseType, ...) \
    friend void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) \
	{ \
		nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); \
		NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)); \
	} \
    friend void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t) \
	{ \
		nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); \
		NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)); \
	}

#define NLOHMANN_SERIALIZE_DERIVED_EMPTY(Type, BaseType) \
    friend void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t) \
	{ \
		nlohmann::to_json(nlohmann_json_j, static_cast<const BaseType &>(nlohmann_json_t)); \
	} \
    friend void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t) \
	{ \
		nlohmann::from_json(nlohmann_json_j, static_cast<BaseType&>(nlohmann_json_t)); \
	}

#define NLOHMANN_SERIALIZE_POLY(Type, BaseType, ...) \
	virtual void Serialize(nlohmann::json& nlohmann_json_j) override \
	{ \
		BaseType::Serialize(nlohmann_json_j); \
		to_json(nlohmann_json_j, *this); \
	} \
	virtual void Deserialize(nlohmann::json& nlohmann_json_j) override \
	{ \
		BaseType::Deserialize(nlohmann_json_j); \
		from_json(nlohmann_json_j, *this); \
	} \
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Type, __VA_ARGS__);

#define NLOHMANN_SERIALIZE_POLY_BASE(Type, ...) \
	virtual void Serialize(nlohmann::json& nlohmann_json_j) \
	{ \
		to_json(nlohmann_json_j, *this); \
	} \
	virtual void Deserialize(nlohmann::json& nlohmann_json_j) \
	{ \
		from_json(nlohmann_json_j, *this); \
	} \
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Type, __VA_ARGS__);
