#include "GraphicsAxisLineItem.hpp"

#include <iostream>

// - Constructors
GraphicsAxisLineItem::GraphicsAxisLineItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent): 
	QGraphicsObject(parent)
{
	this->setLine(x1, y1, x2, y2);
}

GraphicsAxisLineItem::GraphicsAxisLineItem(const QLineF& line, QGraphicsItem *parent): 
	QGraphicsObject(parent)
{
	this->setLine(line);
}

GraphicsAxisLineItem::GraphicsAxisLineItem(QGraphicsItem *parent): 
	QGraphicsObject(parent)
{
	
}


// - Public Member Functions
QLineF GraphicsAxisLineItem::line() const 
{
	return this->line_;
}

QPen GraphicsAxisLineItem::pen() const
{
	return this->pen_;
}

void GraphicsAxisLineItem::setLine(const QLineF& line)
{
	this->line_ = line;
	this->prepareGeometryChange();
	this->update();
}

void GraphicsAxisLineItem::setLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
	this->line_ = QLineF(x1, y1, x2, y2);
	this->prepareGeometryChange();
	this->update();
}

void GraphicsAxisLineItem::setPen(const QPen& pen)
{
	this->pen_ = pen;
}

// - Implementation of pure virtual functions
QRectF GraphicsAxisLineItem::boundingRect() const
{
	qreal lx = qMin(this->line_.x1(), this->line_.x2());
	qreal rx = qMax(this->line_.x1(), this->line_.x2());
	qreal ty = qMin(this->line_.y1(), this->line_.y2());
	qreal by = qMax(this->line_.y1(), this->line_.y2());
	//this->shape().controlPointRect();
	return QRectF(
		lx - 0.5 * this->markSize_, 
		ty - 0.5 * this->markSize_, 
		(rx - lx) + this->markSize_, 
		(by - ty) + this->markSize_
	);
}

void GraphicsAxisLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	auto sRect = QRect(
		this->line_.x1() - 0.5 * this->markSize_, 
		this->line_.y1() - 0.5 * this->markSize_,
		this->markSize_, this->markSize_
	);
	auto eRect = QRect(
		this->line_.x2() - 0.5 * this->markSize_, 
		this->line_.y2() - 0.5 * this->markSize_,
		this->markSize_, this->markSize_
	);
	painter->setPen(this->pen_);
	painter->setRenderHints( painter->renderHints() | QPainter::Antialiasing );
	painter->drawLine(this->line_);
	painter->drawEllipse(sRect);
	painter->drawEllipse(eRect);
}


// - Overrides Mouse Events
void GraphicsAxisLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent* e)
{
	// Call default implementation
	QGraphicsObject::mouseMoveEvent(e);

	auto pos = e->scenePos();
	if (this->grabbed_ == Grabbed::beginPoint) {
		this->setLine(
			pos.x(), pos.y(),
			this->line_.x2(), this->line_.y2()
		);
	} else if (this->grabbed_ == Grabbed::endPoint) {
		this->setLine(
			this->line_.x1(), this->line_.y1(),
			pos.x(), pos.y()
		);
	} else {

	}
	this->update();
}

void GraphicsAxisLineItem::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
	auto pos = e->scenePos();
	auto r1 = pos - this->line().p1();
	auto r2 = pos - this->line().p2();

	auto d1 = QPointF::dotProduct(r1, r1);
	auto d2 = QPointF::dotProduct(r2, r2);
	auto th = 0.25 * std::pow(this->markSize_, 2);

	if (d1 < th) {
		std::cout << "bPoint clicked" << std::endl;
		this->grabbed_ = Grabbed::beginPoint;
		emit beginPointClicked();
	} else if (d2 < th) {
		std::cout << "ePoint clicked" << std::endl;
		this->grabbed_ = Grabbed::endPoint;
		emit endPointClicked();
	} else {
		
	}
}

void GraphicsAxisLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{
	// Call default implementation
	QGraphicsObject::mouseReleaseEvent(e);

	this->grabbed_ = Grabbed::none;
}
