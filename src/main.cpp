#include<Qapplication>
#include"view/gameField.h"
#include"controller/GameController.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Field f;
	GameController controller(f);
	GameField * game_field = new GameField(f);

	//connect(game_field, &GameField::cellCliked, &controller, &GameController::click_Processing);

	game_field->show();

	return app.exec();

}