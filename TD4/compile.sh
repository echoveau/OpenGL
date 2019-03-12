#!/bin/bash
gcc actions.c -c
gcc init.c -c
gcc VM_init.c -c
gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o opmat.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test
