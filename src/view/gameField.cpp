#include"gameField.h"
#include <QtGui>

void GameField::drawCell(QPainter& painter, int row, int col, typeCell type)
{

	const int W = width(), H = height();
	const int CellW = W/3, CellH = H/3;

	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(3);
	painter.setPen(pen);

	painter.drawRect(col*CellW, row * CellH, CellW, CellH);
	if (type == typeCell::X)
		drawX(painter, row, col,CellW,CellH);
	if (type == typeCell::O)
		drawO(painter,row,col, CellW, CellH);

}

void GameField::drawX(QPainter& painter, int row, int col,int CellW,int CellH)
{
	const int centerX = col * CellW + CellW / 2;
	const int centerY = row * CellH + CellH / 2;
	const int offset = qMin(CellW, CellH) / 4; 

	QPen pen(Qt::red, 10);
	pen.setCapStyle(Qt::RoundCap);
	painter.setPen(pen);

	// Диагональ 1
	painter.drawLine(centerX - offset, centerY - offset,
		centerX + offset, centerY + offset);

	// Диагональ 2
	painter.drawLine(centerX + offset, centerY - offset,
		centerX - offset, centerY + offset);
}

void GameField::drawO(QPainter& painter, int row, int col, int CellW, int CellH)
{
	QPen pen;
	pen.setColor(Qt::blue);
	pen.setWidth(10);
	pen.setCapStyle(Qt::RoundCap);
	painter.setPen(pen);

	QRectF r(col * CellW, row * CellH, CellW, CellH);
	painter.drawEllipse(r.center(),CellW/3,CellH/3);

}

GameField::GameField(const Field& field, QWidget* parent):
	field_(field),
	QWidget(parent)
{
	resize(600, 600);

}

void GameField::paintEvent(QPaintEvent* event)
{
	QPainter p(this);

	const int W = size().width(), H = size().height();
	p.fillRect(0, 0, W, H, QColor(255, 255, 255, 255));
	QPen pen;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			typeCell type = field_.getCell(i, j).getType();
			drawCell(p, i, j, type);
		}
	}

}


void GameField::mousePressEvent(QMouseEvent* event)
{
	const int W = width(), H = height();
	const int CellW = W / 3, CellH = H / 3;

	QPoint curentPoint = event->pos();

	int col = curentPoint.x() / CellW;
	int row = curentPoint.y() / CellH;


	qDebug() << "row " << row << " , column " << col;

	emit cellCliked(row, col);
}

