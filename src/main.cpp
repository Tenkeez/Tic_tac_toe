#include<Qapplication>
#include"view/MainField.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainField * main = new MainField();

	main->show();
	return app.exec();

}