#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "ChartScene.hpp"
#include "GraphicsAxisLineItem.hpp"

#include <iostream>
#include <QtWidgets>

class MainWindow: public QMainWindow
{
private:
	// - Widgets
	QPushButton *testButton;	
	QGraphicsView *chartView;

	// Graphics 
	ChartScene *scene;
	GraphicsAxisLineItem *xAxis;
	
	// - Layout components
	QVBoxLayout *layout;

	
	// ######################################## //
	// Private Member Functions					//
	// ######################################## //
	
	
public:
	// - Constructors
	MainWindow();



// ######################################## //
// SLOTS									//
// ######################################## //
private slots:
	// Opens File Pick Dialog
	void openFileDialog();

	// Opens image file in the given path.
	void openImage(const QString&);

	//
	void changeLine(const QPointF&);
};

#endif
