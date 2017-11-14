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
	static cGameNode*	m_pCurrScene;		// ÇöÀç ¾À
	static SCENE_LIST	m_eCurrScene;		// ÇöÀç ¾À Å¸ÀÔ
	mSceneList			m_mSceneList;		// ÀüÃ¼ ¾À ¸ñ·Ï

public:
	void Update();
	void Render();

	// ¾À Ãß°¡
	cGameNode* AddScene(SCENE_LIST sceneName, cGameNode* scene);
	// ÇöÀç ¾À °¡Á®¿À±â
	SCENE_LIST GetCurrScene() { return m_eCurrScene; }
	// ¾À º¯°æ
	void ChangeScene(SCENE_LIST sceneName);
	// ¸ðµç ¾À »èÁ¦
	void ReleaseAll();
};