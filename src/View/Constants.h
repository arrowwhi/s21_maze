#pragma once

#include "../Helpers/Helpers.h"

#include <QColor>

namespace s21 {

struct Def {
    constexpr static uint point_size = 6, path_size = 2;
    // constexpr static uint path_size = 2;
    constexpr static double width = 500, height = 500;
    constexpr static Qt::GlobalColor point_color = Qt::red;
    constexpr static Qt::GlobalColor path_color = Qt::green;
    constexpr static Qt::GlobalColor wall_color = Qt::black;
    constexpr static Qt::GlobalColor empty_color = Qt::white;
};

}  // namespace s21
