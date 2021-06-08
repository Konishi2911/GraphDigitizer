#include "MainWindow.hpp"

// - Constructors
MainWindow::MainWindow()
{
	// Initialize Widgets
	this->testButton = new QPushButton("&Open");
	this->chartView = new QGraphicsView;
	//this->chartView->setMouseTracking(true);

	// Create Graphics View
	this->scene = new ChartScene;
	this->chartView->setScene(scene);

	xAxis = new GraphicsAxisLineItem(10, 5, 50, 40);
	this->scene->addItem(xAxis);	

	// Define Layout
	this->layout = new QVBoxLayout;
	this->layout->addWidget(chartView);
	this->layout->addWidget(testButton);

	// Register the Layout on main window
	auto tmpWidget = new QWidget;
	tmpWidget->setLayout(layout);
	this->setCentralWidget(tmpWidget);


	// ######################## //	
	// TEMPORARY TEST			//
	// ######################## //	

	connect(
		this->testButton, &QPushButton::clicked,
		this, &MainWindow::openFileDialog
	);
	/*
	connect(
		this->scene, &ChartScene::mouseMoved,
		this, &MainWindow::changeLine
	);
*/

	// ######################## //	
	// END TEMPORARY TEST		//
	// ######################## //	


	// Set X-Axis Line Style
	auto pen = QPen(QColor("gray"));
	pen.setWidth(1);
	this->xAxis->setPen(pen);
	
}

// - Slots
void MainWindow::openFileDialog()
{
	auto fileName = QFileDialog::getOpenFileName(this, "Open", "./", "PNG Image(*.png)");
	openImage(fileName);
}

void MainWindow::openImage(const QString& pathStr)
{
	auto image = QImage(pathStr);
	auto pixImage = new QGraphicsPixmapItem(QPixmap::fromImage(image));
	this->scene->addItem(pixImage);


}

void MainWindow::changeLine(const QPointF& point)
{
	std::cout << "Update Point: " << point.x() << ", " << point.y() << std::endl;
	this->xAxis->setLine(10, 5, point.x(), point.y());
}
