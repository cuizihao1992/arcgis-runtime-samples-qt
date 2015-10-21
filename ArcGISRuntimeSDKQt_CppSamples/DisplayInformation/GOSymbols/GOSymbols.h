// Copyright 2015 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOSYMBOLS_H
#define GOSYMBOLS_H

namespace Esri {
namespace ArcGISRuntime {
  class Map;
  class MapView;
  class Viewpoint;
  class GraphicsOverlay;
  }
}

#include <Geometry.h>
#include <QWidget>

class GOSymbols : public QWidget
{
  Q_OBJECT

public:
  explicit GOSymbols(QWidget* parent = 0);
  ~GOSymbols();

private:
  void createUi();
  void addBuoyPoints(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  void addBoatTrip(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  void addNestingGround(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  void addText(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  Esri::ArcGISRuntime::Geometry createNestingGround();

private:
  Esri::ArcGISRuntime::Map* m_map;
  Esri::ArcGISRuntime::MapView* m_mapView;
};

#endif // GOSYMBOLS_H
