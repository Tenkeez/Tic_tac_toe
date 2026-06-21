#include"MainField.h"
#include<Qlayout>

MainField::MainField(QWidget* parent):
	QWidget(parent)
{
	resize(1920, 1080);
	field_ = Field();
	status_ = statusOfGame();

	controller_ = new GameController(field_);
	controller_->changeGameMode(true);
	game_field_ = new GameField(field_);
	connect(game_field_, &GameField::cellCliked, this, &MainField::onCellClicked);

	
	QHBoxLayout* mainLayout = new QHBoxLayout();
	mainLayout->addWidget(game_field_);
	this->setLayout(mainLayout);

	show();
}


void MainField::onCellClicked(int row, int col)
{
	controller_->click_Processing(row, col);
	game_field_->update();
}