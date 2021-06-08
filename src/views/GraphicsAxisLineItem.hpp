#ifndef GRAPHICS_AXIS_LINE_ITEM_HPP
#define GRAPHICS_AXIS_LINE_ITEM_HPP

#include <QtWidgets>

class GraphicsAxisLineItem: public QGraphicsObject
{

	Q_OBJECT

private:
	// - TYPES
	enum class Grabbed { beginPoint, endPoint, none };

private:
	size_t markSize_ = 10;
	QPen pen_;
	QLineF line_;

	Grabbed grabbed_ = Grabbed::none;	


protected:
	// - Overrides Mouse Events
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent*) override;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;


signals:
	void beginPointClicked();
	void endPointClicked();
	
public:
	// - Constructors
	GraphicsAxisLineItem(
		qreal x1, qreal y1, 
		qreal x2, qreal y2, 
		QGraphicsItem *parent = nullptr
	);
	GraphicsAxisLineItem(const QLineF& line, QGraphicsItem *parent = nullptr);
	GraphicsAxisLineItem(QGraphicsItem *parent = nullptr);
	

	// - Public Member Functions
	QLineF line() const;
	QPen pen() const;

	void setLine(const QLineF&);
	void setLine(qreal x1, qreal y1, qreal x2, qreal y2);
	void setPen(const QPen&);

	
	// - Implementation of pure virtual functions
	QRectF boundingRect() const override;
	void paint(
		QPainter*, const QStyleOptionGraphicsItem*, 
		QWidget *widget = nullptr
	) override;

};

#endif
