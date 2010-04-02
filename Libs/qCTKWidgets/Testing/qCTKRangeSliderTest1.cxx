/*=========================================================================

  Library:   qCTK

  Copyright (c) Kitware Inc. 
  All rights reserved.
  Distributed under a BSD License. See LICENSE.txt file.

  This software is distributed "AS IS" WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the above copyright notice for more information.

=========================================================================*/

// QT includes
#include <QApplication>
#include <QString>

// qCTK includes
#include "qCTKRangeSlider.h"

// STD includes
#include <stdlib.h>
#include <iostream>

bool checkSlider(const qCTKRangeSlider& slider)
{
  return slider.minimum()  <= slider.minimumValue() &&
    slider.minimumValue() <= slider.maximumValue() &&
    slider.maximumValue() <= slider.maximum();
}

bool checkSlider(const qCTKRangeSlider& slider, 
                 int min, int minVal, int maxVal, int max)
{
  return slider.minimum() == min &&
    slider.minimumValue() == minVal &&
    slider.maximumValue() == maxVal &&
    slider.maximum() == max;
}

int qCTKRangeSliderTest1(int argc, char * argv [] )
{
  QApplication app(argc, argv);

  qCTKRangeSlider slider;
  if (!checkSlider(slider))
    {
    std::cerr << "qCTKRangeSlider:: 1) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimum(40);
  slider.setMaximum(4000);
  slider.setValues(50, 500);
  if (!checkSlider(slider, 40, 50, 500, 4000))
    {
    std::cerr << "qCTKRangeSlider:: 2) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(700, 60);
  if (!checkSlider(slider, 40, 60, 700, 4000))
    {
    std::cerr << "qCTKRangeSlider:: 3) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(800, 900);
  if (!checkSlider(slider, 40, 800, 900, 4000))
    {
    std::cerr << "qCTKRangeSlider:: 4) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(5000, 6000);
  if (!checkSlider(slider, 40, 4000, 4000, 4000))
    {
    std::cerr << "qCTKRangeSlider:: 5) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setRange(-15, 40);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "qCTKRangeSlider:: 6) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  // nothing happen yet but it would be nice if it moves the 2 values at 
  // the same time.
  slider.triggerAction(QAbstractSlider::SliderSingleStepSub);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "qCTKRangeSlider:: 7) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMaximumValue(30);
  if (!checkSlider(slider, -15, 30, 30, 40))
    {
    std::cerr << "qCTKRangeSlider:: 8) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimumValue(40);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "qCTKRangeSlider:: 9) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimumValue(-20);
  if (!checkSlider(slider, -15, -15, 40, 40))
    {
    std::cerr << "qCTKRangeSlider:: 10) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  
  return EXIT_SUCCESS;
}

