#pragma once
#include "SingletonBase.h"
#include "GameObject.h"

#define _PERFECTLY_ELASTIC_COLLISION

#ifdef _PERFECTLY_ELASTIC_COLLISION             //  ����ź���浹
    #define RESTITUTION_COEF    1.0f
#elif _PERFECTLY_INELASTIC_COLLISION            //  ������ź���浹
    #define RESTITUTION_COEF    0.0f
#else
    #define RESTITUTION_COEF    0.75f           //  �浹���
#endif

class PhysicsHelper : public SingletonBase<PhysicsHelper>
{
public:
    bool    IsCollision(GameObject* Unit1, GameObject* Unit2);

    template <class T>
    void BoxCollider(T VecUnit1, vector<T> VecUnit2, int DmgDeal1, int DmgDeal2);

    template <class T>
    void    BoxCollider(vector<T> VecUnit1, vector<T> VecUnit2, int DmgDeal1, int DmgDeal2);
};