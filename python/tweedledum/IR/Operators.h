/*------------------------------------------------------------------------------
| Part of Tweedledum Project.  This file is distributed under the MIT License.
| See accompanying file /LICENSE for details.
*-----------------------------------------------------------------------------*/
#pragma once

#include <pybind11/pybind11.h>
#include <tweedledum/IR/Instruction.h>
#include <tweedledum/Operators/Reversible.h>
#include <tweedledum/Operators/Standard.h>

namespace tweedledum::python {

class PyOperator {
public:
    static constexpr std::string_view kind()
    {
        return "py_operator";
    }

    PyOperator(pybind11::object const& handle)
        : handle_(handle)
    {}

    pybind11::object obj() const
    {
        return handle_;
    }

private:
    pybind11::object handle_;
};

} // namespace tweedledum

void init_Operators(pybind11::module& module);