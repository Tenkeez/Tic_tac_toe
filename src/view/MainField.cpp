#include"MainField.h"
#include<Qlayout>
#include<qpushbutton.h>

MainField::MainField(QWidget* parent):
	QWidget(parent)
{
	resize(800, 600);
	field_ = Field();

	controller_ = new GameController(field_);

	controller_->changedBoard = [this]()
		{
			game_field_->update();
		};

	controller_->changeGameMode(true);
	game_field_ = new GameField(field_);
	connect(game_field_, &GameField::cellCliked, this, &MainField::onCellClicked);

	
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(game_field_);

	QHBoxLayout* buttonLayout = new QHBoxLayout();

	QPushButton* button_reset = new QPushButton("reset");
	buttonLayout->addWidget(button_reset);
	QPushButton* button_mode = new QPushButton("mode");
	buttonLayout->addWidget(button_mode);
	mainLayout->addLayout(buttonLayout);

	connect(button_reset, &QPushButton::clicked, this, &MainField::resetGame);
	connect(button_mode, &QPushButton::clicked, this, &MainField::changeModeGame);
	this->setLayout(mainLayout);

}

void MainField::resetGame()
{
	controller_->reset();
}

void MainField::changeModeGame()
{
	if(controller_->checkGameMode()== false)
		controller_->changeGameMode(true);
	else
		controller_->changeGameMode(false);
	resetGame();
}


void MainField::onCellClicked(int row, int col)
{
	controller_->click_Processing(row, col);
}