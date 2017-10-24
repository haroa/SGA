#pragma once

/*
�̱��� ���� : ���� ��ü ���� ���
�ν��Ͻ��� ȣ�� �� ó�� ȣ��(�ν��Ͻ��� ���� �Ǳ� ��)�� �Ǹ�
�ν��Ͻ��� ���� �ؼ� ��ȯ �Ѵ�.
�ν��Ͻ��� ���� �� ���� ȣ�� �ϰ� �Ǹ� ������ ���� �� �ν��Ͻ��� ��ȯ�Ѵ�.
*/

template <class T> // template<typename T>
class SingletonBase
{
protected:
    // �̱��� �ν��Ͻ� ����
    static T* instance;

    SingletonBase() {};
    ~SingletonBase() {};

public:
    // �̱��� �ν��Ͻ� ��������
    static T* GetInstance();
    // �̱��� �ν��Ͻ� �����ϱ�
    void ReleaseInstance();
};

// �̱��� �ʱ�ȭ
template<typename T>
T* SingletonBase<T>::instance = NULL;

// �̱��� �ν��Ͻ� ��������
template<typename T>
T* SingletonBase<T>::GetInstance()
{
    // �̱��� �ν��Ͻ��� ���� �Ǿ� ���� �ʴٸ� ���� ����
    if (!instance)
        instance = new T;

    return instance;
}

// �̱��� �ν��Ͻ� �����ϱ�
template<typename T>
void SingletonBase<T>::ReleaseInstance()
{
    // �̱��� �ν��Ͻ��� �����Ǿ� �ִٸ� ���� �Ѵ�.
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}