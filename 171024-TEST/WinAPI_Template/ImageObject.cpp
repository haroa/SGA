#include "stdafx.h"
#include "ImageObject.h"
#include "DrawHelper.h"
#include "GeometryHelper.h"

#pragma region CONSTRUCTOR
ImageObject::ImageObject()
    :m_pImageInfo(NULL)
    ,m_szFileName(NULL)
    ,m_isTrans(true)
    ,m_transColor(RGB(255, 0, 255))
    ,m_pBlendImage(NULL)
{
}

ImageObject::~ImageObject()
{
    if (m_pImageInfo)
    {
        SelectObject(m_pImageInfo->hMemDC, m_pImageInfo->hOldBit);
        DeleteObject(m_pImageInfo->hBit);
        DeleteDC(m_pImageInfo->hMemDC);

        if (m_szFileName)
        {
            delete m_szFileName;
        }
        delete m_pImageInfo;
    }
}
#pragma endregion

#pragma region SETUP
void ImageObject::Setup(int width, int height)
{
    Setup(NULL, width, height);
}

void ImageObject::Setup(const char * FileName, int width, int height)
{
    //  Basic image
    HDC hdc = GetDC(g_hWnd);

    m_pImageInfo = new IMAGE_INFO;
    m_pImageInfo->btLoadType = LOAD_FILE;
    m_pImageInfo->resID = 0;
    m_pImageInfo->hMemDC = CreateCompatibleDC(hdc);
    if (FileName == NULL)
    {
        m_pImageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
    }
    else
    {
        m_pImageInfo->hBit = (HBITMAP)LoadImage(g_hInst, FileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
        int len = (int)strlen(FileName);
        m_szFileName = new char[len + 1];
        strcpy_s(m_szFileName, len + 1, FileName);
    }
    m_pImageInfo->hOldBit = (HBITMAP)SelectObject(m_pImageInfo->hMemDC, m_pImageInfo->hBit);
    m_pImageInfo->nWidth = width;
    m_pImageInfo->nHeight = height;

    ReleaseDC(g_hWnd, hdc);

    //  For transparent
    m_isTrans = true;
    m_transColor = RGB(255, 0, 255);

    //  For alpha blend
    m_stBlendFunc.BlendOp = AC_SRC_OVER;
    m_stBlendFunc.BlendFlags = 0;
    m_stBlendFunc.AlphaFormat = 0;

    // ���ĺ��� ����ü �ʱ�ȭ (�⺻ ���� �ٲ� ���� ����)
    // DC ��������
    HDC alphaHdc = GetDC(g_hWnd);

    // �̹��� ���� ���� ���� �� �ʱ�ȭ
    m_pBlendImage = new IMAGE_INFO;
    m_pBlendImage->btLoadType = LOAD_EMPTY;
    m_pBlendImage->resID = 0;
    m_pBlendImage->hMemDC = CreateCompatibleDC(alphaHdc);
    m_pBlendImage->hBit = (HBITMAP)CreateCompatibleBitmap(alphaHdc, m_pImageInfo->nWidth, m_pImageInfo->nHeight);
    m_pBlendImage->hOldBit = (HBITMAP)SelectObject(m_pBlendImage->hMemDC, m_pBlendImage->hBit);
    m_pBlendImage->nWidth = W_WIDTH;
    m_pBlendImage->nHeight = W_HEIGHT;

    // DC ����
    ReleaseDC(g_hWnd, alphaHdc);
}
#pragma endregion

#pragma region SPRITES
void ImageObject::SpritesRender(HDC hdc, RECT SpritesBox, int FrameX, int FrameY, double Alpha)
{
    m_stBlendFunc.SourceConstantAlpha = (BYTE)Alpha;
    POINT boxSize = { SpritesBox.right - SpritesBox.left, SpritesBox.bottom - SpritesBox.top };
    BitBlt(m_pBlendImage->hMemDC
        , 0, 0
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , hdc
        , SpritesBox.left, SpritesBox.top
        , SRCCOPY);

    GdiTransparentBlt(m_pBlendImage->hMemDC
        , 0, 0
        , m_spritesWidth, m_spritesHeight
        , m_pImageInfo->hMemDC
        , m_spritesWidth * FrameX, m_spritesHeight * FrameY
        , m_spritesWidth, m_spritesHeight
        , m_transColor);

    GdiAlphaBlend(hdc
        , SpritesBox.left, SpritesBox.top
        , boxSize.x, boxSize.y
        , m_pBlendImage->hMemDC
        , 0, 0
        , m_spritesWidth, m_spritesHeight
        , m_stBlendFunc);
}

void ImageObject::SpritesRender(HDC hdc, UnitPos DestPos, UnitSize DestSize, int FrameX, int FrameY, double Alpha)
{
    RECT DestRt = g_pDrawHelper->MakeRect(DestPos, DestSize);
    SpritesRender(hdc, DestRt, FrameX, FrameY, Alpha);
}

void ImageObject::SpritesRender(HDC hdc, UnitPos RightEndPos, UnitSize EachSize, int Number, double Alpha)
{
    int tempScore = Number;
    UnitPos renderPos = RightEndPos;

    while (tempScore != 0)
    {
        int printNumber = tempScore % 10;

        //  NUMBER RENDERER
        SpritesRender(hdc, renderPos, EachSize, printNumber, 0, Alpha);
        renderPos.x -= (double)EachSize.w;
        tempScore -= printNumber;
        tempScore = tempScore / 10;
    }
}

void ImageObject::SpritesRender(HDC hdc, UnitPos DestPos, UnitSize DestSize, UnitSize SrcSize, int FrameX, int FrameY, double Alpha)
{
    m_stBlendFunc.SourceConstantAlpha = (BYTE)Alpha;
    BitBlt(m_pBlendImage->hMemDC
        , 0, 0
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , hdc
        , 0, 0
        , SRCCOPY);

    GdiTransparentBlt(m_pBlendImage->hMemDC
        , (int)(DestPos.x - m_spritesWidth * 0.5f), (int)(DestPos.y - m_spritesHeight * 0.5f)
        , DestSize.w, DestSize.h
        , m_pImageInfo->hMemDC
        , m_spritesWidth * FrameX, m_spritesHeight * FrameY
        , m_spritesWidth, m_spritesHeight
        , m_transColor);

    GdiAlphaBlend(hdc
        , (int)(DestPos.x - m_spritesWidth * 0.5f), (int)(DestPos.y - m_spritesHeight * 0.5f)
        , DestSize.w, DestSize.h
        , m_pBlendImage->hMemDC
        , (int)(DestPos.x - m_spritesWidth * 0.5f), (int)(DestPos.y - m_spritesHeight * 0.5f)
        , SrcSize.w, SrcSize.h
        , m_stBlendFunc);
}
#pragma endregion

#pragma region ROTATE
void ImageObject::Render(HDC hdc, UnitPos KeyPos, double Angle)
{
    UnitPos pt1 = UnitPos{ (KeyPos.x - m_pImageInfo->nWidth * 0.5f), (KeyPos.y - m_pImageInfo->nHeight * 0.5f) };
    UnitPos pt2 = UnitPos{ (KeyPos.x + m_pImageInfo->nWidth * 0.5f), (KeyPos.y - m_pImageInfo->nHeight * 0.5f) };
    UnitPos pt3 = UnitPos{ (KeyPos.x - m_pImageInfo->nWidth * 0.5f), (KeyPos.y + m_pImageInfo->nHeight * 0.5f) };

    pt1 = g_pGeoHelper->GetRotateCoord(KeyPos, pt1, Angle);
    pt2 = g_pGeoHelper->GetRotateCoord(KeyPos, pt2, Angle);
    pt3 = g_pGeoHelper->GetRotateCoord(KeyPos, pt3, Angle);

    POINT Pt[3] = {
          POINT{ (LONG)pt1.x, (LONG)pt1.y }
        , POINT{ (LONG)pt2.x, (LONG)pt2.y }
        , POINT{ (LONG)pt3.x, (LONG)pt3.y }
    };

    BitBlt(m_pBlendImage->hMemDC
                    , 0, 0
                    , W_WIDTH, W_HEIGHT
                    , hdc
                    , 0, 0
                    , SRCCOPY);
    
    PlgBlt(m_pBlendImage->hMemDC, Pt, m_pImageInfo->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , NULL
                    , 0, 0);
    
    GdiTransparentBlt(hdc
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_pBlendImage->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_transColor);
}
#pragma endregion

#pragma region NORMAL_RENDER
//  Fullsize blit to (0, 0) from (0, 0)
void ImageObject::FastRender(HDC hdc)
{
    BitBlt(hdc
        , 0, 0
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , m_pImageInfo->hMemDC
        , 0, 0
        , SRCCOPY);
}

//  Fullsize blit to (0, 0) from (X, Y) : this coordinates are not center point
void ImageObject::FastRender(HDC hdc, UnitPos DestPos)
{
    FastRender(hdc, DestPos, UnitPos{ 0.0f, 0.0f });
}

//  FullSize blit to (dX, dY) from (sX, sY) : this coordinates are not center point
void ImageObject::FastRender(HDC hdc, UnitPos DestPos, UnitPos SrcPos)
{
    BitBlt(hdc
        , (int)DestPos.x, (int)DestPos.y
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , m_pImageInfo->hMemDC
        , (int)DestPos.x, (int)DestPos.y
        , SRCCOPY);
}

void ImageObject::Render(HDC hdc, UnitPos Pos)
{
    GdiTransparentBlt(hdc
                    , (int)(Pos.x - GetWidth() * 0.5f), (int)(Pos.y - GetHeight() * 0.5f)
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_pImageInfo->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_transColor);
}

void ImageObject::Render(HDC hdc, int destX, int destY)
{
    if (m_isTrans)
    {
        GdiTransparentBlt(hdc
                        , destX, destY
                        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                        , m_pImageInfo->hMemDC
                        , 0, 0
                        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                        , m_transColor);
    }
    else
    {
        BitBlt(hdc
            , destX, destY
            , m_pImageInfo->nWidth, m_pImageInfo->nHeight
            , m_pImageInfo->hMemDC
            , 0, 0
            , SRCCOPY);
    }
}

void ImageObject::Render(HDC hdc, int destX, int destY, int destW, int destH)
{
    GdiTransparentBlt(hdc
                    , destX, destY
                    , destW, destH
                    , m_pImageInfo->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_transColor);
}

void ImageObject::Render(HDC hdc, int destX, int destY, int srcX, int srcY, int srcW, int srcH)
{
    if (m_isTrans)
    {
        GdiTransparentBlt(hdc
                        , destX, destY
                        , srcW, srcH
                        , m_pImageInfo->hMemDC
                        , srcX, srcY
                        , srcW, srcH
                        , m_transColor);
    }
    else
    {
        BitBlt(hdc
            , destX, destY
            , srcW, srcH
            , m_pImageInfo->hMemDC
            , srcX, srcY
            , SRCCOPY);
    }
}

void ImageObject::AlphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
    // ���İ� �ʱ�ȭ
    m_stBlendFunc.SourceConstantAlpha = alpha;

    if (m_isTrans)
    {
        //1. ����ؾ� �� DC�� �׷��� �ִ� ������ �����̹����� �׷��ش�
        BitBlt(m_pBlendImage->hMemDC
            , 0, 0
            , m_pImageInfo->nWidth, m_pImageInfo->nHeight
            , hdc
            , destX, destY
            , SRCCOPY);
        //2. ����ؾ� �� �̹����� ���忡 �׷��ش�(����Ÿ ���� �����ش�)
        GdiTransparentBlt(m_pBlendImage->hMemDC
                        , 0, 0
                        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                        , m_pImageInfo->hMemDC
                        , 0, 0
                        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                        , m_transColor);
        //3. ���� DC�� ����ؾ� �� DC�� �׸���
        
        GdiAlphaBlend(hdc
                    , destX, destY
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_pBlendImage->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_stBlendFunc);
    }
    else
    {
        // ���ĺ��� �ɼ� ���� ����ؼ� �׸���.
        GdiAlphaBlend(hdc
                    , destX, destY
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_pImageInfo->hMemDC
                    , 0, 0
                    , m_pImageInfo->nWidth, m_pImageInfo->nHeight
                    , m_stBlendFunc);
    }
}

void ImageObject::Render(HDC hdc, int destX, int destY, int srcX, int srcY, int srcW, int srcH, int alpha)
{
    Render(hdc
        , destX, destY
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , srcX, srcY
        , srcW, srcH
        , alpha);
}

void ImageObject::Render(HDC hdc, int destX, int destY, int destW, int destH, int srcX, int srcY, int srcW, int srcH, int alpha)
{
    m_stBlendFunc.SourceConstantAlpha = alpha;
    GdiAlphaBlend(hdc
                , destX, destY
                , destW, destH
                , m_pImageInfo->hMemDC
                , srcX, srcY
                , srcW, srcH
                , m_stBlendFunc);
}
#pragma endregion

#pragma region TRANSPARENT_RENDER
//  No resize blit with Transparent
void ImageObject::TransRender(HDC hdc)
{
    GdiTransparentBlt(hdc
        , 0, 0
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , m_pImageInfo->hMemDC
        , 0, 0
        , m_pImageInfo->nWidth, m_pImageInfo->nHeight
        , m_transColor);
}


#pragma endregion