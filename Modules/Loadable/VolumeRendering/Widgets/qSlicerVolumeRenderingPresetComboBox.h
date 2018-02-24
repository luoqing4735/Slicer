/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through CANARIE�s Research Software Program, and Cancer
  Care Ontario.

==============================================================================*/

#ifndef __qSlicerVolumeRenderingPresetComboBox_h
#define __qSlicerVolumeRenderingPresetComboBox_h

// SlicerQt includes
#include "qSlicerWidget.h"
#include "qSlicerVolumeRenderingModuleWidgetsExport.h"

// qSlicerVolumeRendering includes
#include "qMRMLVolumePropertyNodeWidget.h"

class vtkMRMLNode;
class vtkMRMLScalarVolumeNode;
class qSlicerVolumeRenderingPresetComboBoxPrivate;

class Q_SLICER_MODULE_VOLUMERENDERING_WIDGETS_EXPORT qSlicerVolumeRenderingPresetComboBox
  : public qSlicerWidget
{
  Q_OBJECT

public:
  /// Constructors
  typedef qSlicerWidget Superclass;
  explicit qSlicerVolumeRenderingPresetComboBox(QWidget* parent=0);
  virtual ~qSlicerVolumeRenderingPresetComboBox();

  /// Get selected preset node in the combobox.
  /// Note: This node is not in the main MRML scene, but from the private presets scene
  Q_INVOKABLE vtkMRMLNode* currentNode()const;

  /// Get volume property node controlling volume rendering transfer functions.
  /// Its content mirrors the currently selected preset node in the combobox.
  Q_INVOKABLE vtkMRMLVolumePropertyNode* mrmlVolumePropertyNode()const;

public slots:
  /// Set selected preset node in the combobox. Triggers update of the volume property node
  void setCurrentNode(vtkMRMLNode* node);

  /// Set volume property node controlling volume rendering transfer functions.
  /// Its content mirrors the currently selected preset node in the combobox.
  void setMRMLVolumePropertyNode(vtkMRMLNode* node);

  void updatePresetSliderRange();
  void applyPreset(vtkMRMLNode* volumePropertyNode);

signals:
  void currentNodeChanged(vtkMRMLNode* node);
  void currentNodeIDChanged(const QString& id);

  /// Signal notifying about offset change.
  /// Handled by \sa qMRMLVolumePropertyNodeWidget or \sa ctkVTKVolumePropertyWidget by moving all control points.
  void presetOffsetChanged(double xOffset, double yOffset, bool dontMoveFirstAndLast);

protected slots:
  void startInteraction();
  void endInteraction();
  void interaction();

  void offsetPreset(double newPosition);
  void resetOffset();

protected:
  QScopedPointer<qSlicerVolumeRenderingPresetComboBoxPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerVolumeRenderingPresetComboBox);
  Q_DISABLE_COPY(qSlicerVolumeRenderingPresetComboBox);
};

#endif
