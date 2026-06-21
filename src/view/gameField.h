#ifndef ___GAMEFIELD_H___
#define ___GAMEFIELD_H___

#include<QWidget	>
#include"model/field.h"

class GameField :public QWidget
{
	Q_OBJECT
private:
	const Field& field_;

private:
	void drawCell(QPainter& painter, int row, int col, typeCell type);
	void drawX(QPainter& painter, int row, int col, int CellW, int CellH);
	void drawO(QPainter& painter, int row, int col, int CellW, int CellH);
public:
	explicit GameField(const Field& field, QWidget* parent = nullptr);

protected:
	void paintEvent(QPaintEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
};


#endif