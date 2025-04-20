//
// Created by ChiroYuki on 12/04/2025.
//

#include "RS/Graphics/Containers/GridContainer.h"

GridContainer::GridContainer(int rows, int columns, float spacing)
        : rows(rows), columns(columns), spacing(spacing) {}

void GridContainer::setRows(int newRows) {
    rows = newRows;
    updateLayout();
}

void GridContainer::setColumns(int newColumns) {
    columns = newColumns;
    updateLayout();
}

void GridContainer::setSpacing(float newSpacing) {
    spacing = newSpacing;
    updateLayout();
}

void GridContainer::updateLayout() {
    Vector2 cursor = {0, 0};
    Vector2 containerSize = getSize();

    float totalWidth = 0.0f;
    float totalHeight = 0.0f;
    for (const auto& child : children) {
        Vector2 size = child->getSize();
        totalWidth = std::max(totalWidth, size.x);
        totalHeight = std::max(totalHeight, size.y);
    }

    int currentColumn = 0;
    int currentRow = 0;

    for (const auto& child : children) {
        Vector2 size = child->getSize();
        Vector2 pos = {0, 0};

        pos.x = static_cast<float>(currentColumn) * (totalWidth + spacing);
        pos.y = static_cast<float>(currentRow) * (totalHeight + spacing);

        child->setPosition(pos);

        currentColumn++;
        if (currentColumn >= columns) {
            currentColumn = 0;
            currentRow++;
            if (currentRow >= rows) {
                break;
            }
        }
    }
}