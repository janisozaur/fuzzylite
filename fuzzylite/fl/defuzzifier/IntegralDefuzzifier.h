/*
 Copyright © 2010-2015 by FuzzyLite Limited.
 All rights reserved.

 This file is part of fuzzylite®.

 fuzzylite® is free software: you can redistribute it and/or modify it under
 the terms of the FuzzyLite License included with the software.

 You should have received a copy of the FuzzyLite License along with 
 fuzzylite®. If not, see <http://www.fuzzylite.com/license/>.

 fuzzylite® is a registered trademark of FuzzyLite Limited.
 */

#ifndef FL_INTEGRALDEFUZZIFIER_H
#define FL_INTEGRALDEFUZZIFIER_H

#include "fl/defuzzifier/Defuzzifier.h"

namespace fl {

    /**
    
      The IntegralDefuzzifier is the base class for defuzzifiers which integrate
      over the fuzzy set. 
    
      @author Juan Rada-Vilela, Ph.D.
      @since 4.0
      @todo check  http://en.wikipedia.org/wiki/Adaptive_quadrature
    
     */
    class FL_API IntegralDefuzzifier : public Defuzzifier {
    protected:
        static int _defaultResolution;

        int _resolution;
    public:

        /**
          Sets the default resolution for integral-based defuzzifiers
          @param defaultResolution is the default resolution for integral-based defuzzifiers
         */
        static void setDefaultResolution(int defaultResolution);
        /**
          Gets the default resolution for integral-based defuzzifiers
          @return the default resolution for integral-based defuzzifiers
         */
        static int defaultResolution();

        explicit IntegralDefuzzifier(int resolution = defaultResolution());
        virtual ~IntegralDefuzzifier() FL_IOVERRIDE;
        FL_DEFAULT_COPY_AND_MOVE(IntegralDefuzzifier)

        /**
          Sets the resolution of the defuzzifier. The resolution refers to the
          number of divisions in which the range `[minimum,maximum]` is divided
          in order to integrate the area under the curve

          @param resolution is the resolution of the defuzzifier
         */
        virtual void setResolution(int resolution);
        /**
          Gets the resolution of the defuzzifier. The resolution refers to the
          number of divisions in which the range `[minimum,maximum]` is divided
          in order to integrate the area under the curve

          @return the resolution of the defuzzifier
         */
        virtual int getResolution() const;
    };
}

#endif  /* INTEGRALDEFUZZIFIER_H */
