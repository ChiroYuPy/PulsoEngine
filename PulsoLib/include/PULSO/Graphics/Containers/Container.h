//
// Created by ChiroYuki on 08/04/2025.
//

#ifndef WMG_CONTAINER_H
#define WMG_CONTAINER_H


#include "CompositeDrawable.h"

class Container : public CompositeDrawable {
public:
    Container();

    void onUpdate(Time update) override;

    virtual void updateLayout();
};

//TODO Drawable
//  └── CompositeDrawable
//        └── Container
//              ├── FlowContainer               arranger les éléments sur une ligne/colone en ajustant leurs dimensions
//              ├── FillFlowContainer           arranger les éléments sur plusieurs lignes si leurs dimensions dépassent celle du conteneur
//              ├── OverlayContainer            afficher un overlay sans focus ni visibilité ( tooltip, info )
//              ├── FocusedOverlayContainer     afficher un overlay qui prend le focus des évènements et permet un hide/show ( chatbox, pause, settings )
//              ├── ScrollContainer             permet de scroller en x et/ou en y en fonction de la place que prend ses enfants par rapport a sa taille ( contient souvent un FillFlowCOntainer )
//              └── SearchContainer

#endif //WMG_CONTAINER_H
