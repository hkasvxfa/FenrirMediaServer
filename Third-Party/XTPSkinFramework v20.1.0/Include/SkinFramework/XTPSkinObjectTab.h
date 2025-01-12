// XTPSkinObjectTab.h: interface for the CXTPSkinObjectTab class.
//
// (c)1998-2021 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPSKINOBJECTTAB_H__)
#	define __XTPSKINOBJECTTAB_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

//===========================================================================
// Summary:
//     CXTPSkinObjectTab is a CXTPSkinObjectFrame derived class.
//     It implements a standard tab control.
//===========================================================================
class _XTP_EXT_CLASS CXTPSkinObjectTab : public CXTPSkinObjectFrame
{
	DECLARE_DYNCREATE(CXTPSkinObjectTab)
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPSkinObjectTab object.
	//-----------------------------------------------------------------------
	CXTPSkinObjectTab();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPSkinObjectTab object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	virtual ~CXTPSkinObjectTab();

protected:
	//{{AFX_CODEJOCK_PRIVATE

	void FillClient(CDC* pDC, CRect rc);
	CRect GetHeaderRect();
	void FillTabFace(CDC* pDC, CRect rcItem, int iItem, int iCount, BOOL bSelected, BOOL bFocused);
	void DrawTab(CDC* pDC, int iItem);
	void DrawTabIcon(CDC* pDC, CRect& rcItem, int iItem);
	void DrawTabText(CDC* pDC, CRect& rcItem, int iItem, int iCount, BOOL bSelected, BOOL bFocused);
	void OnDraw(CDC* pDC);

protected:
	//{{AFX_VIRTUAL(CXTPSkinObjectTab)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CXTPSkinObjectTab)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnPrintClient(WPARAM wParam, LPARAM /*lParam*/);
	afx_msg void OnPaint();
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	int m_nHotItem;
	BOOL m_bPaint;
	//}}AFX_CODEJOCK_PRIVATE
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPSKINOBJECTTAB_H__)
