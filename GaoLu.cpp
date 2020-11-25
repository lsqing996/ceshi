// GaoLu.cpp: implementation of the CGaoLu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GaoLuWenDuJianCe.h"
#include "GaoLu.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define  PI 3.141593

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGaoLu::CGaoLu()
{
	m_YD.x = 300;
 	m_YD.y = 120;
	m_HJMYD.x = m_YD.x + 1100;
	m_HJMYD.y = m_YD.y + 280;
	m_QXYD.x = m_YD.x - 100;
	m_QXYD.y = m_YD.y + 800;
	InitialDataWenDu();
	m_bj = 0;
 	m_kx = 1000.0/10000;
 	m_ky = -1000.0/10000;
}

CGaoLu::~CGaoLu()
{

}

void CGaoLu::Draw(CDC *p)
{
	m_nZB = 0;
	m_temp.x = -200;
 	m_temp.y = 200;

	pDC = p;
	DrawGaoLu();
	DrawHengJieMian(m_temp);
	DrawHengJieMian(CPoint(-m_temp.x,m_temp.y));
	DrawHengJieMian(CPoint(m_temp.x,-m_temp.y));
	DrawHengJieMian(CPoint(-m_temp.x,-m_temp.y));
	if(m_bj)
		DrawWenDuQuXian(m_bj-1);
}

void CGaoLu::DrawGaoLu()
{
	int x,y;
	int r;//�ھ������أ�
	r = 200;
	x = m_YD.x;
	y = m_YD.y;
	pDC->MoveTo(x,y);
	y -= 3*r*m_ky;
	pDC->LineTo(x,y);
	x -= r*m_kx;
	y += r*m_ky;
	pDC->LineTo(x,y);

	x = m_YD.x + r*m_kx;
	y = m_YD.y;
	pDC->MoveTo(x,y);
	y -= 3*r*m_ky;
	pDC->LineTo(x,y);
	x += r*m_kx;
	y += r*m_ky;
	pDC->LineTo(x,y);//������ʯ����̿��ʯ��ʯ���

//====================================================
	x = m_YD.x - 2*r*m_kx;
	y = m_YD.y - 2*r*m_ky;
	pDC->MoveTo(x,y);
	x += r*m_kx;
	y -= r*m_ky;
	pDC->LineTo(x,y);//������¯����
	x -= 1.5*r*m_kx;
	y -= 6*r*m_ky;
	pDC->LineTo(x,y);
	x += 1.5*r*m_kx;
	y -= 2*r*m_ky;
	pDC->LineTo(x,y);
	x -= r*m_kx;
	pDC->LineTo(x,y);
	y -= r*m_ky;
	pDC->MoveTo(x,y);
	x += r*m_kx;
	pDC->LineTo(x,y);//���ȿ��������
	y -= 3*r*m_ky;
	pDC->LineTo(x,y);
	x -= r/2*m_kx;
	pDC->LineTo(x,y);
	y -= r*m_ky;
	pDC->MoveTo(x,y);
	x += 2*r*m_kx;
	pDC->LineTo(x,y);//��������

//=============================================
	x = m_YD.x + 3*r*m_kx;
	y = m_YD.y - 2*r*m_ky;
	pDC->MoveTo(x,y);
	x -= r*m_kx;
	y -= r*m_ky;
	pDC->LineTo(x,y);//���Ҳ��¯����
	x += 1.5*r*m_kx;
	y -= 6*r*m_ky;
	pDC->LineTo(x,y);
	x -= 1.5*r*m_kx;
	y -= 2*r*m_ky;
	pDC->LineTo(x,y);
	x += r*m_kx;
	pDC->LineTo(x,y);
	y -= r*m_ky;
	pDC->MoveTo(x,y);
	x -= r*m_kx;
	pDC->LineTo(x,y);//�������
	y -= r*m_ky;
	pDC->LineTo(x,y);
	x += r*m_kx;
	pDC->LineTo(x,y);
	y -= r*m_ky;
	pDC->MoveTo(x,y);
	x -= r*m_kx;
	pDC->LineTo(x,y);//��������
	y -= 2*r*m_ky;
	pDC->LineTo(x,y);
	x -= 2*r*m_kx;
	pDC->LineTo(x,y);

//=============================================
//=============================================
	x = m_YD.x + r/2*m_kx;
	y = m_YD.y + 1.5*r*m_ky;
	pDC->MoveTo(x,y);
	y -= 2*r*m_ky;
	pDC->LineTo(x,y);
	x -= r/4*m_kx;
	y += r/4*m_ky;
	pDC->MoveTo(x,y);
	x += r/4*m_kx;
	y -= r/4*m_ky;
	pDC->LineTo(x,y);
	x += r/4*m_kx;
	y += r/4*m_ky;
	pDC->LineTo(x,y);//������ʯ����̿��ʯ��ʯ��ڼ�ͷ

	x = m_YD.x - 1.5*r*m_kx;
	y = m_YD.y - 2*r*m_ky;
	pDC->MoveTo(x,y);
	x -= r*m_kx;
	y += r*m_ky;
	pDC->LineTo(x,y);
	y -= r/4*m_ky;
	pDC->MoveTo(x,y);
	y += r/4*m_ky;
	pDC->LineTo(x,y);
	x += r/4*m_kx;
	pDC->LineTo(x,y);//����߸�¯�����ͷ

	x = m_YD.x + 2.5*r*m_kx;
	y = m_YD.y - 2*r*m_ky;
	pDC->MoveTo(x,y);
	x += r*m_kx;
	y += r*m_ky;
	pDC->LineTo(x,y);
	x -= r/4*m_kx;
	pDC->MoveTo(x,y);
	x += r/4*m_kx;
	pDC->LineTo(x,y);
	y -= r/4*m_ky;
	pDC->LineTo(x,y);//���ұ߸�¯�����ͷ

	x = m_YD.x - 4*r*m_kx;
	y = m_YD.y - 23*r/2*m_ky;
	pDC->MoveTo(x,y);
	x += 1.5*r*m_kx;
	pDC->LineTo(x,y);
	x -= 0.4*r*m_kx;
	y += 0.2*r*m_ky;
	pDC->MoveTo(x,y);
	x += 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);
	x -= 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);//������ȿ�������ڼ�ͷ

	x = m_YD.x - 2*r*m_kx;
	y = m_YD.y - 31*r/2*m_ky;
	pDC->MoveTo(x,y);
	x -= 1.5*r*m_kx;
	pDC->LineTo(x,y);
	x += 0.4*r*m_kx;
	y += 0.2*r*m_ky;
	pDC->MoveTo(x,y);
	x -= 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);
	x += 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);//����߳����ڼ�ͷ

	x = m_YD.x + 4.5*r*m_kx;
	y = m_YD.y - 23*r/2*m_ky;
	pDC->MoveTo(x,y);
	x -= 1.5*r*m_kx;
	pDC->LineTo(x,y);
	x += 0.4*r*m_kx;
	y += 0.2*r*m_ky;
	pDC->MoveTo(x,y);
	x -= 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);
	x += 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);//���ұ߽���ڼ�ͷ

	x = m_YD.x + 3*r*m_kx;
	y = m_YD.y - 13.5*r*m_ky;
	pDC->MoveTo(x,y);
	x += 1.5*r*m_kx;
	pDC->LineTo(x,y);
	x -= 0.4*r*m_kx;
	y += 0.2*r*m_ky;
	pDC->MoveTo(x,y);
	x += 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);
	x -= 0.4*r*m_kx;
	y -= 0.2*r*m_ky;
	pDC->LineTo(x,y);//���ұ߳����ڼ�ͷ

//=============================================
//=============================================
	CString str;
	CFont ft;
	ft.CreatePointFont(150,_T("����"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));

	str.Format("����ʯ����̿��ʯ��ʯ");
	pDC->TextOut(m_YD.x - 4*r*m_kx,m_YD.y + 2.5*r*m_ky,str);

	str.Format("��¯����");
	pDC->TextOut(m_YD.x - 5*r*m_kx,m_YD.y + 0.5*r*m_ky,str);

	str.Format("��¯����");
	pDC->TextOut(m_YD.x + 2*r*m_kx,m_YD.y + 0.5*r*m_ky,str);

	str.Format("�ȿ��������");
	pDC->TextOut(m_YD.x - 10*r*m_kx,m_YD.y - 11*r*m_ky,str);

	str.Format("�����");
	pDC->TextOut(m_YD.x + 5*r*m_kx,m_YD.y - 11*r*m_ky,str);

	str.Format("������");
	pDC->TextOut(m_YD.x - 7*r*m_kx,m_YD.y - 15*r*m_ky,str);

	str.Format("������");
	pDC->TextOut(m_YD.x + 5*r*m_kx,m_YD.y - 13*r*m_ky,str);
	
	str.Format("����¯����ʾ��ͼ��");
	pDC->TextOut(m_YD.x-3.5*r*m_kx,m_YD.y-17*r*m_ky,str);
}

void CGaoLu::DrawHengJieMian(CPoint point)
{
	int i;
	float x,y,r;
	float temp_r;
	temp_r = 80;
	x = m_HJMYD.x + point.x;
	y = m_HJMYD.y - point.y;
	r = 100;
	pDC->Ellipse(x-r,y-r,x+r,y+r);//����Բ

	x = m_HJMYD.x + point.x;
	y = m_HJMYD.y - point.y;
	r = 60;
	pDC->Ellipse(x-r,y-r,x+r,y+r);//����Բ

	for (i=0;i<8;i++)
	{
		x = m_HJMYD.x + point.x + temp_r*cos(45*i*PI/180);
		y = m_HJMYD.y - point.y + temp_r*sin(45*i*PI/180);
		r = 10;
		pDC->Ellipse(x-r,y-r,x+r,y+r);//���˸��ȵ�ż
		m_ZB[m_nZB][0] = x;
		m_ZB[m_nZB][1] = y;
		m_nZB++;
	}

	CString str;
	str.Format("��һ��");
	pDC->TextOut(1170,200,str);
	str.Format("�ڶ���");
	pDC->TextOut(1570,200,str);
	str.Format("������");
	pDC->TextOut(1170,600,str);
	str.Format("���Ĳ�");
	pDC->TextOut(1570,600,str);
}

void CGaoLu::DrawWenDuQuXian(int k)
{
	int i;
	int x1,y1;
	float x,y,r;
	x1 = m_QXYD.x;
	y1 = m_QXYD.y;
	pDC->MoveTo(x1,y1);
	x1 += 400;
	pDC->LineTo(x1,y1);
	x1 -= 400;
	pDC->MoveTo(x1,y1);
	y1 -= 400;
	pDC->LineTo(x1,y1);

	y1 += 400;
	pDC->MoveTo(x1,y1);
	for(i=0;i<10;i++)
	{
 		x = m_QXYD.x + i*m_kx*200;
 		y = m_QXYD.y + m_WD[i][k]*m_ky*20;
		pDC->LineTo(x,y);
	}

	CString str;
	str.Format("��%d��",k/8+1);
	pDC->TextOut(85,870,str);
	str.Format("��%d���ȵ�ż",k%8+1);
	pDC->TextOut(85,900,str);
}

void CGaoLu::InitialDataWenDu()
{
	int i,j;
	i = 0;
	j = 0;
	FILE *fp;
	fp = fopen(".\\GLWD.txt","r");
	for (i=0;i<20;i++)
		for(j=0;j<32;j++)
			fscanf(fp,"%f",&m_WD[i][j]);
		fclose(fp);
}

int CGaoLu::PanDuan(CPoint point)
{
	float d[100];
	float x1,y1,x2,y2;
	int i,j;
	for(i=0;i<32;i++)
	{
		x1 = m_ZB[i][0];
		y1 = m_ZB[i][1];
		x2 = point.x;
		y2 = point.y;
		d[i] = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		if(d[i] < 10)
			return i+1;
	}
	return 0;
}
