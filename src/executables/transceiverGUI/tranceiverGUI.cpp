#include "transceiverGUI.hpp"

using namespace pylongps;

/**
This function initializes the class, connecting widgets, setting up the form generated by Qt designer and adding the components that the designer doesn't handle well.

@throw: This function can throw exceptions
*/
transceiverGUI::transceiverGUI()
{
setupUi(this);

//Set buttons to switch the pages in the GUI
connect(toggleGUIPagePushButtonP1, SIGNAL(clicked(bool)), this, SLOT(toggleGUIPage()));
connect(toggleGUIPagePushButtonP2, SIGNAL(clicked(bool)), this, SLOT(toggleGUIPage()));

//Add a scrolly map without any other features
Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget();
mapWidget->setProjection(Marble::Mercator);
mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
mapWidget->setShowOverviewMap(false);
mapWidget->setShowCompass(false);
mapWidget->setShowScaleBar(false);
mapWidget->setShowCrosshairs(false);
mapWidget->setShowGrid(false);
mapWidget->centerOn(0.0,0.0);

//Hide navigator tool
QList<Marble::AbstractFloatItem *> floatItems = mapWidget->floatItems();
for(int i=0; i<floatItems.size(); i++)
{
floatItems.at(i)->hide();
}


baseStationMapLayout->addWidget(mapWidget);

} 

/**
This function toggles which page is displayed in the GUI.  If the current index is 0, it makes it 1 and vice versa.
*/
void transceiverGUI::toggleGUIPage()
{
if(mainWindowStackedWidget->count() > 1)
{ //Toggle the index
mainWindowStackedWidget->setCurrentIndex(!mainWindowStackedWidget->currentIndex());
}
}