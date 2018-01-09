#pragma once

class cVector3;

class cMatrix
{
private:
	class cRow
	{
	private:
		vector<float> m_vecColumn;

	public:
		cRow() {}
		~cRow() {}

		float& operator [] (int nIndex)
		{
			return m_vecColumn[nIndex];
		}

		void Resize(int nDimension)
		{
			m_vecColumn.resize(nDimension);
		}
	};

private:
	vector<cRow> m_vecRow;

public:
	cMatrix();
	cMatrix(int nDimension);
	~cMatrix();

	cRow& operator [] (int nIndex)
	{
		return m_vecRow[nIndex];
	}

	bool operator == (cMatrix& mat);
	bool operator != (cMatrix& mat);
	cMatrix operator + (cMatrix& mat);
	cMatrix operator - (cMatrix& mat);
	cMatrix operator * (float f);
	friend cMatrix operator * (float f, cMatrix& mat);
	cMatrix operator * (cMatrix& mat);

	static cMatrix Identity(int dimension);
	void Resize(int nDimension);
	void Random();

	cMatrix Inverse(OUT float& determinant);
	cMatrix Transpose();
	float Determinant();
	float Cofactor(int row, int col);
	float Minor(int row, int col);
	cMatrix Adjoint();

	static	cMatrix Translation(float x, float y, float z);
	static	cMatrix Translation(cVector3 v);
	static	cMatrix RotateX(float angle);
	static	cMatrix RotateY(float angle);
	static	cMatrix RotateZ(float angle);
	static	cMatrix Scale(float x, float y, float z);

	static	cMatrix	View(cVector3* pEye/* 0, 0, -5 */, cVector3* pLookAt /* 0, 0, 0 */, cVector3* pUp/* 0, 1, 0 */);
	static	cMatrix Projection(float fovY /* 45도 */, float aspect /* 화면 가로사이즈/세로사이즈 */, float nearZ /* 1 */, float farZ /* 1000 */);
	static	cMatrix Viewport(float x /* 0 */, float y /* 0 */, float w /* 화면가로 사이즈 */,
		float h /* 화면 세로 사이즈 */, float minZ /* 0 */, float maxZ /* 1 */);
};