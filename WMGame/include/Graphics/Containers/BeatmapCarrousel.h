//
// Created by adrian on 29/04/25.
//

#ifndef BEATMAPCARROUSEL_H
#define BEATMAPCARROUSEL_H

#include "PULSO/Graphics/Containers/ScrollContainer.h"
#include "PULSO/Graphics/Shapes/Box.h"

class BeatmapCarrousel final : public ScrollContainer {
public:

    float distanceDecayScroll = 0.1f;
    BeatmapCarrousel();

};



#endif //BEATMAPCARROUSEL_H
