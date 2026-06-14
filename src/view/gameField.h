#ifndef ___GAMEFIELD_H___
#define ___GAMEFIELD_H___

#include<QWidget	>
#include"model/field.h"

class GameField :public QWidget
{
	Q_OBJECT
private:
	const Field& field_;
	int width_;

private:
	void drawCell(QPainter& painter, int row, int col, typeCell type);
public:
	explicit GameField(const Field& field, QWidget* parent = nullptr);

protected:
	void paintEvent(QPaintEvent* event) override;


};


#endif