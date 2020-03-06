#include "stdafx.h"
#include "package_v4.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Package_v4 w;
	w.show();
	return a.exec();
}
