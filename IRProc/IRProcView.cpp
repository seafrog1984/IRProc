
// IRProcView.cpp : CIRProcView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CIRProcView 构造/析构

CIRProcView::CIRProcView()
	: CFormView(CIRProcView::IDD)
{
	// TODO:  在此处添加构造代码

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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CIRProcView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CIRProcView 诊断

#ifdef _DEBUG
void CIRProcView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIRProcView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CIRProcDoc* CIRProcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIRProcDoc)));
	return (CIRProcDoc*)m_pDocument;
}
#endif //_DEBUG


// CIRProcView 消息处理程序
