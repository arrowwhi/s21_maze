#pragma once

#include <QColor>

#include "../helpers/helpers.h"

namespace s21 {

struct Def {
  constexpr static uint point_size = 6, path_size = 2, cell_size = 2;
  constexpr static double width = 500, height = 500;
  constexpr static Qt::GlobalColor point_color =
      Qt::red;  // start end points color
  constexpr static Qt::GlobalColor path_color = Qt::green;   // slove color
  constexpr static Qt::GlobalColor wall_color = Qt::black;   // cave walls color
  constexpr static Qt::GlobalColor cell_color = Qt::black;   // maze walls color
  constexpr static Qt::GlobalColor empty_color = Qt::white;  // cave air color
};

}  // namespace s21
