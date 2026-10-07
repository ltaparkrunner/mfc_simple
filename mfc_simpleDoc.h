
// mfc_simpleDoc.h: интерфейс класса CmfcsimpleDoc 
//


#pragma once

struct SLine {
    CArray<CPoint, CPoint> m_points;

    // 1. Конструктор по умолчанию (обязателен)
    SLine() {}

    // 2. Конструктор копирования
    SLine(const SLine& src) {
        m_points.Copy(src.m_points);
    }

    // 3. Оператор присваивания (именно его требует компилятор)
    SLine& operator=(const SLine& src) {
        if (this != &src) {
            m_points.Copy(src.m_points); // Явно копируем элементы массива
        }
        return *this;
    }
};

class CmfcsimpleDoc : public CDocument
{
protected: // создать только из сериализации
	CmfcsimpleDoc() noexcept;
	DECLARE_DYNCREATE(CmfcsimpleDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CmfcsimpleDoc();
    CArray<SLine, SLine&> m_lines; // Список всех нарисованных линий
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
