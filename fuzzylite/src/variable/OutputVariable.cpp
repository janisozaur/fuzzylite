/*
 * OutputVariable.cpp
 *
 *  Created on: 2/12/2012
 *      Author: jcrada
 */

#include "fl/variable/OutputVariable.h"

#include "fl/term/Accumulated.h"
#include "fl/defuzzifier/Defuzzifier.h"

#include "fl/engine/Configuration.h"

#include <sstream>

namespace fl {

    OutputVariable::OutputVariable(const std::string& name, scalar defaultValue,
            bool lockDefuzzifiedValue)
            : Variable(name), _output(new Accumulated("output")), _defuzzifier(NULL),
              _defaultValue(defaultValue),
              _defuzzifiedValue(std::numeric_limits<scalar>::quiet_NaN()),
              _lockDefuzzifiedValue(lockDefuzzifiedValue),
              _minimum(-std::numeric_limits<scalar>::infinity()),
              _maximum(std::numeric_limits<scalar>::infinity()) {
    }

    OutputVariable::~OutputVariable() {
        delete _output;
    }

    void OutputVariable::configure(Configuration* config) {
        this->_defuzzifier = config->getDefuzzifier();
        this->_output->setAccumulation(config->getAccumulation());
    }

    Accumulated* OutputVariable::output() const {
        return this->_output;
    }

    void OutputVariable::setDefuzzifier(Defuzzifier* defuzzifier) {
        this->_defuzzifier = defuzzifier;
    }

    Defuzzifier* OutputVariable::getDefuzzifier() const {
        return this->_defuzzifier;
    }

    void OutputVariable::setDefaultValue(scalar defaultValue) {
        this->_defaultValue = defaultValue;
    }

    scalar OutputVariable::getDefaultValue() const {
        return this->_defaultValue;
    }

    void OutputVariable::setDefuzzifiedValue(scalar defuzzifiedValue) {
        this->_defuzzifiedValue = defuzzifiedValue;
    }

    scalar OutputVariable::getDefuzzifiedValue() const {
        return this->_defuzzifiedValue;
    }

    void OutputVariable::setLockDefuzzifiedValue(bool lock) {
        this->_lockDefuzzifiedValue = lock;
    }

    bool OutputVariable::lockDefuzzifiedValue() const {
        return this->_lockDefuzzifiedValue;
    }

    void OutputVariable::setMininum(scalar minimum){
        this->_minimum = minimum;
    }

    scalar OutputVariable::getMinimum() const{
        return this->_minimum;
    }

    void OutputVariable::setMaximum(scalar maximum){
        this->_maximum =maximum;
    }

    scalar OutputVariable::getMaximum() const{
        return this->_maximum;
    }

    scalar OutputVariable::defuzzify(bool overrideLock) {
        if (this->_output->isEmpty()) {
            //if a previous defuzzification was successfully performed and
            //and the output is supposed to not change when the output is empty
            if (_lockDefuzzifiedValue and not Op::IsNan(_defuzzifiedValue))
                return _defuzzifiedValue;
            return _defaultValue;
        }
        scalar result = this->_defuzzifier->defuzzify(this->_output);

        if (Op::IsLt(result, _minimum)) result = _minimum;
        if (Op::IsGt(result, _maximum)) result = _maximum;

        if (not overrideLock and _lockDefuzzifiedValue) _defuzzifiedValue = result;

        return result;
    }

} /* namespace fl */
