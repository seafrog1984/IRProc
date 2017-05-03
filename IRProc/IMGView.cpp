// IMGView.cpp : ʵ���ļ�
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


void CIMGView::OnBnClickedOpen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, _T("image files (*.bmp; *.jpg) |*.bmp; *.jpg | All Files (*.*) |*.*||"), NULL);                            // ѡ��ͼƬ��Լ��     
	dlg.m_ofn.lpstrTitle = _T("Open Image");// ���ļ��Ի���ı�����     
	if (dlg.DoModal() != IDOK)             // �ж��Ƿ���ͼƬ         
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
	//���������ʾ
	imshow("view", img1);
}
