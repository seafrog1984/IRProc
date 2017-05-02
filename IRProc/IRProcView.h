
// IRProcView.h : CIRProcView 类的接口
//
#include"IRProcDoc.h"
#pragma once

#include "resource.h"


class CIRProcView : public CFormView
{
public: // 仅从序列化创建
	CIRProcView();
	DECLARE_DYNCREATE(CIRProcView)

public:
	enum{ IDD = IDD_IRPROC_FORM };

// 特性
public:
	CIRProcDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CIRProcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // IRProcView.cpp 中的调试版本
inline CIRProcDoc* CIRProcView::GetDocument() const
   { return reinterpret_cast<CIRProcDoc*>(m_pDocument); }
#endif

