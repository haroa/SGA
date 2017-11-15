#pragma once
#include "cSingletonBase.h"

#define g_pFileManager FileDataManager::GetInstance()

class FileDataManager : public cSingletonBase<FileDataManager>
{
private:
    map<string, json>   m_mapJsonData;

public:
    void    JsonSave(string Filename, string JsonString);
    void    JsonLoad(string Key, string Filename);
    void    JsonRelease(string Key);
    json    JsonFind(string Key);
    void    FileAppend(string Filename, string StringData);

    string  MakeCsvString(vector<string> VecArray);
    vector<string>  CharArraySeperation(char CharArray[]);
    void Tokenizer(const string& str, vector<string>& tokens, const string& token = ",");
};