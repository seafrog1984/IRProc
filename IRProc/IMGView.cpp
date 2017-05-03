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
	//
	//CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, _T("image files (*.bmp; *.jpg) |*.bmp; *.jpg | All Files (*.*) |*.*||"), NULL);                            // 选项图片的约定     
	//dlg.m_ofn.lpstrTitle = _T("Open Image");// 打开文件对话框的标题名     
	//if (dlg.DoModal() != IDOK)             // 判断是否获得图片         
	//	return;
	//CString m_path = dlg.GetPathName();

	//Mat src = imread((LPSTR)(LPCSTR)m_path);
	#define F_TO_C(x)  ((((x)-32.0) * 5.0) / 9.0)
	#define C_TO_F(x)    ((32.0) + ((x) * (9.0/5.0)))
	unsigned short *tmp= (unsigned short*)malloc(320*240*sizeof(short));
	long width=320, height=240;
	ifstream fin("b.dat");

	for (int i = 0; i < width*height; i++)
	{
		fin>> *(tmp+i);
		if (*(tmp+i) == ' ')
			i--;
	}
	
	fin.close();

	Mat src(height, width, CV_8UC1, tmp);
	namedWindow("src");
	imshow("src", src);
	Mat img;
	//	img.create(height, width, CV_16UC1, tmp);
	src.copyTo(img);
	//	cvtColor(src,img , CV_BGR2GRAY);

	Mat dst, g_src(img), g_dst;
	dst.create(img.size(), CV_8UC3);
	g_dst.create(img.size(), CV_8UC1);
	//cvtColor(img, g_src, CV_BGR2GRAY);

	if (tmp)
	{
		
		
		//	SetDlgItemText(IDC_CENTER_TEMP, buf);

		// highly non-optimal conversion from 16-bit to 8-bit

		// Values are in degrees C * 100.0
		// So, 1 deg C would == 100
		// My mind doesn't work well in deg C so I have a F_TO_C conversion
		//
		// topvalue represents the highest temperature value we want to display
		// bottomvalue represents the lowest temperature value we want to display
		//

		bool auto_range = true; // set to false to use manual range...

		// Manual range values
		float topvalue = (int)(F_TO_C(130) * 100.0);
		float bottomvalue = (int)(F_TO_C(50) * 100.0);


		int i, end, col, row;
		float value;
		unsigned short *src = (unsigned short *)tmp;
		//unsigned char  *dest = (unsigned char  *)m_ImageData8;
		unsigned char displayValue;
		end = width * height;  // image size...

		if (auto_range)
		{
			bottomvalue = 99999;
			topvalue = -99999;
			for (i = 0; i < end; i++)
			{
				value = src[i];
				bottomvalue = min(bottomvalue, value);
				topvalue = max(topvalue, value);
			}
		}

		float range = topvalue - bottomvalue;

		if (range != 0)
		{

			for (i = 0; i < end; i++)
			{
				value = *src++;
				// Limit upper + lower values
				if (value < bottomvalue) value = bottomvalue;
				if (value > topvalue)    value = topvalue;
				// Scale to 0..255 for display
				displayValue = ((value - bottomvalue) * 255) / range;

				row = i / width;
				col = i%width;
				g_dst.at<uchar>(row, col) = displayValue;
			}
		}
	}
	//int i, j;
	//for (i = 0; i < dst.rows; i++)
	//{
	//	for (j = 0; j < dst.cols; j++)
	//	{
	//		int tmp = g_src.at<uchar>(i, j);

	//		dst.at<Vec3b>(i, j)[0] = 101.2 - 116.2*cos(tmp*0.08655) + 91.93*sin(tmp*0.08592);
	//		dst.at<Vec3b>(i, j)[1] = 150.9 - 110.9*cos(tmp*0.08457) - 97.33*sin(tmp*0.08457);
	//		dst.at<Vec3b>(i, j)[2] = 125.3 + 59.93*cos(tmp*0.04896) - 130.2*sin(tmp*0.04896);


	//	}
	//}

	namedWindow("test");

	imshow("test", g_dst);


}
