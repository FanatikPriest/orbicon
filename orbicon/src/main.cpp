#include "orbicon_app.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OrbiconApp w;
	w.show();
	return a.exec();
}
