/**
 * \file VtkVisPointSetItem.h
 * 2011/09/29 KR Initial implementation
 *
 */

#ifndef VTKVISPOINTSETITEM_H
#define VTKVISPOINTSETITEM_H

// ** INCLUDES **
#include "VtkVisPipelineItem.h"

class vtkAlgorithm;
class vtkDataSetAttributes;
class vtkPointSet;
class vtkProp3D;
class vtkRenderer;
class vtkTransformFilter;
class QVtkDataSetMapper;

class vtkOsgActor;

class VtkAlgorithmProperties;
class VtkCompositeFilter;

/**
 * \brief An item in the VtkVisPipeline containing a point set object to be visualized.
 *
 * Any VTK point set object (i.e. vtkUnstructuredGrid- and vtkPolyDataAlgorithm-objects) 
 * are represented by a VtkVisPointSetItem to be assigned a mapper, an actor and its 
 * visualization properties (colour, scalar values, etc.).
 * \sa VtkVisPipelineItem
 */
class VtkVisPointSetItem : public VtkVisPipelineItem
{

public:
	/// @brief Constructor for a source/filter object.
	VtkVisPointSetItem(vtkAlgorithm* algorithm,
	                   TreeItem* parentItem,
	                   const QList<QVariant> data = QList<QVariant>());

	/// @brief Constructor for composite filter
	VtkVisPointSetItem(VtkCompositeFilter* compositeFilter, TreeItem* parentItem,
	                   const QList<QVariant> data = QList<QVariant>());

	~VtkVisPointSetItem();

	/// @brief Gets the last selected attribute.
	const QString GetActiveAttribute() const {return _activeAttribute; }

	/// @brief Initializes vtkMapper and vtkActor necessary for visualization of
	/// the item and sets the item's properties.
	void Initialize(vtkRenderer* renderer);

	vtkAlgorithm* transformFilter() const;

	/// @brief Sets the selected attribute array for the visualisation of the data set.
	void SetActiveAttribute(const QString& name);

	/// @brief Sets the scalar range for the selected data array
	void SetScalarRange(double min, double max);

	/// @brief Scales the data in visualisation-space.
	void setScale(double x, double y, double z) const;

	/// @brief Translates the item in visualisation-space.
	void setTranslation(double x, double y, double z) const;

	/// @brief Enables / disables backface culling.
	void setBackfaceCulling(bool enable) const;

protected:
	QVtkDataSetMapper* _mapper;
	vtkTransformFilter* _transformFilter;
	QString _activeAttribute;

	/// Selects the appropriate VTK-Writer object and writes the object to a file with the given name.
	virtual int callVTKWriter(vtkAlgorithm* algorithm, const std::string &filename) const;

	/// Sets a color lookup table for the current scalar array.
	void setLookupTableForActiveScalar();

	void SetScalarVisibility(bool on);

	/// @brief Sets pre-set properties on vtkActor and on vtkMapper
	void setVtkProperties(VtkAlgorithmProperties* vtkProps);

private:
	/// Checks if the selected attribute actually exists for the data set
	bool activeAttributeExists(vtkDataSetAttributes* data, std::string& name);

	/// @brief The active VtkAlgorithmProperties.
	/// From algorithm, compositeFilter, or copied from parent
	VtkAlgorithmProperties* _vtkProps;
};

#endif // VTKVISPOINTSETITEM_H

