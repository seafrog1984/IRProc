// IMGView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IRProc.h"
#include "IMGView.h"


// CIMGView

IMPLEMENT_DYNCREATE(CIMGView, CFormView)

CIMGView::CIMGView()
	: CFormView(CIMGView::IDD)
{

}

CIMGView::~CIMGView()
{
}

void CIMGView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIMGView, CFormView)
END_MESSAGE_MAP()


// CIMGView ���

#ifdef _DEBUG
void CIMGView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CIMGView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CIMGView ��Ϣ�������
