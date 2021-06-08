#include "MainWindow.hpp"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
	// Create Application
	QApplication app(argc, argv);

	MainWindow window;
	window.show();

	return app.exec();
}
