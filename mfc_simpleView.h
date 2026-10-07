
// mfc_simpleView.h: интерфейс класса CmfcsimpleView
//

#pragma once


class CmfcsimpleView : public CView
{
protected: // создать только из сериализации
	CmfcsimpleView() noexcept;
	DECLARE_DYNCREATE(CmfcsimpleView)

// Атрибуты
public:
	CmfcsimpleDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CmfcsimpleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool m_bDrawing;
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в mfc_simpleView.cpp
inline CmfcsimpleDoc* CmfcsimpleView::GetDocument() const
   { return reinterpret_cast<CmfcsimpleDoc*>(m_pDocument); }
#endif

