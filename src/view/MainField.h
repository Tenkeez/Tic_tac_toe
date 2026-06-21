#ifndef ___MAINFIELD_H___
#define ___MAINFIELD_H___

#include<QWidget>
#include"gameField.h"
#include"controller/GameController.h"
#include"model/status.h"

class MainField:public QWidget
{
	Q_OBJECT
private:
	Field field_;
	statusOfGame status_;
	GameController* controller_{nullptr};
	GameField* game_field_{ nullptr };
public:
	explicit MainField(QWidget* parent = nullptr);


private slots:
	void onCellClicked(int row, int col);
};

#endif