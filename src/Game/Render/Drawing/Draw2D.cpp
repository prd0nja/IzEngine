#include "Draw2D.hpp"

namespace IW3SR
{
	void Draw2D::Initialize()
	{
        HDC hdc = GetDC(NULL);
        
        auto callback = [](const LOGFONT* lpelf, const TEXTMETRIC* lpntm, DWORD FontType, LPARAM lParam)
        {
            ID3DXFont* pFont;
            D3DXCreateFont(dx->device, lpelf->lfHeight, 0, FW_NORMAL, 1, FALSE, DEFAULT_CHARSET,
                OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, lpelf->lfFaceName, &pFont);

            Fonts[lpelf->lfFaceName] = pFont;
            FontNames.push_back(lpelf->lfFaceName);
            return 1;
        };
        EnumFontFamilies(hdc, NULL, callback, NULL);
        ReleaseDC(NULL, hdc);
	}

    void Draw2D::Text(const std::string& text, const std::string& font, 
        float x, float y, float size, const vec4& color)
    {
        
    }
}
