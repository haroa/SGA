#pragma once

#define g_pDeviceManager cDeviceManager::GetInstance()
#define g_pD3DDevice cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
private:
	LPDIRECT3D9				m_pD3D;			// D3D9 �������̽����� �����͸� ��´�.
	LPDIRECT3DDEVICE9		m_pD3DDevice;	// ��ġ�� ���� D3D9 �������̽��� ����µ� ��� �ȴ�.

public:
	cDeviceManager();
	~cDeviceManager();

	static cDeviceManager* GetInstance()
	{
		static cDeviceManager instance;
		return &instance;
	}

	void Destroy();

	LPDIRECT3DDEVICE9 GetDevice() { return m_pD3DDevice; }
};