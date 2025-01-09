#!/bin/bash

xargs -I {} sed -i '1s/^/#include "aadc_types.hpp"\n/' {}
