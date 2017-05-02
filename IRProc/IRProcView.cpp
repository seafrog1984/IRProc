
// IRProcView.cpp : CIRProcView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "IRProc.h"
#endif

#include "IRProcDoc.h"
#include "IRProcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIRProcView

IMPLEMENT_DYNCREATE(CIRProcView, CFormView)

BEGIN_MESSAGE_MAP(CIRProcView, CFormView)
END_MESSAGE_MAP()

// CIRProcView ����/����

CIRProcView::CIRProcView()
	: CFormView(CIRProcView::IDD)
{
	// TODO:  �ڴ˴���ӹ������

}

CIRProcView::~CIRProcView()
{
}

void CIRProcView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CIRProcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CIRProcView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CIRProcView ���

#ifdef _DEBUG
void CIRProcView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIRProcView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CIRProcDoc* CIRProcView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIRProcDoc)));
	return (CIRProcDoc*)m_pDocument;
}
#endif //_DEBUG


// CIRProcView ��Ϣ�������
