#include"gameField.h"
#include <QtGui>

void GameField::drawCell(QPainter& painter, int row, int col, typeCell type)
{

	const int W = size().width(), H = size().height();

	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(3);
	painter.setPen(pen);

	switch (type)
	{
	case typeCell::EMPTY:
		painter.drawRect(row * W / 3, col * H / 3, W / 3, H / 3);
		break;
	case typeCell::X:
		pen.setColor(Qt::red);
		pen.setWidth(10);
		painter.setPen(pen);
		painter.drawLine(row, col, row * 2, col * 2);

		break;
	case typeCell::O:
		break;
	default:
		break;
	}

}

GameField::GameField(const Field& field, QWidget* parent):
	field_(field),
	QWidget(parent)
{
	width_ = size().width();

	resize(600, 600);

}

void GameField::paintEvent(QPaintEvent* event)
{
	QPainter p(this);

	const int W = size().width(), H = size().height();
	p.fillRect(0, 0, W, H, QColor(255, 255, 255, 255));
	QPen pen;

	pen.setColor(Qt::black);

	p.setPen(pen);

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			typeCell type = field_.getCell(i, j).getType();
			drawCell(p, j, i, type);
		}
	}

}

