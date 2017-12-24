#include "carcontroler.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CarControler w;
	w.show();
	return a.exec();
}
