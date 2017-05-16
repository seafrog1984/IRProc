
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "IRProc.h"

#include "MainFrm.h"

#include"IRProcView.h"
#include "IMGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_IMGProc, &CMainFrame::OnImgproc)
	ON_UPDATE_COMMAND_UI(ID_IMGProc, &CMainFrame::OnUpdateImgproc)
	ON_COMMAND(ID_INFOManage, &CMainFrame::OnInfomanage)
	ON_UPDATE_COMMAND_UI(ID_INFOManage, &CMainFrame::OnUpdateInfomanage)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.x = 0;
	cs.y = 0;
	//cs.style &= ~WS_MAXIMIZEBOX;
	//cs.style &= ~WS_SIZEBOX;

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

void CMainFrame::SwitchToForm(int nForm)
{
	//获取原来的活动窗体的视图句柄 
	CView* pOldActiveView = GetActiveView();
	//获取由"nForm"标识的窗体所对应的视图句柄 
	CView* pNewActiveView = (CView*)GetDlgItem(nForm);
	//若视图句柄为空，则创建一新的。 
	if (pNewActiveView == NULL)
	{
		if (nForm == IDD_INFO)
			pNewActiveView = (CView*)new CIRProcView;
		if (nForm == IDD_IMG)
			pNewActiveView = (CView*)new CIMGView;
		CCreateContext context;
		context.m_pCurrentDoc = pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, 0L,
			CFrameWnd::rectDefault,
			this, nForm, &context);
		pNewActiveView->OnInitialUpdate();
	}
	//选择pNewActiveView为活动窗体 
	SetActiveView(pNewActiveView);
	//显示活动窗体，隐藏非活动窗体 
	pNewActiveView->ShowWindow(SW_SHOW);
	pOldActiveView->ShowWindow(SW_HIDE);
	int ID;
	if (pOldActiveView->GetRuntimeClass() == RUNTIME_CLASS(CIRProcView))
		ID = IDD_INFO;
	if (pOldActiveView->GetRuntimeClass() == RUNTIME_CLASS(CIMGView))
		ID = IDD_IMG;
	//设置窗体的ID号 
	pOldActiveView->SetDlgCtrlID(ID);
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
}



void CMainFrame::OnImgproc()
{
	// TODO:  在此添加命令处理程序代码
	//通过IsKindOf函数确定当前活动窗口是否是第一个窗口，如是，则无须切换， 
	//否则将通过SwitchToForm函数将当前活动窗口切换到"IDD_SWITCHFORM_FORM" 
	//标识的第二个窗体。 
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CIMGView)))
		return;
	SwitchToForm(IDD_IMG);
	CIMGView *p = (CIMGView *)GetDlgItem(IDD_IMG);
	p->OnBnClickedOpen();

}


void CMainFrame::OnUpdateImgproc(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	//通过IsKindOf函数判断当前活动窗口是否是第一个窗体，如是则将其选中。 
	pCmdUI->SetCheck(GetActiveView()->IsKindOf(RUNTIME_CLASS(CIMGView)));
}


void CMainFrame::OnInfomanage()
{
	// TODO:  在此添加命令处理程序代码
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CIRProcView)))
		return;
	SwitchToForm(IDD_INFO);
}


void CMainFrame::OnUpdateInfomanage(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(GetActiveView()->IsKindOf(RUNTIME_CLASS(CIRProcView)));
}


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int cx = GetSystemMetrics(SM_CXSCREEN);

	int cy = GetSystemMetrics(SM_CYSCREEN);

	lpMMI->ptMinTrackSize.x = cx;

	lpMMI->ptMaxTrackSize.x = cx;

	lpMMI->ptMaxTrackSize.y = cy;

	lpMMI->ptMinTrackSize.y = cy;


	CFrameWnd::OnGetMinMaxInfo(lpMMI);

}
