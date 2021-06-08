#include "ChartScene.hpp"

#include <iostream>

void ChartScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	// Call default implementation
	QGraphicsScene::mousePressEvent(event);

	auto pos = event->scenePos();
	emit mouseClicked(pos);
}

void ChartScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	// Call default implementation
	QGraphicsScene::mouseMoveEvent(event);

	auto pos = event->scenePos();
	emit mouseMoved(pos);
}

void ChartScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	// Call default implementation
	QGraphicsScene::mouseReleaseEvent(event);

	auto pos = event->scenePos();
	emit mouseReleased(pos);
}
