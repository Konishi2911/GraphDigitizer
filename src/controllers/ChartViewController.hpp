#ifndef CHART_VIEW_CONTROLLER_HPP
#define CHART_VIEW_CONTROLLER_HPP

class ChartViewController 
{
public:
	// - Types
	enum class EditingItem { X_AXIS, Y_AXIS, POINTS };

private:
	EditingItem nowEditing_;

public:
	// - Constructor
	ChartViewController();	

	// - Public Member Functions
	EditingItem editing() const;

	
};

#endif 
