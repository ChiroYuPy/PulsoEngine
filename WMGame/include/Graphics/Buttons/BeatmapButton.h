//
// Created by ChiroYuki on 14/04/2025.
//

#ifndef WMG_BEATMAPBUTTON_H
#define WMG_BEATMAPBUTTON_H

#include "PULSO/Graphics/Shapes/Box.h"
#include "PULSO/Graphics/Interactives/Button.h"

class BeatmapButton final : public Button {
public:
    BeatmapButton(Color color);

    void onPress() override;

    void onRelease() override;

    void onHoverEnter() override;

    void onHoverExit() override;

private:
    std::shared_ptr<Box> boxShape;

    Time animDuration;

    Color hoverColor;
};


#endif //WMG_BEATMAPBUTTON_H
