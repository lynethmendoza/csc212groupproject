# CSC 212 Term Project: Group 5 – Recursive Graphics
Our project uses recursion to create different fractals: Sierpinski Triangle, Hilbert Curve, and Koch Snowflake.

## Compiling and Running
Since we are using L-Systems, it is important to use the L-System Plotter Python code in this repo. 
Make sure that all files are in the same directory for this to work.
You have to download matplotlib onto your computer since the L-System code uses that library.

### For Each Fractal C++ File:

You'll need to run and compile the C++ first before you plot whichever fractal you may like. 
To do this, you should run the following cpp files with this:

``g++ [chosenfractal].cpp  && ./a.out [filename].txt [degree/order of fractal]``

### For the L-System Plotter Python File:

The Python file should take in your command file name (that was edited in the C++ file), the name for your PNG file, and the degree for turns:

``python3 "l-system-plotter.py" "[filename].txt" "[outputname].png" [degree]``

## Specifics for Each Fractal
Hilbert Curve Code:
-Degrees: 90

Sierpinski Snowkflake:
-Degrees: 60

Sierpinski Triangle:
-Degrees: 120
