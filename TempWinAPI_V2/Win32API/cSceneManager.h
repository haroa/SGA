#pragma once
#include "cSingletonBase.h"

#define g_pSceneManager cSceneManager::GetInstance()

class cGameNode;

enum SCENE_LIST
{
	SLIST_TITLE,
	SLIST_LOADING,
	SLIST_PLAY,
	SLIST_DUNGEON,
	SLIST_END
};

class cSceneManager : public cSingletonBase<cSceneManager>
{
private:
	typedef map<SCENE_LIST, cGameNode*> mSceneList;
	typedef map<SCENE_LIST, cGameNode*>::iterator miSceneList;

private:
	static cGameNode*	m_pCurrScene;		// ���� ��
	static SCENE_LIST	m_eCurrScene;		// ���� �� Ÿ��
	mSceneList			m_mSceneList;		// ��ü �� ���

public:
	void Update();
	void Render();

	// �� �߰�
	cGameNode* AddScene(SCENE_LIST sceneName, cGameNode* scene);
	// ���� �� ��������
	SCENE_LIST GetCurrScene() { return m_eCurrScene; }
	// �� ����
	void ChangeScene(SCENE_LIST sceneName);
	// ��� �� ����
	void ReleaseAll();
};