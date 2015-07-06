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

#ifndef FL_EXTREMELY_H
#define FL_EXTREMELY_H

#include "fl/hedge/Hedge.h"

namespace fl {

    /**
     * Extremely is a hedge in the ordered set 
     * (Not, Seldom, Somewhat, Very, Extremely, Any)
     */
    class FL_API Extremely : public Hedge {
    public:
        std::string name() const;
        /**
         * Computes Extremely for a membership function value \f$x\f$
         * @param x is a membership function value
         * @return \f$
         * \cases{
         * 2x^2 & \mbox{if $x \le 0.5$} \cr
         * 1-2(1-x)^2 & \mbox{otherwise}\cr
         * }
         * \f$
         */
        scalar hedge(scalar x) const;
        Extremely* clone() const;

        /**
         * @return a new instance of Extremely
         */
        static Hedge* constructor();
    };

}
#endif /* FL_EXTREMELY_H */
