//
// Created by ChiroYuki on 14/04/2025.
//

#ifndef WMG_BEATMAPBUTTON_H
#define WMG_BEATMAPBUTTON_H

#include "PULSO/Graphics/Shapes/Box.h"
#include "PULSO/Graphics/Interactives/Button.h"

class BeatmapButton final : public Button {
public:
    BeatmapButton();

    void onPress() override;

    void onRelease() override;

    void onHoverEnter() override;

    void onHoverExit() override;

private:
    std::shared_ptr<Box> boxShape;

    Time animDuration;
};


#endif //WMG_BEATMAPBUTTON_H
