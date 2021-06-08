#ifndef CHART_SCENE_HPP
#define CHART_SCENE_HPP

#include "GraphicsAxisLineItem.hpp"
#include "ChartViewController.hpp"

#include <QtWidgets>

class ChartScene: public QGraphicsScene
{
	// This MACRO is required to identify the source code have to be precompiled by MOC.
	Q_OBJECT

private:
	GraphicsAxisLineItem *xAxis_;
	GraphicsAxisLineItem *yAxis_;
	QVector<QGraphicsEllipseItem> points_;

	

protected:
	// - Overriden Events
	void mousePressEvent(QGraphicsSceneMouseEvent*) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

public:
	// - Constructors
	using QGraphicsScene::QGraphicsScene;

signals:
	void mouseClicked(QPointF);
	void mouseMoved(QPointF);
	void mouseReleased(QPointF);
};

#endif 
