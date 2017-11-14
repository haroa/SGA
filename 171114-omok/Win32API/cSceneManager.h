#pragma once
#include "cSingletonBase.h"

#define g_pSceneManager cSceneManager::GetInstance()

class cGameNode;

class cSceneManager : public cSingletonBase<cSceneManager>
{
private:
	typedef map<string, cGameNode*> mSceneList;
	typedef map<string, cGameNode*>::iterator miSceneList;

private:
	static cGameNode*	m_pCurrScene;		// ���� ��
	mSceneList			m_mSceneList;		// ��ü �� ���

public:
	void Update();
	void Render();

	// �� �߰�
	cGameNode* AddScene(string sceneName, cGameNode* scene);
	// �� ����
	void ChangeScene(string sceneName);
	// ��� �� ����
	void ReleaseAll();
};