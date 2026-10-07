
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

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в mfc_simpleView.cpp
inline CmfcsimpleDoc* CmfcsimpleView::GetDocument() const
   { return reinterpret_cast<CmfcsimpleDoc*>(m_pDocument); }
#endif

