#pragma once
#include "cSingletonBase.h"
#include "ImageObject.h"

/*
Map : dictionary(Key - Value)
Key = first
Value = second
*/
#define g_pImageManager2 ImageManager::GetInstance()

class ImageManager : public cSingletonBase<ImageManager>
{
private:
    map<string, ImageObject*>               m_mapImage;
    map<string, ImageObject*>::iterator     m_mapIter;

public:
    ImageObject* AddImage(string Key, int Width, int Height);
    ImageObject* AddImage(string Key, const char* Filename, int Width, int Height);

    //  Search image and remove
    ImageObject* FindImage(string Key);
    void DeleteImage(string Key);
    void DeleteImageAll();

    void Render(string Key, HDC hdc);
};