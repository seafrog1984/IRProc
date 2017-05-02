
// IRProcView.h : CIRProcView ��Ľӿ�
//
#include"IRProcDoc.h"
#pragma once

#include "resource.h"


class CIRProcView : public CFormView
{
public: // �������л�����
	CIRProcView();
	DECLARE_DYNCREATE(CIRProcView)

public:
	enum{ IDD = IDD_IRPROC_FORM };

// ����
public:
	CIRProcDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CIRProcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // IRProcView.cpp �еĵ��԰汾
inline CIRProcDoc* CIRProcView::GetDocument() const
   { return reinterpret_cast<CIRProcDoc*>(m_pDocument); }
#endif

