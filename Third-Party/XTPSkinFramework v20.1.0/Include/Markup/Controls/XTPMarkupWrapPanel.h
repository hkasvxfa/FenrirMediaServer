// XTPMarkupWrapPanel.h: interface for the CXTPMarkupWrapPanel class.
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
#if !defined(__XTPMARKUPWRAPPANEL_H__)
#	define __XTPMARKUPWRAPPANEL_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPMarkupDependencyProperty;
class CXTPMarkupDrawingContext;

//===========================================================================
// Summary:
//     CXTPMarkupWrapPanel is a CXTPMarkupPanel derived class.
//     It implements the WrapPanel XAML Tag.
//===========================================================================
class _XTP_EXT_CLASS CXTPMarkupWrapPanel : public CXTPMarkupPanel
{
	DECLARE_MARKUPCLASS(CXTPMarkupWrapPanel)
protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPMarkupWrapPanel object.
	//-----------------------------------------------------------------------
	CXTPMarkupWrapPanel();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPMarkupWrapPanel object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	virtual ~CXTPMarkupWrapPanel();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the orientation of child elements inside WrapPanel.
	// Parameters:
	//     orientation - An XTPMarkupOrientation enumeration value;
	//                   xtpMarkupOrientationHorizontal to position elements horizontally,
	//                   xtpMarkupOrientationVertical to position elements vertically.
	//-----------------------------------------------------------------------
	void SetOrientation(XTPMarkupOrientation orientation);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the current orientation of child elements inside WrapPanel.
	// Returns:
	//     An XTPMarkupOrientation enumeration value;
	//     xtpMarkupOrientationHorizontal if elements are positioned horizontally,
	//     xtpMarkupOrientationVertical if elements are positioned vertically.
	//-----------------------------------------------------------------------
	XTPMarkupOrientation GetOrientation() const;

protected:
	//{{AFX_CODEJOCK_PRIVATE
	// Implementation

	virtual CSize MeasureOverride(CXTPMarkupDrawingContext* pDC, CSize szAvailableSize);
	virtual CSize ArrangeOverride(CSize szFinalSize);

protected:
	void ArrangeLine(int nPanelHeight, int nLineHeight, int nFirstElement, int nCount);

public:
	static CXTPMarkupDependencyProperty* m_pOrientationProperty;
	static CXTPMarkupDependencyProperty* m_pItemHeightProperty;
	static CXTPMarkupDependencyProperty* m_pItemWidthProperty;

	//}}AFX_CODEJOCK_PRIVATE

	//{{AFX_CODEJOCK_PRIVATE
public:
	DECLARE_DISPATCH_MAP()
#	ifdef _XTP_ACTIVEX
	DECLARE_INTERFACE_MAP()
	DECLARE_OLETYPELIB_EX(CXTPMarkupWrapPanel);
#	endif

	afx_msg long OleGetOrientation();
	afx_msg void OleSetOrientation(long nValue);

	//}}AFX_CODEJOCK_PRIVATE
};

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(__XTPMARKUPWRAPPANEL_H__)
