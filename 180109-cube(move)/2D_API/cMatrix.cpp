#include "stdafx.h"
#include "cMatrix.h"
#include "cVector3.h"


cMatrix::cMatrix()
{
}


cMatrix::cMatrix(int nDimension)
{
	Resize(nDimension);
}

cMatrix::~cMatrix()
{
}

bool cMatrix::operator==(cMatrix& mat)
{
	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			if (fabs((*this)[i][j] - mat[i][j]) > FLT_EPSILON)
				return false;
		}
	}

	return true;
}

bool cMatrix::operator!=(cMatrix& mat)
{
	return !((*this) == mat);
}

cMatrix cMatrix::operator+(cMatrix& mat)
{
	cMatrix matRet(m_vecRow.size());

	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			matRet[i][j] = (*this)[i][j] + mat[i][j];
		}
	}

	return matRet;
}

cMatrix cMatrix::operator-(cMatrix& mat)
{
	cMatrix matRet(m_vecRow.size());

	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			matRet[i][j] = (*this)[i][j] - mat[i][j];
		}
	}

	return matRet;
}

cMatrix cMatrix::operator*(float f)
{
	cMatrix matRet(m_vecRow.size());

	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			matRet[i][j] = (*this)[i][j] * f;
		}
	}

	return matRet;
}

cMatrix operator * (float f, cMatrix& mat)
{
	return mat * f;
}

cMatrix cMatrix::operator*(cMatrix& mat)
{
	cMatrix matRet(m_vecRow.size());

	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			matRet[i][j] = 0;
			for (int k = 0; k < m_vecRow.size(); ++k)
			{
				matRet[i][j] += (*this)[i][k] * mat[k][j];
			}
		}
	}
	return matRet;
}

cMatrix cMatrix::Identity(int dimension)
{
	cMatrix matRet(dimension);

	for (int i = 0; i < dimension; ++i)
	{
		matRet[i][i] = 1;
	}
	
	return matRet;
}

void cMatrix::Resize(int nDimension)
{
	m_vecRow.resize(nDimension);

	for (int i = 0; i < nDimension; ++i)
	{
		m_vecRow[i].Resize(nDimension);
	}
}

void cMatrix::Random()
{
	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
			(*this)[i][j] = ((rand() % 1001) - 500) / 100.f;
	}
}

cMatrix cMatrix::Inverse(OUT float& determinant)
{
	determinant = Determinant();

	if (fabs(determinant) < FLT_EPSILON)
	{
		return cMatrix::Identity(m_vecRow.size());
	}
	return (1 / determinant) * Adjoint();
}

cMatrix cMatrix::Transpose()
{
	return cMatrix();
}

float cMatrix::Determinant()
{
	if (m_vecRow.size() == 2)
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	float fDeterminant = 0;
	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		fDeterminant += (*this)[i][0] * Cofactor(i, 0);
	}
	return fDeterminant;
}

float cMatrix::Cofactor(int row, int col)
{
	int nConst = 1;
	if ((row + col) % 2 == 1)
		nConst = -1;

	return nConst * Minor(row, col);
}

float cMatrix::Minor(int row, int col)
{
	int nMinorRow = 0;
	int nMinorCol = 0;

	cMatrix mat(m_vecRow.size() - 1);
	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		if (i == row) continue;

		nMinorCol = 0;
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			if (j == col) continue;
			mat[nMinorRow][nMinorCol] = (*this)[i][j];
			++nMinorCol;
		}
		++nMinorRow;
	}

	return mat.Determinant();
}

cMatrix cMatrix::Adjoint()
{
	cMatrix matRet(m_vecRow.size());

	for (int i = 0; i < m_vecRow.size(); ++i)
	{
		for (int j = 0; j < m_vecRow.size(); ++j)
		{
			matRet[i][j] = Cofactor(j, i);
		}
	}
	return matRet;
}

cMatrix cMatrix::Translation(float x, float y, float z)
{
	cMatrix matRet = cMatrix::Identity(4);

	matRet[3][0] = x;
	matRet[3][1] = y;
	matRet[3][2] = z;

	return matRet;
}

cMatrix cMatrix::Translation(cVector3 v)
{
	//cMatrix matRet = cMatrix::Identity(4);

	//matRet[3][0] = v.x;
	//matRet[3][1] = v.y;
	//matRet[3][2] = v.z;

	//return matRet;

	return Translation(v.x, v.y, v.z);
}

cMatrix cMatrix::RotateX(float angle)
{
	cMatrix matRet = cMatrix::Identity(4);

	matRet[1][1] = cosf(angle);
	matRet[1][2] = sinf(angle);
	matRet[2][1] = -sinf(angle);
	matRet[2][2] = cosf(angle);

	return matRet;
}

cMatrix cMatrix::RotateY(float angle)
{
	cMatrix matRet = cMatrix::Identity(4);

	matRet[0][0] = cosf(angle);
	matRet[0][2] = -sinf(angle);
	matRet[2][0] = sinf(angle);
	matRet[2][2] = cosf(angle);

	return matRet;
}

cMatrix cMatrix::RotateZ(float angle)
{
	cMatrix matRet = cMatrix::Identity(4);

	matRet[0][0] = cosf(angle);
	matRet[0][1] = sinf(angle);
	matRet[1][0] = -sinf(angle);
	matRet[1][1] = cosf(angle);

	return matRet;
}

cMatrix cMatrix::Scale(float x, float y, float z)
{
	cMatrix matRet = cMatrix::Identity(4);

	matRet[0][0] = x;
	matRet[1][1] = y;
	matRet[2][2] = z;

	return matRet;
}

cMatrix cMatrix::View(cVector3* pEye, cVector3* pLookAt, cVector3* pUp)
{
	cMatrix matRet(4);

	cVector3 l = *pLookAt - *pEye;
	cVector3 r = cVector3::Cross(*pUp, l).Normalize();
	cVector3 u = cVector3::Cross(l, r).Normalize();

	matRet[0][0] = r.x; matRet[0][1] = u.x; matRet[0][2] = l.x;
	matRet[1][0] = r.y; matRet[1][1] = u.y; matRet[1][2] = l.y;
	matRet[2][0] = r.z; matRet[2][1] = u.z; matRet[2][2] = l.z;

	matRet[3][0] = -cVector3::Dot(r, *pEye);
	matRet[3][1] = -cVector3::Dot(u, *pEye);
	matRet[3][2] = -cVector3::Dot(l, *pEye);
	matRet[3][3] = 1.0f;

	return matRet;
}

cMatrix cMatrix::Projection(float fovY, float aspect, float nearZ, float farZ)
{
	cMatrix matRet(4);

	float sy = 1.0f / tanf(fovY / 2.0f);
	float sx = sy / aspect;

	matRet[0][0] = sx;
	matRet[1][1] = sy;
	matRet[2][2] = farZ / (farZ - nearZ);
	matRet[2][3] = 1.0f;
	matRet[3][2] = (-farZ * nearZ) / (farZ - nearZ);

	return matRet;
}

cMatrix cMatrix::Viewport(float x, float y, float w, float h, float minZ, float maxZ)
{
	cMatrix matRet(4);

	matRet[0][0] = w / 2.0f;
	matRet[1][1] = -h / 2.0f;
	matRet[2][2] = maxZ - minZ;

	matRet[3][0] = x + w / 2.0f;
	matRet[3][1] = y + h / 2.0f;
	matRet[3][2] = minZ;
	matRet[3][3] = 1.0f;

	return matRet;
}