#pragma once



// CIMGView ������ͼ

class CIMGView : public CFormView
{
	DECLARE_DYNCREATE(CIMGView)

public:
	CIMGView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CIMGView();

public:
	enum { IDD = IDD_IMG };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();

	void SetControlInfo(WORD CtrlID);
	void OnMySize(UINT nType, int cx, int cy);
protected:

	int m_old_cx, m_old_cy;

	CDWordArray m_control_info;
};


