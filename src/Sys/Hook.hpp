#pragma once
#include <vector>
#include <map>
#include <cstdint>

#include <Windows.h>
#include <MinHook.h>

namespace IW3SR
{
    /// <summary>
    /// Hook class.
    /// </summary>
    /// <typeparam name="T">The hook function definition type.</typeparam>
    template <typename T>
    class Hook
    {
    public:
        uint32_t Target = 0;
        uint32_t Address = 0;
        uint32_t Trampoline = 0;
        T Detour = 0;

        /// <summary>
        /// Initialize a new Hook instance.
        /// </summary>
        Hook() = default;
        ~Hook() = default;

        /// <summary>
        /// Initialize a new Hook instance.
        /// </summary>
        /// <param name="target">The target address.</param>
        /// <param name="detour">The detour function.</param>
        Hook(uint32_t target, T detour)
        {
            Target = target;
            Detour = detour;

            Install();
        }

        /// <summary>
        /// Install the hook.
        /// </summary>
        /// <returns></returns>
        void Install()
        {
            auto it = Table.find(Target);
            std::vector<Hook<T>> hooks = it != Table.end() ? it->second : std::vector<Hook<T>>{ };

            Address = hooks.empty() ? Target : hooks.front().Trampoline;

            LPVOID lpAddress = reinterpret_cast<LPVOID>(Address);
            LPVOID lpDetour = reinterpret_cast<LPVOID>(Detour);
            LPVOID lpTrampoline = nullptr;

            MH_CreateHook(lpAddress, lpDetour, &lpTrampoline);
            MH_EnableHook(lpAddress);

            Trampoline = reinterpret_cast<uint32_t>(lpTrampoline);

            hooks.push_back(*this);
            Table[Target] = hooks;
        }

        /// <summary>
        /// Remove the hook.
        /// </summary>
        void Remove()
        {
            auto it = Table.find(Target);
            if (it == Table.end())
                return;

            std::vector<Hook<T>> hooks = it->second;
            for (auto it = hooks.rbegin(); it != hooks.rend(); ++it)
            {
                LPVOID lpAddress = reinterpret_cast<LPVOID>(it->Address);
                MH_DisableHook(lpAddress);
                MH_RemoveHook(lpAddress);
            }

            std::erase_if(hooks, [this](const Hook<T>& hook) { return hook.Address == Address; });
            if (hooks.empty())
            {
                Table.erase(Target);
                return;
            }

            it->second = { };
            for (Hook<T>& hook : hooks)
            {
                hook.Address = hook.Target;
                hook.Install();
            }
        }

        /// <summary>
        /// Call the trampoline function.
        /// </summary>
        /// <typeparam name="R">The return type.</typeparam>
        /// <typeparam name="...Args">The function args type.</typeparam>
        /// <param name="...args">The function args.</param>
        /// <returns></returns>
        template <typename R = void, typename ...Args>
        R Call(const Args... args)
        {
            return reinterpret_cast<T>(Trampoline)(args...);
        }

    private:
        static inline std::map<uint32_t, std::vector<Hook<T>>> Table;
    };
}
