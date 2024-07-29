# Matlogica AADC C++ to Python Integration

This repository showcases an **example** of the Matlogica automated conversion of arbitrary C++ code to AADC (Automated Adjoint Differentiation Compiler) enabled C++ code. It further demonstrates how to expose AAD-enabled C++ code to Python using pybind11.

## Overview

- **libQLcpp**: Contains examples of quantitative analytics. Notably, the `Market` class interface is not implemented in C++ and is intended to be implemented in Python, with instances usable in C++.
- **libQLcpp-aadc**: This directory is automatically generated and includes modifications such as changing native `double` types to active `idouble` types among other changes required to ensure compatibility with the C++ compiler.
- **libQLcpp-aadc-py**: Automatically generated directory containing pybind11 code that exposes all functions and classes to Python.

The `example.py` script utilizes the generated wheel for `libQLcpp`, implements the `Market` interface, calls pricing functions, and computes scenarios with associated risks.

## Usage

### Installation

Ensure you have Python 3 installed, and follow these steps to set up the environment:

1. Remove existing builds:
   ```bash
   rm -rf libQLcpp-aadc
   rm -rf libQLcpp-aadc-py
   ```

2. Generate AADC-enabled C++ code:
   ```bash
   python3 ConvScript.py
   ```

3. Build Python wheels for the AADC-enabled code:
   ```bash
   python3 BuildPythonWheels.py
   ```

4. Install the generated wheel:
   ```bash
   pip install libQLcpp-aadc-py/dist/libql-1.7.5.26-cp311-cp311-linux_x86_64.whl
   ```

### Running the Example

Execute the example script to see the integration in action:
```bash
python3 example.py
```
```
idouble(9.51e-01)
idouble(9.75e+01)
You are using evaluation version of AADC. Expire date is 20240901
Scenario prices:
[98.71079753 98.31651601 98.22082166 97.76763258 97.97724197 98.64659737
 97.51744094 97.91050362 98.31712918 98.04051725 97.9100717  97.48848971
 98.12427672 97.99621938 97.57909628 97.86058474 98.02081412 97.67201301
 97.96077635 97.87429167]
Scenario derivatives dP/dr:
[-49.35539876 -49.158258   -49.11041083 -48.88381629 -48.98862098
 -49.32329868 -48.75872047 -48.95525181 -49.15856459 -49.02025863
 -48.95503585 -48.74424486 -49.06213836 -48.99810969 -48.78954814
 -48.93029237 -49.01040706 -48.8360065  -48.98038817 -48.93714584]
```

## Additional Resources

For more information on using AADC with Python, visit the [Matlogica AADC Python GitHub repository](https://github.com/matlogica/AADC-Python).

