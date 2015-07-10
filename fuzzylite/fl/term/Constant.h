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

#ifndef FL_CONSTANT_H
#define FL_CONSTANT_H

#include "fl/term/Term.h"

namespace fl {

    /**
     * %Term for a constant value
     * @author Juan Rada-Vilela, Ph.D.
     * @see Term
     * @see Variable
     * @since 4.0
     */
    class FL_API Constant : public Term {
    protected:
        scalar _value;

    public:
        explicit Constant(const std::string& name = "",
                scalar value = fl::nan);
        virtual ~Constant() FL_IOVERRIDE;
        FL_DEFAULT_COPY_AND_MOVE(Constant)

        virtual std::string className() const FL_IOVERRIDE;
        /**
         * Provides the parameters of the term as `value`
         * @return `value`
         */
        virtual std::string parameters() const FL_IOVERRIDE;
        /**
         * Configures the term with the parameters given as `value`
         * @param parameters as `value`
         */
        virtual void configure(const std::string& parameters) FL_IOVERRIDE;
        /**
         * Gets the constant value
         * @param x is irrelevant
         * @return @f$c@f$, where @f$c@f$ is the constant value
         */
        virtual scalar membership(scalar x) const FL_IOVERRIDE;

        /**
         * Sets the constant value
         * @param value is the constant value
         */
        virtual void setValue(scalar value);
        /**
         * Gets the constant value
         * @return the constant value
         */
        virtual scalar getValue() const;

        virtual Constant* clone() const FL_IOVERRIDE;

        static Term* constructor();
    };
}

#endif  /* FL_CONSTANT_H */
