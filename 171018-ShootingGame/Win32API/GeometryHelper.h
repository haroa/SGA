#pragma once
#include "cSingletonBase.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

inline double sq(double x) { return x * x; }

class GeometryHelper : public cSingletonBase<GeometryHelper>
{
public:

    UnitPos GetCenterPointWindow();

    double GetVectorSpeed(UnitPos BeginPos, UnitPos DestPos);
    UnitPos GetCoordFromAngle(double Degree, double Length);
    double GetAngleFromCoord(UnitPos BeginPos, UnitPos DestPos);
    double Degree2Rad(double Degree);
    double Rad2Degree(double Rad);

    double GetDistance(UnitPos Pos1, UnitPos Pos2);
    UnitPos GetRotateCoord(UnitPos StartPos, UnitPos DestPos, double DeltaDegree);
};

