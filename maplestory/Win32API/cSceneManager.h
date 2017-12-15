#pragma once
#include "cSingletonBase.h"

#define g_pSceneManager cSceneManager::GetInstance()

class cGameNode;

enum SCENE_LIST
{
	SLIST_LOADING,
	SLIST_TITLE,
	SLIST_PANTHEONTOWN
};

class cSceneManager : public cSingletonBase<cSceneManager>
{
private:
	typedef map<SCENE_LIST, cGameNode*> mSceneList;
	typedef map<SCENE_LIST, cGameNode*>::iterator miSceneList;

private:
	static cGameNode*	m_pCurrScene;		// ���� ��
	static SCENE_LIST	m_eNextScene;		// ���� �� (Ű ��)
	static SCENE_LIST	m_eCurrScene;		// ���� �� (Ű ��)
	static SCENE_LIST	m_eBefoScene;		// �� �� (Ű ��)
	mSceneList			m_mSceneList;		// ��ü �� ���

public:
	void Update();
	void Render();

	// �� �߰�
	cGameNode* AddScene(SCENE_LIST sceneName, cGameNode* scene);
	// ���� ��
	void SetNextScene(SCENE_LIST next) { m_eNextScene = next; }
	SCENE_LIST GetNextScene() { return m_eNextScene; }
	// ���� ��
	SCENE_LIST GetBefoScene() { return m_eBefoScene; }
	// �� ����
	void ChangeScene(SCENE_LIST sceneName);
	// ��� �� ����
	void ReleaseAll();
};