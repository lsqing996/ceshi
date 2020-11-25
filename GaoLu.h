// GaoLu.h: interface for the CGaoLu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAOLU_H__4AC0BF32_5E00_403F_9C32_C1E1DF508985__INCLUDED_)
#define AFX_GAOLU_H__4AC0BF32_5E00_403F_9C32_C1E1DF508985__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define PI 3.141593
typedef struct
{
	int x,y;
	int r;
}m_ReDianOu;//热电偶结构体
class CGaoLu  
{
public:
	int PanDuan(CPoint point);
	void InitialDataWenDu();
	void DrawWenDuQuXian(int k);
	void DrawHengJieMian(CPoint point);
	void DrawGaoLu();
	void Draw(CDC *p);
	CGaoLu();
	virtual ~CGaoLu();
	CDC *pDC;
	CPoint m_YD;//高炉坐标原点
	CPoint m_HJMYD;//横截面坐标原点
	CPoint m_temp,m_QXYD;//坐标轴原点
	float m_kx,m_ky;//比例尺
	float m_WD[20][32];
	float m_ZB[32][2];
	int m_nZB;
	int m_bj;//曲线标记
	m_ReDianOu m_RDO[5][10];//热电偶
};

#endif // !defined(AFX_GAOLU_H__4AC0BF32_5E00_403F_9C32_C1E1DF508985__INCLUDED_)
