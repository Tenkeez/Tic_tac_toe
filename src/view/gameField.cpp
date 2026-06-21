#include"gameField.h"
#include <QtGui>

void GameField::drawCell(QPainter& painter, int row, int col, typeCell type)
{

	const int W = size().width(), H = size().height();

	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(3);
	painter.setPen(pen);

	painter.drawRect(row * W / 3, col * H / 3, W / 3, H / 3);
	if (type == typeCell::X)
		drawX(painter, row, col);
	if (type == typeCell::O)
		drawO(painter,row,col);

}

void GameField::drawX(QPainter& painter, int row, int col)
{
	const int W = size().width(), H = size().height();

	QPen pen;
	pen.setColor(Qt::red);
	pen.setWidth(10);
	painter.setPen(pen);
	const int o = 30;


	QPoint p1((row * W / 3)+o, (col * H / 3)+o);
	QPoint p2(((row +1) * W / 3)-o, ((col+1) * H / 3)-o);
	QLine l1(p1,p2);

	QPoint p3(((row) * W / 3)+o, ((col+1) * H / 3)-o);
	QPoint p4(((row +1) * W / 3)-o, ((col) * H / 3)+o);
	QLine l2(p3, p4);
	painter.drawLine(l1);
	painter.drawLine(l2);
}

void GameField::drawO(QPainter& painter, int row, int col)
{
	const int W = size().width(), H = size().height();

	QPen pen;
	pen.setColor(Qt::blue);
	pen.setWidth(10);
	painter.setPen(pen);
	QRectF r(row * W / 3, col * H / 3, W / 3, H / 3);
	painter.drawEllipse(r.center(),W/9,H/9);

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


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			typeCell type = field_.getCell(i, j).getType();
			drawCell(p, j, i, type);
		}
	}

}

