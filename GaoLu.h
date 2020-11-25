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
}m_ReDianOu;//�ȵ�ż�ṹ��
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
	CPoint m_YD;//��¯����ԭ��
	CPoint m_HJMYD;//���������ԭ��
	CPoint m_temp,m_QXYD;//������ԭ��
	float m_kx,m_ky;//������
	float m_WD[20][32];
	float m_ZB[32][2];
	int m_nZB;
	int m_bj;//���߱��
	m_ReDianOu m_RDO[5][10];//�ȵ�ż
};

#endif // !defined(AFX_GAOLU_H__4AC0BF32_5E00_403F_9C32_C1E1DF508985__INCLUDED_)
