// IMGView.cpp : 实现文件
//

#include "stdafx.h"
#include "IRProc.h"
#include "IMGView.h"
#include <fstream>

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

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
	ON_BN_CLICKED(IDC_OPEN, &CIMGView::OnBnClickedOpen)
END_MESSAGE_MAP()


// CIMGView 诊断

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


// CIMGView 消息处理程序


void CIMGView::OnBnClickedOpen()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, _T("image files (*.bmp; *.jpg) |*.bmp; *.jpg | All Files (*.*) |*.*||"), NULL);                            // 选项图片的约定     
	dlg.m_ofn.lpstrTitle = _T("Open Image");// 打开文件对话框的标题名     
	if (dlg.DoModal() != IDOK)             // 判断是否获得图片         
		return;
	CString m_path = dlg.GetPathName();

	Mat src = imread((LPSTR)(LPCSTR)m_path);

	Mat img1;
	CRect rect;
	GetDlgItem(IDC_PIC)->GetClientRect(&rect);

	resize(src, img1, Size(rect.Width(), rect.Height()), 0, 0);

	/*ofstream out("F:\\img.txt", ios::out);

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			out << i << "," << j << src.at<uchar>(i, j) << endl;
		}
	}*/
	//载入后先显示
	imshow("view", img1);
}
