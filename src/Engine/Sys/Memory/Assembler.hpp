#pragma once
#include "Engine/API.hpp"
#include "Function.hpp"

#include <asmjit/asmjit.h>
#ifndef ASMJIT_NO_X86
namespace arch = asmjit::x86;
#else
namespace arch = asmjit::x64;
#endif

namespace IW3SR::Engine
{
#define ASM_FUNCTION(function) \
	void ASM_##function(asmjit::CodeHolder& code, arch::Assembler& a)

#define ASM_LOAD(function) \
	Assembler::Get().NewCode(ASM_##function)

	/// <summary>
	/// Just-in-time assembler.
	/// </summary>
	class Assembler
	{
		CLASS_SINGLETON(Assembler)
	protected:
		using F = Function<void(asmjit::CodeHolder& code, arch::Assembler& a)>;
	public:
		asmjit::JitRuntime Runtime;

		/// <summary>
		/// Create a new code.
		/// </summary>
		/// <param name="function">The function callback with assembly instructions.</param>
		/// <returns>The compiled function address.</returns>
		uintptr_t NewCode(F function)
		{
			asmjit::CodeHolder code;
			code.init(Runtime.environment(), Runtime.cpuFeatures());
			arch::Assembler a(&code);

			function(code, a);

			int address = 0;
			auto error = Runtime.add(&address, &code);
			if (error) throw std::runtime_error("AsmJit compile error.");
			return address;
		}

	private:
		/// <summary>
		/// Initialize JIT assembler.
		/// </summary>
		Assembler() = default;
		~Assembler() = default;
	};
}
