// [WriteFile Name=ProjectGeometry, Category=Geometry]
// [Legal]
// Copyright 2018 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

#ifndef PROJECTGEOMETRY_H
#define PROJECTGEOMETRY_H

namespace Esri
{
namespace ArcGISRuntime
{
class Map;
class MapQuickView;
class Graphic;
class CalloutData;
}
}

#include <QQuickItem>
#include <QMouseEvent>

class ProjectGeometry : public QQuickItem
{
  Q_OBJECT

public:
  explicit ProjectGeometry(QQuickItem* parent = nullptr);
  ~ProjectGeometry() = default;

  Q_PROPERTY(Esri::ArcGISRuntime::CalloutData* calloutData MEMBER m_calloutData NOTIFY calloutDataChanged)

  void componentComplete() Q_DECL_OVERRIDE;
  static void init();

signals:
  void calloutDataChanged();

private slots:
  void onMouseClicked(const QMouseEvent& event);

private:
  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
  Esri::ArcGISRuntime::Graphic* m_inputGraphic = nullptr;
  Esri::ArcGISRuntime::CalloutData* m_calloutData = nullptr;
};

#endif // PROJECTGEOMETRY_H
