#include "stdafx.h"
#include "cSceneManager.h"
#include "cGameNode.h"

// ����ƽ ���� �ʱ�ȭ
cGameNode* cSceneManager::m_pCurrScene = NULL;
SCENE_LIST cSceneManager::m_eCurrScene = SLIST_END;

void cSceneManager::Update()
{
	if (m_pCurrScene)
		m_pCurrScene->Update();
}

void cSceneManager::Render()
{
	if (m_pCurrScene)
		m_pCurrScene->Render();
}

cGameNode* cSceneManager::AddScene(SCENE_LIST sceneName, cGameNode* scene)
{
	// ���� �� ���(��)�� �߰� �Ѵ�.
	if (scene) m_mSceneList.insert(make_pair(sceneName, scene));
	return scene;
}

void cSceneManager::ChangeScene(SCENE_LIST sceneName)
{
	// �� ��� �� ���ͷ�����
	miSceneList find = m_mSceneList.find(sceneName);

	// ã�� ���� ���� ���
	if (find == m_mSceneList.end())
		assert(false && "ã�� ���� ����.");

	// ã�� ���� ������� ���� ���
	if (find->second == m_pCurrScene)
		assert(false && "ã�� ���� ���� ���� ����");

	// ������� �Դٸ� �� ��ȯ�� ������ ����
	if (m_pCurrScene != NULL)
	{ // ���� ���� ��� ���� ����
		m_pCurrScene->Release();
		//g_pImageManager->ReleaseAll();
	}

	// ���ο� ������ ��ü �� �¾�
	m_eCurrScene = find->first;
	m_pCurrScene = find->second;
	m_pCurrScene->Setup();
}

void cSceneManager::ReleaseAll()
{
	// ��� ���� �ݺ��ڸ� ���ؼ� ���鼭 ���� ���� �Ѵ�.
	miSceneList iter = m_mSceneList.begin();
	for (; iter != m_mSceneList.end();)
	{
		// ����
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = m_mSceneList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	m_mSceneList.clear();
}
