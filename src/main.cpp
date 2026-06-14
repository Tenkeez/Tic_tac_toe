#include<Qapplication>
#include"view/gameField.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Field f;
	f.setCell(2, 2, typeCell::X);

	GameField * game_field = new GameField(f);

	game_field->show();

	return app.exec();

}