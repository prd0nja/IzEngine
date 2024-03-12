#pragma once
#include <format>
#include <string>
#include <iostream>
#include <unordered_map>

namespace IW3SR::Engine
{
	/// <summary>
	/// Channels.
	/// </summary>
	enum class Channel
	{
		Log,
		Debug,
		Warning,
		Error,
		Info,
		Verbose,
		System,
		Engine,
		Game,
		Audio
	};

	/// <summary>
	/// Console ANSI colors.
	/// </summary>
	enum class ConColor
	{
		Default = 0,
		Red = 91,
		Green = 92,
		Yellow = 93,
		Blue = 94,
		Magenta = 95,
		Cyan = 96,
		White = 97,
		Black = 30,
		DarkRed = 31,
		DarkGreen = 32,
		DarkYellow = 33,
		DarkBlue = 34,
		DarkMagenta = 35,
		DarkCyan = 36,
		DarkWhite = 37,
	};

	/// <summary>
	/// Log class.
	/// </summary>
	class API Log
	{
	public:
		/// <summary>
		/// Write to the console.
		/// </summary>
		/// <param name="msg">The string.</param>
		static void Write(const std::string& msg)
		{
			const bool eol = msg.find('\n') != std::string::npos;
			const auto endl = eol ? FormatColor(ConColor::Default) : "";
			std::cout << msg << endl;
		}

		/// <summary>
		/// Write to the console.
		/// </summary>
		/// <typeparam name="...Args">The format arguments.</typeparam>
		/// <param name="fmt">The format string.</param>
		/// <param name="...args">The format arguments.</param>
		template <typename... Args>
		static void Write(std::format_string<Args...> fmt, Args&&... args)
		{
			Write(std::format(fmt, std::forward<Args>(args)...));
		}

		/// <summary>
		/// Write line to the console.
		/// </summary>
		/// <typeparam name="...Args">The format arguments.</typeparam>
		/// <param name="fmt">The format string.</param>
		/// <param name="...args">The format arguments.</param>
		template <typename... Args>
		static void WriteLine(std::format_string<Args...> fmt, Args&&... args)
		{
			Write(std::format(fmt, std::forward<Args>(args)...) + '\n');
		}

		/// <summary>
		/// Write line to the console.
		/// </summary>
		/// <typeparam name="...Args">The format arguments.</typeparam>
		/// <param name="channel">The log channel.</param>
		/// <param name="fmt">The format string.</param>
		/// <param name="...args">The format arguments.</param>
		template <typename... Args>
		static void WriteLine(Channel channel, std::format_string<Args...> fmt, Args&&... args)
		{
			const auto& msg = std::format(fmt, std::forward<Args>(args)...) + '\n';
			const auto& [name, color] = Channels[channel];
			Write(std::format("{}{}{}", FormatColor(color), FormatChannel(name), msg));
		}

	private:
		/// <summary>
		/// Channel info.
		/// </summary>
		struct Info
		{
			std::string name;
			ConColor color;
		};

		/// <summary>
		/// Channels.
		/// </summary>
		static inline std::unordered_map<Channel, Info> Channels = {
			{ Channel::Log, { "Log", ConColor::Default } },
			{ Channel::Debug, { "Debug", ConColor::DarkWhite } },
			{ Channel::Warning, { "Warning", ConColor::Yellow } },
			{ Channel::Error, { "Error", ConColor::Red } },
			{ Channel::Info, { "Info", ConColor::Cyan } },
			{ Channel::Verbose, { "Verbose", ConColor::Green } },
			{ Channel::System, { "System", ConColor::Magenta } },
			{ Channel::Engine, { "Engine", ConColor::Magenta } },
			{ Channel::Game, { "Game", ConColor::Cyan } },
			{ Channel::Audio, { "Audio", ConColor::Magenta } }
		};

		/// <summary>
		/// Format channel name.
		/// </summary>
		/// <param name="channel">The channel name.</param>
		/// <returns></returns>
		static inline std::string FormatChannel(const std::string& name)
		{
			return std::format("[{}] ", name);
		}

		/// <summary>
		/// Format color.
		/// </summary>
		/// <param name="color">The color.</param>
		static inline std::string FormatColor(ConColor color)
		{
			return std::format("\x1b[{}m", static_cast<int>(color));
		}
	};
}
