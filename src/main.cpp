#include<Qapplication>
#include"view/gameField.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Field f;
	f.setCell(1,1, typeCell::X);
	f.setCell(2, 0, typeCell::O);
	f.setCell(2, 1, typeCell::O);
	f.setCell(2, 2, typeCell::O);

	GameField * game_field = new GameField(f);

	game_field->show();

	return app.exec();

}