#pragma once
#include "Core/Common.hpp"

#include "Texture.hpp"

#include <cef_app.h>
#include <cef_browser.h>
#include <cef_client.h>
#include <latch>

namespace IzEngine
{
	class BrowserApp : public CefApp
	{
		IMPLEMENT_REFCOUNTING(BrowserApp);
	};

	class BrowserClient : public CefClient, public CefLifeSpanHandler, public CefRenderHandler
	{
	public:
		CefRefPtr<CefRenderHandler> GetRenderHandler() override;
		CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;
		void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;

		void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects,
			const void* buffer, int width, int height) override;
		void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
		void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
		bool IsClosed();

	private:
		std::atomic<bool> Painted;
		std::atomic<bool> Closed;

		IMPLEMENT_REFCOUNTING(BrowserClient);
	};

	class Browser
	{
	public:
		static inline CefRefPtr<CefBrowser> Instance;
		static inline CefRefPtr<BrowserApp> App;
		static inline CefRefPtr<BrowserClient> Client;
		static inline Ref<Texture> Texture;
		static inline std::mutex TextureMutex;

		static void Initialize();
		static void Shutdown();
	};
}
