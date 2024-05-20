#pragma once

#define CLASS_DISALLOW_COPY_AND_ASSIGN(type) \
	type(const type&) = delete;              \
	void operator=(const type&) = delete;

#define CLASS_DISALLOW_MOVE(type) \
	type(type&&) = delete;        \
	type& operator=(type&&) = delete;

#define CLASS_DEFAULT(type) \
public:                     \
	type() = default;       \
	virtual ~type() = default;

#define CLASS_SINGLETON(type) \
public:                       \
	static inline type& Get() \
	{                         \
		static type instance; \
		return instance;      \
	}

#define CLASS_FINAL(type)                  \
public:                                    \
	virtual ~type() = default;             \
                                           \
private:                                   \
	type() = default;                      \
	type(const type&) = delete;            \
	type& operator=(const type&) = delete; \
	type(type&&) = delete;                 \
	type& operator=(type&&) = delete;
