#include "ChartViewController.hpp"

// - Constructor
ChartViewController::ChartViewController():
	nowEditing_(EditingItem::X_AXIS)
{}

// - Public Member Functions

ChartViewController::EditingItem ChartViewController::editing() const
{
	return this->nowEditing_;
}
