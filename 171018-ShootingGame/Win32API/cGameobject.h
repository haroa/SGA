#pragma once
#include "cImage.h"

class cGameobject
{
protected:
	cImage*		m_pImage;	//�ڱ��̹���
	float		m_fPosX;	//���� X��ġ
	float		m_fPosY;	//���� Y��ġ
	RECT		m_rtBody;	//��Ʈ �ڽ�
	float		m_fSpeedX;	//X�� ��ġ���ǵ�
	float		m_fSpeedY;	//Y�� ��ġ���ǵ�
	int			m_nDelay;	//������
	int			m_nSizeW;	//����ũ��
	int			m_nSizeH;	//����ũ��
	



	bool	m_isActive;	//Ȱ��ȭ üũ
public:
	
#pragma region GET
	float GetPosX() { return m_fPosX; }
	float GetPosY() { return m_fPosY; }
	float GetSpeedX() { return m_fSpeedX; }
	float GetSpeedY() { return m_fSpeedY; }
	RECT GetBody() { return m_rtBody; }
	int GetDelay() { return m_nDelay; }
	int GetSizeW() { return m_nSizeW; }
	int GetsizeH() { return m_nSizeH; }
	bool GetIsActive() { return m_isActive; }
#pragma endregion


#pragma region Set
	void SetPosX(float X) { m_fPosX = X; }
	void SetPosY(float Y) { m_fPosY = Y; }
	void SetSpeedX(float X) { m_fSpeedX = X; }
	void SetSpeedY(float Y) { m_fSpeedY = Y; }
	void SetBody(RECT rtBody) { m_rtBody = rtBody; }
	void SetDelay(int Delay) { m_nDelay = Delay; }
	void SetSizeW(int Width) { m_nSizeW = Width; }
	void SetSizeH(int Height) { m_nSizeH = Height; }
	void SetIsActive(bool isActive) { m_isActive = isActive; }
#pragma endregion


	
	cGameobject();
	~cGameobject();

	void Update();
	void Render();
	void Move();
};

